#include "application.h"

#include <QIcon>
#include <QGuiApplication>


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // 设置应用图标
    QGuiApplication::setWindowIcon(QIcon("icon.png"));

    // 创建本程序的应用类
    Application application;
    application.show();

    return app.exec();
}
