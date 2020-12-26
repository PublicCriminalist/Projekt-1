#include <iostream>
#include "gra.hpp"

using namespace std;

int main()
{
    Gra game;
    bool stan=0;
    cout << "Proste przedsiebiorstwo by Piotr Marciniak\nKomendy:\nlp - Wydrukuj liste pracownikow\nzinz - zatrudnij inzyniera (pensja: 3000)" << endl;
    cout << "zmag - zatrudnij magazyniera (pensja: 1000)\nzmkt - zatrudnij marketera(pensja: 2000)\nzrob - zatrudnij robotnika (pensja: 1000)\nkred - wez kredyt" << endl;
    cout << "stan - wyswietl stan firmy\nsk - wyswietl pozyczki\nkt - zakoncz ture\nend - zakoncz gre\n" << endl;
    cout << "Budzet poczatkowy: 10000\nWartosc firmy wymagana do wygrania: 100000\nLimit czasowy: 120 tur\nWartosc firmy obliczana jest na przychodu z 3 ostatnich dni" << endl;
    while (stan==0) {
        stan=game.akcja();
    }
    cout << "Koniec gry" << endl;
    return 0;
}

/*Sta³e w programie:
* Liczba dni liczona do wartoœci firmy N=3
* Maksymalna liczba rat d³ugu X=12
* Wsp. maksymalnego zad³u¿enia M=2
* P³aca in¿yniera Inz.X=3000
* P³aca magazyniera Mag.X=1000
* P³aca marketera Mkt.X=2000
* P³aca robotnika Rob.X=1000
* Cena produktu na in¿yniera CI=700
* Pojemnoœæ magazynu na magazyniera CMag=10
* Popyt na marketera Cmkt=20
* Produkcja na robotnika CR=10
* Maksymalna liczba danych pracowników: 20
* Maksymalna liczba tur: 120
* Warunek zwyciêstwa: 100 000
* Odsetki obliczane s¹ na podstawie wzoru d³ug*(liczba rat)/100
*/