/**
 * @author: 江涛 (878490964@qq.com)
 * @date:   2018.07.19
 */
#ifndef ACTIVITY_H
#define ACTIVITY_H

#include "board/board.h"

#include <QObject>

// 所有模式的基类
class Activity : public QObject
{
    Q_OBJECT
public:
    explicit Activity(QObject* parent = nullptr) : QObject(parent) {}

protected:
    // 处理Ui界面的点击事件
    virtual void clickEvent(index_t index) { Q_UNUSED(index); }
    // 悔棋事件
    virtual void rollbackEvent(qint32 n)   { Q_UNUSED(n); }

signals:
    // 点击完成
    void clickFinish(index_t, COLOR, index_t);
    // 悔棋完成
    void rollbackFinish(index_t, index_t);
    // 胜利
    void victory(COLOR);

public slots:
    // 处理悔棋的逻辑事件
    void rollback(qint32 n) { Q_UNUSED(n); rollbackEvent(1); }

    // 处理棋盘的逻辑事件
    void clickBoard(qint32 index) { clickEvent((index_t) index); }
};


#endif // ACTIVITY_H
