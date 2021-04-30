#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace Shapes
{
class Rectangle : public Shape
{
private:
    int x1, y1, x2, y2;
public:
    Rectangle(int xFrom, int yFrom, int xTo, int yTo):x1(xFrom), y1(yFrom), x2(xTo), y2(yTo){}

    bool isIn(int x, int y) const {
        return x1 <= x && x <= x2 && y1 <= y && y <= y2;
    }

    int getX() const {
        return x1;
    }

    int getY() const {
        return y1;
    }
    int getXTo() const {
        return x2;
    }
    int getYTo() const {
        return y2;
    }
};
} // namespace Shapes

#endif // RECTANGLE_H
