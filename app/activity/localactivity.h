/**
 * @author: 江涛 (878490964@qq.com)
 * @date:   2018.07.19
 */
#ifndef LOCALACTIVITY_H
#define LOCALACTIVITY_H

#include "activity.h"

// 本地双人对战的活动类
class LocalActivity : public Activity
{
    Q_OBJECT
public:
    explicit LocalActivity(QObject* parent = nullptr) : Activity(parent) {}

protected:
    // 落子的处理
    virtual void clickEvent(index_t index)
    {
        chess_t chess = NC;
        COLOR   color = COLOR::WHT;
        // 获取落子方的颜色
        if(_board.lastIndex() != NO_INDEX) {
            color = next(colorType(_board.at(_board.lastIndex())));
        }

        // 构造出棋子
        if(checkIndex(index) && _board.at(index) == NC) {
            quint8 count = _board.count(color);
            chess        = (++ count) | color;

            emit clickFinish(index, colorType(chess), _board.lastIndex());
            _board.put(index, chess);

            // 胜利结束
            if(_board.isVictory()) {
                emit victory(color);
                return;
            }
        }

        Activity::clickEvent(index);
    }

    // 实现本地两人对战的悔棋功能
    virtual void rollbackEvent(qint32 n)
    {
        // 获取悔棋位置和上上次落子的位置
        index_t next = _board.lastIndex();
        _board.rollback();
        index_t prev = _board.lastIndex();
        emit rollbackFinish(next, prev);

        Activity::rollbackEvent(n);
    }

private:
    Board _board;   // 棋盘
};

#endif // LOCALACTIVITY_H
