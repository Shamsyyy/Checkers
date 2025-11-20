#pragma once
#include <stdlib.h>

typedef int8_t POS_T;

// Структура, описывающая один возможный ход фигуры.
struct move_pos
{
    POS_T x, y;             // исходная клетка (строка и столбец), откуда делается ход
    POS_T x2, y2;           // целевая клетка, куда ходим
    POS_T xb = -1, yb = -1; // координаты сбитой фигуры при взятии; -1, если взятия нет

    // Конструктор для хода без взятия.
    move_pos(const POS_T x, const POS_T y, const POS_T x2, const POS_T y2)
        : x(x), y(y), x2(x2), y2(y2)
    {
    }

    // Конструктор для хода со взятием (с координатами сбитой фигуры).
    move_pos(const POS_T x, const POS_T y, const POS_T x2, const POS_T y2, const POS_T xb, const POS_T yb)
        : x(x), y(y), x2(x2), y2(y2), xb(xb), yb(yb)
    {
    }

    // Сравнение двух ходов: совпадают ли все координаты "откуда-куда".
    bool operator==(const move_pos &other) const
    {
        return (x == other.x && y == other.y && x2 == other.x2 && y2 == other.y2);
    }

    bool operator!=(const move_pos &other) const
    {
        return !(*this == other);
    }
};
