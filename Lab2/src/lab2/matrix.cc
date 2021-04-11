#include <iostream>

using namespace std;

#include "matrix.h"

TwoDimensionMatrix& TwoDimensionMatrix:: operator= (const TwoDimensionMatrix &matrix){
    for (size_t i = 0; i < matrix.getSize(); i++){
        for (size_t j = 0; j < matrix.getSize(); j++){
            values[i][j] = matrix.get(i,j);
        }
    }
    return *this;
}

TwoDimensionMatrix& TwoDimensionMatrix:: operator*= (const MatrixElement number){
    for (size_t i = 0; i < size; i++){
        for (size_t j = 0; j < size; j++){
            values[i][j] *= number;
        }
    }
    return *this;
}

TwoDimensionMatrix TwoDimensionMatrix:: operator&& (const TwoDimensionMatrix& matrix) const{
    TwoDimensionMatrix result;
    for (size_t i = 0; i < size; i++){
        for (size_t j = 0; j < size; j++){
            result[i][j] = this->values[i][j] && matrix.get(i,j);
        }
    }
    return result;
}


