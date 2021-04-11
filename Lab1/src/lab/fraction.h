#ifndef TASK1_FRACTION_H
#define TASK1_FRACTION_H

#include <iosfwd>
#include <string>

/**
Zaimplementuj podaną na zajęciach klasę reprezentującą Ulamek (ang. Fraction), zawierającą:
    licznik (ang. numerator) i mianownik (ang. denominator), proszę aby były protected
    konstruktor bezparametrowy, który ustawi wartości licznika i mianownika
    konstruktor z parametrami (część z wartością domyślną), który ustawi licznik i mianownik na podstawie parametrów,
        wartością domyślną dla mianownika ma być 1
    zadany zestaw metod dostępowych/modyfikujących obiekty klasy -tzw. gettery i settery,
        które umożliwią modyfikacje i pobranie wartości licznika i mianownika
    metodę print(), wypisującą atrybuty obiektu na konsolę w formie licznik/mianownik\n
    zadany atrybut (removedFractions_) i metodę statyczną: removedFractions().
        Skladowa ta powinna byc incrementowana w destruktorze

    Dodaj do klasy metody zapisz(ostream& os)/wczytaj(istream& is),
        zapisujące/odczytujące zawartość obiektu do przekazanego jako parametr strumienia wyjściowego/wejściowego,
        w formacie "licznik/mianownik". Metoda wczytująca może założyć, że format danych będzie poprawny
        (nie trzeba obslugiwac bledow).

    Proszę o utworzenie 3 stałych w klasie i metod do odczytu (tzn. getterów):
        nazwa ułamka jako string
            metoda: getFractionName()
        stała statyczna odzwierciedlajaca niedopuszczalna wartość mianownika: (ang. invalidDenominatorValue)
            metoda: getInvalidDenominatorValue()
        statyczna stała czasu kompilacji (constexpr) odzwierciedlajaca domyślna wartość mianownika: (ang. defaultDenominatorValue)
            metoda: getDefaultDenominatorValue()
**/

class Fraction{
    protected:
        const std::string fractionName;
        int numerator, denominator;
        inline static int removedFractions_;
        const static int invalidDenominatorValue = 0;
        constexpr static int defaultDenominatorValue = 1;

    public:
        Fraction():fractionName("") {
        }

        Fraction(int numerator, int denominator = 1, std::string name = ""):fractionName(name) {
            this->numerator=numerator;
            this->denominator=denominator;
        }

        void setNumerator(int newNumerator){
            this->numerator= newNumerator;
        }

        void setDenominator(int newDenominator){
            this->denominator= newDenominator;
        }

        int getNumerator(){
            return this->numerator;
        }

        int getDenominator(){
            return this->denominator;
        }

        std::string getFractionName(){
            return this->fractionName;
        }

        void print() const{
            std::cout << this->numerator << "/" << this->denominator << "\n";
        }

        inline void load (std::istream &is);

        void save(std::ostream &os) const{
            os << this->numerator << "/" << this->denominator;
        }

        static int removedFractions() {
            return removedFractions_;
        }

        ~Fraction(){
            removedFractions_++;
        }

        static int getInvalidDenominatorValue(){
            return invalidDenominatorValue;
        }

        constexpr static int getDefaultDenominatorValue(){
            return defaultDenominatorValue;
        }
};

void Fraction::load (std::istream &is) {
    std::string tmp;
    std::getline(is, tmp);
    int i = tmp.find('/');
    this->numerator = stoi(tmp.substr(0,i));
    this->denominator = stoi(tmp.substr(i+1,tmp.length()));
}

constexpr bool classFractionExists = true;
constexpr bool hasNumeratorAndDenominator = true;
constexpr bool hasConstructorWhichInitialiseFields = true;
constexpr bool hasGettersAndSetters = true;
constexpr bool hasPrintFunction = true;
constexpr bool counterOfDestructedFractionsImplemented = true;
constexpr bool readWriteImplemented = true;
constexpr bool fractionNameSettableFromConstructor = true;
constexpr bool fractionConstStaticFieldsImplemented = true;



#endif // TASK1_FRACTION_H
