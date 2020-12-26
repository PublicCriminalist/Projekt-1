#pragma once
#include <string>
#include "firma.hpp"

class Gra
{
public:
	Gra() { firma = new Firma; stan = 0; }
	bool akcja() {
		string command;
		cout << "\nCo chcesz zrobic? ";
		cin >> command;
		if (command == "lp") firma->drukuj();
		else if (command == "zinz") firma->zatrudnij_inz();
		else if (command == "zmag") firma->zatrudnij_mag();
		else if (command == "zmkt") firma->zatrudnij_mkt();
		else if (command == "zrob") firma->zatrudnij_rob();
		else if (command == "kred") firma->wez_kredyt();
		else if (command == "stan") firma->stan();
		else if (command == "sk") firma->kredyty();
		else if (command == "kt") {
			firma->dochod();
			stan = firma->victory();
		}
		else if (command == "end") stan = 1;
		return stan;
	}


	~Gra() { delete firma; }
private:
	Firma* firma;
	bool stan;
};