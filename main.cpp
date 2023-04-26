#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "viewmodel.h"
#include<QQmlContext>
#include "Shapegenrator.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
//    const QUrl url(u"qrc:/Game/Main.qml"_qs);
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
//        &app, []() { QCoreApplication::exit(-1); },
//        Qt::QueuedConnection);
    viewmodel v;
    Shapegenrator s;
    engine.rootContext()->setContextProperty("mainviewmodel", &v);
    qmlRegisterUncreatableType<viewmodel>("Viewmodels", 1 , 0 , "Viewmodel" , "error .... form qml register of viewmodels");


    qRegisterMetaType<QMap<int,int>>("QMap<int,int>");
    engine.rootContext()->setContextProperty("shapegenratorcontext", &s);
    qmlRegisterUncreatableType<Shapegenrator>("Shapegenrators", 1 , 0 , "Shapegenrator" , "error .... form qml register of Shapegenrators");



    engine.load(u"qrc:/Game/Main.qml"_qs);


    return app.exec();
}
