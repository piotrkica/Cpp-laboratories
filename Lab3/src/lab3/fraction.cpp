#include "fraction.h"


void Fraction::setDenominator(size_t denominator){
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be equal 0");
    }
    this->denominator = denominator;
}

Fraction Fraction::operator+ (const Fraction &other) const{
    Fraction result;
    result.numerator = numerator * other.denominator + other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    result.shorten();
    return result;
}

Fraction Fraction::operator* (const Fraction &other) const{
    Fraction result;
    result.numerator = numerator * other.numerator;
    result.denominator = denominator * other.denominator;
    result.shorten();
    return result;
}

void Fraction::shorten(){
    size_t divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

int Fraction::gcd(size_t a, size_t b){
    if (b==0) return a;
    return gcd(b, a % b);
}
