#ifndef MATRIX_H
#define MATRIX_H

/** Tresc zadania:
Ćw2 [16pkt] Przeciążanie operatorów w C++
Plan zajęć:
    Proszę uzupełnić dane w pliku programmerDetails.h

    Zaimplementuj klasę TwoDimensionMatrix odzwierciedlajaca macierz 2*2, zawierającą:
           - tablice typu MatrixElement (tzn. int), oraz size (=2)
           - konstruktory:
             - bezargumentowy - zerujący wszystkie elementy
             - kopiujący
             - przyjmujący jako argument tablicę (const MatrixElement matrix[size][size]) i kopiujący z niej wartości
           - funkcja składowa do dostępu do elementów (get() zwracająca odpowiedni element
           - funkcja zwracająca size o nazwie (getSize()), proponuję aby była static constexpr
    Uzupełnij klasy o następujące operacje zdefiniowane poprzez przeciążenie operatorów:
        - operator przypisania kopiujący (głęboko): operator=()
        - operatory wypisywania do strumienia (funkcja zewn.) - forma dowolna, byleby wszystkie elementy były w strumieniu
        - operatory arytmetyczne (stosujące odpowiednie operacje na macierzach):
            TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2); // jako funkcja globalna
            TwoDimensionMatrix& operator*=(MatrixElement number); // metoda klas 
        - zadany operator logiczny (metoda klasy),
            TwoDimensionMatrix operator&&(const TwoDimensionMatrix& matrix) const;
        - operator tablicowy dostający się po indeksie do pierwszego z wymiarów tablicy (metoda klasy), proszę pamiętać o wersji const
            MatrixElement* operator[](size_t i);
        - operator konwersji do size_t, zwracający to co getSize() (metoda klasy),
    Deklaracja klasy i funkcji globalnych powinna się znaleźć w pliku "matrix.h", natomiast definicje funkcji zewnętrznych i metod klas w pliku źródłowym "matrix.cpp"

Uwaga:
Wszystkie atrybuty powinny być prywatne, konstruktory i metody - publiczne,
metody większe niż 1-linijkowe powinny być zadeklarowane w klasie, zdefiniowane
poza klasą, obiekty typów klasowych powinny być w miarę możliwości przekazywane
w argumentach funkcji przez referencję, proszę też stosować słówko "const" w
odpowiednich miejscach.
**/

#include <iosfwd>

#include "matrixElement.h"


class TwoDimensionMatrix
{
private:
    constexpr static size_t size = 2;

public:
    TwoDimensionMatrix(){
        for (size_t i = 0; i < size; i++){
            for (size_t j = 0; j < size; j++){
                values[i][j] = 0;
            }
        }
    }

    TwoDimensionMatrix(const TwoDimensionMatrix &matrix) {
        for (size_t i = 0; i < size; i++){
            for (size_t j = 0; j < size; j++){
                values[i][j] = matrix.get(i,j);
            }
        }
    }

    TwoDimensionMatrix(const MatrixElement matrix[size][size]){
        for (size_t i = 0; i < size; i++){
            for (size_t j = 0; j < size; j++){
                values[i][j] = matrix[i][j];
            }
        }
    }

    MatrixElement get(int i, int j) const {
        return values[i][j];
    }

    constexpr size_t getSize() const {
        return size;
    }

    TwoDimensionMatrix& operator= (const TwoDimensionMatrix &matrix) ;

    TwoDimensionMatrix& operator*=(const MatrixElement number);

    TwoDimensionMatrix operator&&(const TwoDimensionMatrix& matrix) const;

    MatrixElement* operator[](int i) {
        return &values[i%2][i/2];
    }

    const MatrixElement* operator[](const int i) const{
        return &values[i%2][i/2];
    }

    operator size_t() const{
        return size;
    }
    
private: // methods:

private: // fields:
    MatrixElement values[2][2];
};

inline std::ostream &operator << (std::ostream & stream, const TwoDimensionMatrix &m){
    return stream <<  m[0][0]  << m[0][1] <<  m[1][0] <<  m[1][1];
}

inline TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2){
    TwoDimensionMatrix result;
    for (size_t i = 0; i < matrix1.getSize(); i++){
        for (size_t j = 0; j < matrix1.getSize(); j++){
            result[i][j] = matrix1.get(i,j) + matrix2.get(i,j);
        }
    }
    return result;
}

#endif // MATRIX_H
