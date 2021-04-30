#ifndef STAGE_H
#define STAGE_H

#include <iosfwd>

namespace Shapes
{
class Shape;
}

class Stage
{
    int width, height;

    constexpr static char emptySymbol{' '};
    constexpr static char shapeSymbol{'*'};

public:
    Stage(int width, int height) : width(width), height(height)
    {}

    void drawShape2Stream(const Shapes::Shape* shape, std::ostream& stream) const{
        /*for (int i = height+10; i >= -10; i--){
            for (int j = -10; j < width+10; j++){
                if (shape->isIn(i, j)){
                    stream << shapeSymbol;
                }
                else{
                    stream << emptySymbol;
                }
            }
            stream << "\n";
        }*/

    }

};

#endif // STAGE_H
