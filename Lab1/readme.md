# Laboratories 1

Zaimplementuj podaną na zajęciach klasę reprezentującą Ulamek (ang. Fraction), zawierającą:  
      -licznik (ang. numerator) i mianownik (ang. denominator), proszę aby były protected  
      -konstruktor bezparametrowy, który ustawi wartości licznika i mianownika  
      -konstruktor z parametrami (część z wartością domyślną), który ustawi licznik i mianownik na podstawie parametrów,  wartością domyślną dla mianownika ma być 1    
      -zadany zestaw metod dostępowych/modyfikujących obiekty klasy -tzw. gettery i settery, które umożliwią modyfikacje i pobranie wartości licznika i mianownika  
      -metodę print(), wypisującą atrybuty obiektu na konsolę w formie licznik/mianownik\n  
      -zadany atrybut (removedFractions_) i metodę statyczną: removedFractions().  
      Skladowa ta powinna byc incrementowana w destruktorze  
        
Dodaj do klasy metody zapisz(ostream& os)/wczytaj(istream& is),  
      -zapisujące/odczytujące zawartość obiektu do przekazanego jako parametr strumienia wyjściowego/wejściowego,
      w formacie "licznik/mianownik". Metoda wczytująca może założyć, że format danych będzie poprawny
      (nie trzeba obslugiwac bledow).  
        
Proszę o utworzenie 3 stałych w klasie i metod do odczytu (tzn. getterów):
      -nazwa ułamka jako string  
      -metoda: getFractionName()  
      -stała statyczna odzwierciedlajaca niedopuszczalna wartość mianownika: (ang. invalidDenominatorValue)  
      -metoda: getInvalidDenominatorValue()  
      -statyczna stała czasu kompilacji (constexpr) odzwierciedlajaca domyślna wartość mianownika: (ang. defaultDenominatorValue)  
      -metoda: getDefaultDenominatorValue()  
