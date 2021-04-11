// author: Grzegorz Prowadzacy

#include "vector.h"

Vector::Vector (const Vector &other){
    _capacity = other.capacity();
    _size = other.size();
    data = new Fraction[_capacity];
    memcpy(data, other.data, _size * sizeof(Fraction));
}

Vector::Vector (Vector && other):_capacity(std::move(other._capacity)), _size(std::move(other._size)){
    data = new Fraction[_capacity];
    data = other.data;
    other.data = nullptr;
    other._size = 0;
    other._capacity = 0;
}


void Vector:: push_back(const Fraction &fraction){
    if (this->_size == this->_capacity){
        Fraction* newData = new Fraction[++_capacity];
        std::copy(data, data + 1, newData);
        delete[] data;
        data = newData;
    }
    this->data[this->_size] = fraction;
    this->_size++;
}

Fraction& Vector::operator[] (size_t i) {
    if (_size <= i){
        throw std::out_of_range("Accessing element outside vector");
    }
    return data[i];
}

Fraction Vector::operator[] (size_t i) const {
    if (_size <= i){
        throw std::out_of_range("Accessing element outside vector");
    }
    return data[i];
}

Vector& Vector::operator=(const Vector& other){
    if (this == &other) return *this;
    _capacity = other._capacity;
    _size = other._size;
    data = new Fraction[_capacity];
    memcpy ( data, other.data, _size * sizeof(Fraction) );

    return *this;
}

Vector& Vector::operator=(Vector &&other){
    if (this == &other) return *this;
    _capacity = other._capacity;
    _size = other._size;
    delete[] data;
    data = other.data;
    other.data = nullptr;
    other._size = 0;
    other._capacity = 0;
    return *this;
}
