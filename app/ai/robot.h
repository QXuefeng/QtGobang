#ifndef ROBOT_H
#define ROBOT_H

#include "global.h"
#include "board/board.h"

#include <QDebug>
#include <QThread>

// 计算落子位置的机器人
// 继承线程防止计算时间长导致界面卡死
class Robot : public QThread
{
    Q_OBJECT
public:
    explicit Robot(const Board& board, QObject* parent = nullptr) : QThread(parent),
        _board(board)
    {}

protected:
    void run()
    {
        // 保存局面最大分和点
        quint32 score     = 0;
        index_t index     = 0;

        // 获取对方棋子颜色和本方棋子颜色
        COLOR   mySide    = COLOR::WHT;
        COLOR   otherSide = COLOR::BLK;
        chess_t chess     = _board.at(_board.lastIndex());
        if(chess != NC) {
            otherSide = colorType(chess);
            mySide    = next(otherSide);
        }

        // 遍历所有点, 寻找局面分最大的点
        bool emptyBoard = true;
        for(size_t i = 0; i < MAXSIZE; ++ i) {
            // 此点可以落子
            if(_board.at(index_t(i)) == NC) {
                quint32 result = 0;
                result += calculatingScore(index_t(i), mySide);
                result += calculatingScore(index_t(i), otherSide) * 0.8;
                if(result > score) { score = result; index = index_t(i); }
            }
            // 不是空棋盘
            else emptyBoard = false;
        }

        // AI先走的情况, 强制天元
        if(emptyBoard) emit robotClickBoard(112);
        emit robotClickBoard(index);
    }

private:
    Board _board;

    // 计算落子点的分数
    qint32 calculatingScore(index_t index, COLOR color)
    {
        qint32  score = 0;
        qint32  rn = row(index), cn = column(index);    // 索引的行,列号
        index_t B_1, B_2;     // 索引的取值边界, [B_1, B_2]

        // 水平方向计算
        B_1 = rn * MAXCOL;
        B_2 = (rn + 1) * MAXCOL - 1;
        score += localCalculation(index, ROWOFFSET, color, B_1, B_2);

        // 垂直方向
        B_1 = cn;
        B_2 = (MAXROW - 1) * MAXCOL + cn;
        score += localCalculation(index, COLOFFSET, color, B_1, B_2);

        // 反斜边方向
        qint32 t1 = qMin(rn, cn);
        qint32 t2 = qMin(MAXROW - rn, MAXCOL - cn);
        B_1 = (rn - t1) * MAXCOL + cn - t1;
        B_2 = (rn + t2) * MAXCOL + cn + t2;
        score += localCalculation(index, REVOFFSET, color, B_1, B_2);

        // 正斜边方向
        qint32 t3 = qMin(rn, qint32(MAXCOL - cn));
        qint32 t4 = qMin(qint32(MAXROW - rn), cn);
        B_1 = (rn - t3) * MAXCOL + cn + t3;
        B_2 = (rn + t4) * MAXCOL + cn - t4;
        score += localCalculation(index, FWDOFFSET, color, B_1, B_2);

        return score;
    }

    // 计算一个方向上的分数
    qint32 localCalculation(index_t index, qint32 offset, COLOR color, index_t LB, index_t RB)
    {
        qint32* status =  _board.aroundStatus(index, offset, color, LB, RB);
        qint32 continuous = status[0], lb = status[1], rb = status[2];
        delete[] status;

        // 左右是否还能落子
        bool   lActive    = (lb != LB && colorType(_board.at(lb - offset)) == COLOR::NCR);
        bool   rActive    = (rb != RB && colorType(_board.at(rb + offset)) == COLOR::NCR);

        if(continuous >= 5)      return 10000;  // 五子成线 +10000
        if(!lActive && !rActive) return 0;      // 死棋

        if(continuous == 4) {
            if(lActive && rActive)  return 10000; // 活4
            else return 200;  // 半活4
        }
        else if(continuous == 3) {
            if(lActive && rActive)  return 2000; // 活3
            else return 100;  // 半活3
        }
        else if(continuous == 2) {
            if(lActive && rActive)  return 150; // 活2
            else return 100;  // 半活2
        }
        else {
            if(lActive && rActive)  return 20; // 活1
            else return 10;   // 半活1
        }
    }

signals:
    void robotClickBoard(index_t);
};

#endif // ROBOT_H
