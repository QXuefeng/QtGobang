/**
 * @author: 江涛 (878490964@qq.com)
 * @date:   2018.07.18
 */
#ifndef APPLICATION_H
#define APPLICATION_H

#include "activity/activityfactory.h"

#include <QDebug>
#include <QObject>
#include <QVariant>
#include <QQuickItem>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQmlApplicationEngine>

class Application : QObject
{
    Q_OBJECT
public:
    explicit Application(QObject* parent = nullptr) : QObject(parent)
    {
        qRegisterMetaType<COLOR>("COLOR");
        qRegisterMetaType<index_t>("index_t");

        model     = MODEL::PVP;
        lock      = false;
        startting = false;
    }

    void show()
    {
        QQmlComponent component(&engine, QUrl(QLatin1String("qrc:/qml/main.qml")));
        view = component.create();
        if(view) {
            QObject::connect(view, SIGNAL(start()), this, SLOT(onStart()), Qt::QueuedConnection);
            QObject::connect(view, SIGNAL(choiceModel(qint32)), this, SLOT(onChoiceModel(qint32)), Qt::QueuedConnection);

            QMetaObject::invokeMethod(view, "pushMessages", Qt::QueuedConnection, Q_ARG(QVariant, QVariant(0)), Q_ARG(QVariant, QVariant(QString("欢迎使用本简陋的五子棋软件(*^__^*), 本软件本地双人, 机器对决和网络对战功能。本着交流学习的目的欢迎大家借鉴与修改，但不要用于学术作弊等地方，否则后果自负(^_^)∠※。作者邮箱：878490964@qq.com。"))));
        }
    }

private slots:
    void onStart()
    {
        startting = false;

        activity = QSharedPointer<Activity>(ActivityFactory::createActivity(model));
        if(activity != nullptr) {
            QObject::connect(activity.data(), SIGNAL(clickFinish(index_t, COLOR, index_t)), this, SLOT(onClickFinish(index_t, COLOR, index_t)));
            QObject::connect(activity.data(), SIGNAL(rollbackFinish(index_t, index_t)), this, SLOT(onRollbackFinish(index_t, index_t)));
            QObject::connect(activity.data(), SIGNAL(victory(COLOR)), this, SLOT(onVictory(COLOR)));

            QObject::connect(view, SIGNAL(rollback(qint32)), activity.data(), SLOT(rollback(qint32)), Qt::QueuedConnection);
            QObject::connect(view, SIGNAL(mouseClickEvent(qint32)), activity.data(), SLOT(clickBoard(qint32)), Qt::QueuedConnection);

            startting = true;
            QMetaObject::invokeMethod(view, "pushMessages", Qt::QueuedConnection, Q_ARG(QVariant, QVariant(0)), Q_ARG(QVariant, QVariant(QString("游戏开始"))));
        }
    }

    // 更新视图
    void onClickFinish(index_t next, COLOR color, index_t prev)
    {
        if(startting) QMetaObject::invokeMethod( view, "clickBoard", Qt::DirectConnection, Q_ARG(QVariant, QVariant(next)), Q_ARG(QVariant, QVariant(color)), Q_ARG(QVariant, QVariant(prev)));
        lock = false;
    }

    // 更新视图
    void onRollbackFinish(index_t next, index_t prev)
    {
        if(startting) {
            QMetaObject::invokeMethod(view, "rollbackBoard", Qt::DirectConnection, Q_ARG(QVariant, QVariant(next)), Q_ARG(QVariant, QVariant(prev)));
            QMetaObject::invokeMethod(view, "pushMessages", Qt::QueuedConnection, Q_ARG(QVariant, QVariant(0)), Q_ARG(QVariant, QVariant(QString("悔一步完成"))));
        }
    }

    void onVictory(COLOR color)
    {
        if(startting) {
            lock        = false;
            startting   = false;
            QString msg = "%1方胜利, 游戏结束";
            if(color == COLOR::WHT) msg = msg.arg("白");
            else if(color == COLOR::BLK) msg = msg.arg("黑");
            QMetaObject::invokeMethod(view, "pushMessages", Qt::QueuedConnection, Q_ARG(QVariant, QVariant(0)), Q_ARG(QVariant, QVariant(QString(msg))));
        }
    }

    // 改变模式
    void onChoiceModel(qint32 model)
    {
        this->model = (MODEL)model;
    }

private:
    QQmlApplicationEngine engine;
    QObject* view;

    QSharedPointer<Activity> activity;

    MODEL model;       // 游戏模式

    bool startting;
    bool lock;          // 点击锁, 防止重复点击
};

#endif // APPLICATION_H
