#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>
#include "viewmodel.h"
#include "Shapes.h"
#include "Shapegenerator.h"
#include "DataSender.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

//    const QUrl url(u"qrc:/Game/Main.qml"_qs);
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
//  &app, []() { QCoreApplication::exit(-1); },
//      Qt::QueuedConnection);

    Shapegenerator* mainshape = new Shapegenerator();
    std::shared_ptr<Shapes> helix = std::make_shared<Shapes>(mainshape);

    QTcpSocket* socket = new QTcpSocket();
    DataSender* sender = new DataSender (socket,helix);
    QThread thread;
    sender->moveToThread(&thread);
    socket->moveToThread(&thread);
    thread.start();

    QMetaObject::invokeMethod(sender, "connect");
    viewmodel* v= new viewmodel(helix,sender);

    engine.rootContext()->setContextProperty("mainviewmodel", v);
    qmlRegisterUncreatableType<viewmodel>("Viewmodels", 1 , 0 , "Viewmodel" , "error .... form qml register of viewmodels");

    engine.rootContext()->setContextProperty("Shapgenratorcontext", mainshape);
    qmlRegisterUncreatableType<Shapegenerator>("Shapegenerators", 1 , 0 , "Shapegenerator" , "error .... form qml register of Shapegenerators");

    engine.load(u"qrc:/Game/Main.qml"_qs);

    return app.exec();
}
