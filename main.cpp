#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "viewmodel.h"
#include<QQmlContext>
#include "Shapes.h"
#include"Shapegenerator.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
//    const QUrl url(u"qrc:/Game/Main.qml"_qs);
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
//        &app, []() { QCoreApplication::exit(-1); },
//        Qt::QueuedConnection);

    Shapegenerator* mainshape = new Shapegenerator();
    Shapes* helix = new Shapes(mainshape);
    viewmodel v(helix);

    engine.rootContext()->setContextProperty("mainviewmodel", &v);
    qmlRegisterUncreatableType<viewmodel>("Viewmodels", 1 , 0 , "Viewmodel" , "error .... form qml register of viewmodels");

    engine.rootContext()->setContextProperty("Shapgenratorcontext", mainshape);
    qmlRegisterUncreatableType<Shapegenerator>("Shapegenerators", 1 , 0 , "Shapegenerator" , "error .... form qml register of Shapegenerators");




    engine.load(u"qrc:/Game/Main.qml"_qs);


    return app.exec();
}
