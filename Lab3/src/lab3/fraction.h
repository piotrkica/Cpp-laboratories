#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>

/** Implementacja ulamka:
Zaimplementuj klase Ulamek (ang. Fraction), posiadająca licznik (ang. numerator) i mianownik (ang. denominator).
       Powinna zawierac jeden konstruktor ustawiajacy licznik i mianownik (domyslne wartosci licznika=0 a mianownika domyslna 1)
       Gettery i settery do wartosci licznika i mianownika
          Settery nie powinny skracac ulamkow
       operator+ dla ulamka zwracajacy ulamek
       operator* dla ulamka zwracajacy ulamek
Niepoprawny mianownik powinien byc zglaszany przez wyjatek std::invalid_argument.
Prosze o skracanie ulamkow po operacji + i * (pomocny moze sie okazac algorytm euklidesa), oczywiscie tutaj robimy tylko dla przypadkow dodatnich
**/

class Fraction{
private:
    size_t numerator, denominator;

public:
    Fraction(size_t n = 0, size_t d = 1): numerator(n){
        d == 0 ? throw std::invalid_argument("Denominator cannot be equal 0") : denominator = d;
    }

    size_t getNumerator() const{
        return numerator;
    }

    size_t getDenominator() const{
        return denominator;
    }

    void setNumerator(size_t numerator){
        this->numerator = numerator;
    }

    void setDenominator(size_t denominator);

    Fraction operator+ (const Fraction &other) const;

    Fraction operator* (const Fraction &other) const;

    void shorten();

private:
    int gcd(size_t a, size_t b);
};

#endif // FRACTION_H
