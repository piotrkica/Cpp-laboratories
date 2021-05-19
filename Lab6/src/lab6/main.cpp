#include <iostream>
#include <gtest/gtest.h>
using namespace ::testing;

#include "utils/programmerDetails.h"
#include "utils/argumentParsing.h"

/** Tresc zadan dla Panstwa:

Zadanie 0: absolutnie obowiazkowe, chociaz bez punktow
1) Pierwsza rzecza jest poprawa bledow kompilacji,
   czyli wpisanie poprawnych Panstwa danych w pliku: programmerDetails.h
2) Oddanne kolokwium musi sie bezwzglednie kompilowac,
   jesli sie nie skompiluje to jest to 0 punktow za kolokwium!
   Oczywiscie w razie problemow z kompilacja prosze pisać.
   Dobrze, jesli nie byloby warningow kompilacji, ale za to nie obnizam punktow.
   Aby się upewnić, że się kompiluje można skorzystać z narzędzia: http://administrare.kis.agh.edu.pl:12345
3) Oddane kolokwium nie powinno crashować na żadnym teście,
   jeśli crashuje proszę zrobic implementacje -fake, ktora nie dopusci do crasha nawet jesli test bedzie failowal, ale za to testy nie beda sie crashowaly.
   W przypadku crasha biorę pod uwagę tylko tyle testów, ile przejdzie do czasu crasha!
5) Mam program antyplagiatowy, dlatego prosze pracowac samodzielnie!
   Osoby ktore udostepniaja swoje rozwiazania rowniez beda mialy kare!

Zadanie implementacyjne: [17pkt] Wykorzystanie biblioteki STL i kontenerów podczas implementacji klasy MyString (ile testów przejdzie, tyle punktów)
Klasa ta ma zawierać statyczna tablice na tekst do 20 znaków, a resztę ma w razie potrzeby pobierać dynamicznie np. przy pomocy typu std::string.
Funkcjonalności są dopasowane tak, aby użyć kilku kontenerów standardowych, poćwiczyć pisanie iteratorów, oraz użyć algorytmów uogólnionych.
Tresc nalezy wydedukowac w oparciu o plik z testami, nad wieloma testami jest sugestia czego można użyć.
    Można też użyć biblioteki boost (oczywiście wtedy w razie błędów kompilacji na sprawdzarce proszę o maila z informacją czego Państwo używają).

Tym razem kod ma się kompilować z flagami:
-Wall -Wextra -pedantic -Werror
dla hardcorów jeszcze:  -Weffc++

FAQ:
    Konieczne może się okazać zrobienie dwóch wersji metod begin/end -jedna stała, druga nie.
    Sygnatury funkcji na Państwa prośbę (pobrane przy pomocy ctags):
        begin             165 mystring.h       iterator begin()
        begin             173 mystring.h       const_iterator begin() const
        capacity           42 mystring.h       auto capacity() const
        cbegin            181 mystring.h       const_iterator cbegin() const
        cend              185 mystring.h       const_iterator cend() const
        const_iterator    122 mystring.h       explicit const_iterator(const MyString* myString, size_t position) :
        empty              46 mystring.h       bool empty() const
        end               169 mystring.h       iterator end()
        end               177 mystring.h       const_iterator end() const
        getPosition       112 mystring.h       auto getPosition() const
        getPosition       157 mystring.h       auto getPosition() const
        iterator           77 mystring.h       explicit iterator(MyString* myString, size_t position) :
        operator !=        58 mystring.h       bool operator!=(const MyString& rhs) const
        operator !=        94 mystring.h       bool operator!=(iterator anotherIt)
        operator !=       139 mystring.h       bool operator!=(const_iterator anotherIt) const
        operator *         90 mystring.h       char& operator*()
        operator *        135 mystring.h       char operator*() const
        operator +        106 mystring.h       iterator operator+(size_t pos)
        operator +        151 mystring.h       const_iterator operator+(size_t pos) const
        operator ++        80 mystring.h       iterator& operator++()
        operator ++       125 mystring.h       const_iterator& operator++()
        operator -        102 mystring.h       size_t operator-(iterator anotherIt)
        operator -        147 mystring.h       size_t operator-(const_iterator anotherIt) const
        operator --        85 mystring.h       iterator& operator--()
        operator --       130 mystring.h       const_iterator& operator--()
        operator ==        98 mystring.h       bool operator==(iterator anotherIt)
        operator ==       143 mystring.h       bool operator==(const_iterator anotherIt) const
        operator []        52 mystring.h       char operator[](size_t i) const
        operator std::string  190 mystring.h       explicit operator std::string() const
        push_back          63 mystring.h       void push_back(char c)
        size               38 mystring.h       auto size() const
**/

int main(int argc, char* argv[])
{
    StudentsInfo::validateStudentsInfo();

    ArgumentParsing::reactToProgramArgumentsPossibilyExit(argc, argv);

    ::testing::InitGoogleTest(&argc, argv);
    GTEST_FLAG(print_time) = false;
    return RUN_ALL_TESTS();
}
