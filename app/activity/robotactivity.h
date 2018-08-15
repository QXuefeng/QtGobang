#ifndef ROBOTACTIVITY_H
#define ROBOTACTIVITY_H

#include "ai/robot.h"
#include "activity.h"

// 人机对战类
class RobotActivity : public Activity
{
    Q_OBJECT
public:
    explicit RobotActivity(bool robotFirst = false, QObject* parent = nullptr) : Activity(parent)
    {
        _robot      = nullptr;
        _robotFirst = robotFirst;

        if(_robotFirst) clickEvent(112);
    }

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

        qint32 count = _board.count();
        if((_robotFirst && count%2 == 0) || (!_robotFirst && count%2 == 1)) {
            // Ai计算落子
            if(_robot) { delete _robot; _robot = nullptr; }
            _robot = new Robot(_board);
            QObject::connect(_robot, SIGNAL(robotClickBoard(index_t)), this, SLOT(onRobotClickBoard(index_t)));
            _robot->start();
        }
        Activity::clickEvent(index);
    }

    // 实现本地两人对战的悔棋功能
    virtual void rollbackEvent(qint32 n)
    {
        qint32 count = _board.count();
        if((_robotFirst && count%2 == 0) || (!_robotFirst && count%2 == 1)) return;


        // 回到玩家落子的那步
        index_t next = _board.lastIndex();
        _board.rollback();
        index_t prev = _board.lastIndex();
        emit rollbackFinish(next, prev);

        next = prev;
        _board.rollback();
        prev = _board.lastIndex();
        emit rollbackFinish(next, prev);

        Activity::rollbackEvent(n);
    }

private:
    Board  _board;       // 棋盘
    bool   _robotFirst;  // 机器人先走
    Robot* _robot;       // 计算落子位置

private slots:
    void onRobotClickBoard(index_t index)
    {
        clickEvent(index);
    }
};


#endif // ROBOTACTIVITY_H
