/**
 * @author: 江涛 (878490964@qq.com)
 * @date:   2018.07.18
 */
#ifndef GLOBAL_H
#define GLOBAL_H

#include <QtGlobal>

typedef   qint16  index_t;      // 索引类型

// 定义棋盘的最大行和列
constexpr quint32  MAXROW    = 15;
constexpr quint32  MAXCOL    = 15;
constexpr quint32  MAXSIZE   = MAXROW * MAXCOL;

// 偏移量
constexpr qint32   COLOFFSET = 15;  // 水平方向的最小偏移量
constexpr qint32   ROWOFFSET = 1;   // 垂直方向的最小偏移量
constexpr qint32   REVOFFSET = 16;  // 反斜45度方向的最小偏移量
constexpr qint32   FWDOFFSET = 14;  // 正斜45度方向的最小偏移量

constexpr index_t  NO_INDEX  = -1;    // 索引不存在

// 检查索引是否在合法范围内
inline bool checkIndex(index_t index)
{
    // 取值区间[0, MAXSIZE)
    if(quint32(index) < MAXSIZE) return true;
    return false;
}

// 索引所在行号
inline qint32 row(index_t index)
{
    return index / MAXCOL;
}

// 索引所在列号
inline qint32 column(index_t index)
{
    return index % MAXCOL;
}

typedef quint16 chess_t;
constexpr chess_t NC = 0;

// 棋子颜色
enum COLOR
{
    NCR = 0x000,  // 无颜色
    BLK = 0x100,  // 黑棋子
    WHT = 0x200,  // 白棋子
};

constexpr chess_t COLORMASK = 0xF00;
constexpr chess_t REVCCOLOR = 0x300;
inline    chess_t TEST_COLORMASK(chess_t x) { return x & COLORMASK; }

inline COLOR colorType(chess_t x)
{
    chess_t n = TEST_COLORMASK(x);
    return  n & (n-1) ? COLOR::NCR : COLOR(n);
}

inline COLOR next(chess_t x)
{
    return colorType(x ^ REVCCOLOR);
}

enum MODEL
{
    PVP = 0x1,  // 人人对战
    PVE = 0x2,  // 人机对战
    NVP = 0x4,  // 网络对战
};

#endif // GLOBAL_H
