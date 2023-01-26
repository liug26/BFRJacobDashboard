#include <QGuiApplication>
#include <QQmlApplicationEngine>
//#include <WS2812Lib/ws2812-rpi.h>
#include "src/code/canhandler.h"

struct package_manager {
    static constexpr auto package_name = "com.cobular.CanHandler";
    static constexpr auto package_version_major = 1;
    static constexpr auto package_version_minor = 0;
};

int main(int argc, char *argv[])
{
//    auto test = new QT_WS2812();
//    delete test;
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    qmlRegisterType<CanHandler>(package_manager::package_name,
        package_manager::package_version_major,
        package_manager::package_version_minor, "CanHandler");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
