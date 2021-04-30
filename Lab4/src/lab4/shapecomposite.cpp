#ifndef SHAPECOMPOSITE_CPP
#define SHAPECOMPOSITE_CPP


#include "shapecomposite.h"

namespace Shapes{

bool ShapeComposite::isIn(int x, int y) const {
    switch(operation) {
        case ShapeOperation::SUM: {
            return this->shape1.get()->isIn(x,y) or this->shape2.get()->isIn(x,y);
        }
        case ShapeOperation::INTERSECTION: {
            return this->shape1.get()->isIn(x,y) and this->shape2.get()->isIn(x,y);
        }
        case ShapeOperation::DIFFERENCE: {
            return this->shape1.get()->isIn(x,y) and !this->shape2.get()->isIn(x,y);
        }
        default: {
            return true;
        }
    }
}
}

#endif
