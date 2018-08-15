/**
 * @author: 江涛 (878490964@qq.com)
 * @date:   2018.07.19
 */
#ifndef BOARD_H
#define BOARD_H

#include "global.h"

#include <QDebug>
#include <QStack>
#include <cstring>
#include <QVariant>

// 棋盘类
class Board
{
public:
    Board()
    {
        // 初始化
        memset(_chesses, 0, sizeof(chess_t) * MAXSIZE);
        _cWhite    = 0;
        _cBlack    = 0;
    }

    Board(const Board& board)
    {
        // 深度拷贝
        memcpy_s(_chesses, MAXSIZE * sizeof(chess_t), board._chesses, MAXSIZE * sizeof(chess_t));
        _cWhite    = board._cWhite;
        _cBlack    = board._cBlack;
        _lastIndex = board._lastIndex;
    }

    // 设置指定棋盘索引处的棋子值
    void put(index_t index, chess_t chess)
    {
        COLOR color = colorType(chess);
        // 是否可以落子
        if(checkIndex(index) && color != COLOR::NCR && at(index) == NC) {
            _chesses[index] = chess;
            color == COLOR::WHT ? ++ _cWhite : ++ _cBlack;
            _lastIndex.push_back(index);
        }
    }

    // 回退一步
    bool rollback()
    {
        index_t index = lastIndex();
        chess_t chess = NC;
        if(index != NO_INDEX) {
            chess           = at(index);
            _chesses[index] = NC;
            _lastIndex.pop_back();
            if(colorType(chess) == COLOR::WHT) -- _cWhite;
            else if(colorType(chess) == COLOR::BLK) -- _cBlack;
            return true;
        }
        return false;
    }

    // 获取棋盘索引位置的棋子
    chess_t at(index_t index) const
    {
        if(checkIndex(index) && _chesses[index]) return _chesses[index];
        return NC;
    }

    // 获取最后一次下棋位置索引
    inline index_t lastIndex() const
    {
        return _lastIndex.empty() ? NO_INDEX : _lastIndex.top();
    }

    // 获取棋盘上棋子的数量
    inline quint8 count() const { return _cWhite + _cBlack; }

    // 获取特定颜色的棋子数量
    quint8 count(COLOR color) const
    {
        if(color == COLOR::WHT)      return _cWhite;
        else if(color == COLOR::BLK) return _cBlack;
        else if(color == COLOR::NCR) return MAXSIZE - count();

        return 0;
    }

    // 是否是胜利局面
    bool isVictory() const
    {
        // 索引的取值边界, [B_1, B_2]
        index_t index = lastIndex(), B_1, B_2;
        chess_t chess = at(index);
        // 索引的行, 列号, 和连续棋子的最大值
        qint32  rn = row(index), cn = column(index), continuous = 0;
        COLOR   color = colorType(chess);
        qint32* status = nullptr;

        // 水平方向计算
        B_1 = rn * MAXCOL;
        B_2 = (rn + 1) * MAXCOL - 1;
        status = aroundStatus(index, ROWOFFSET, color, B_1, B_2);
        continuous = qMax(continuous, status[0]);
        delete[] status;

        // 垂直方向
        B_1 = cn;
        B_2 = (MAXROW - 1) * MAXCOL + cn;
        status = aroundStatus(index, COLOFFSET, color, B_1, B_2);
        continuous = qMax(continuous, status[0]);
        delete[] status;

        // 反斜边方向
        qint32 t1 = qMin(rn, cn);
        qint32 t2 = qMin(MAXROW - rn, MAXCOL - cn);
        B_1 = (rn - t1) * MAXCOL + cn - t1;
        B_2 = (rn + t2) * MAXCOL + cn + t2;
        status = aroundStatus(index, REVOFFSET, color, B_1, B_2);
        continuous = qMax(continuous, status[0]);
        delete[] status;

        // 正斜边方向
        qint32 t3 = qMin(rn, qint32(MAXCOL - cn));
        qint32 t4 = qMin(qint32(MAXROW - rn), cn);
        B_1 = (rn - t3) * MAXCOL + cn + t3;
        B_2 = (rn + t4) * MAXCOL + cn - t4;
        status = aroundStatus(index, FWDOFFSET, color, B_1, B_2);
        continuous = qMax(continuous, status[0]);
        delete[] status;

        return continuous >= 5;
    }

    // 点某一方向连续棋子的数量， 边界
    qint32* aroundStatus(index_t index, qint32 offset, COLOR color, index_t LB, index_t RB) const
    {
        qint32* status = new qint32[3] {0};

        index_t lb = index, rb = index;     // 左右边界
        while(lb - offset >= LB && colorType(at(lb - offset)) == color) lb -= offset;
        while(rb + offset <= RB && colorType(at(rb + offset)) == color) rb += offset;

        status[0] = (rb - lb) / offset + 1;    // 连续同色的棋子数
        status[1] = lb;
        status[2] = rb;

        return status;
    }

private:
    chess_t _chesses[MAXSIZE];  // 保存棋盘棋子

    quint8  _cWhite;     // 白棋的数量
    quint8  _cBlack;     // 黑期的数量

    QStack<index_t> _lastIndex;  // 最后一次落子的棋盘位置索引
};

#endif // BOARD_H
