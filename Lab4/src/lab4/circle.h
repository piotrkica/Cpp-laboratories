#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <math.h>

namespace Shapes
{
class Circle : public Shape
{
private:
    int center_x;
    int center_y;
    int radius;
public:
    Circle(int x, int y, int r): center_x(x), center_y(y), radius(r){}

    bool isIn(int x, int y) const {
        return sqrt(pow((center_x-x),2) + pow((center_y - y), 2)) <= radius;
    }

    int getX() const{
         return center_x;
    }

    int getY() const {
         return center_y;
    }

    int getRadius() const {
         return radius;
    }

};
} // namespace Shapes

#endif // CIRCLE_H
