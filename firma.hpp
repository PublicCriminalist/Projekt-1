#pragma once
#include <iostream>
#include <string>
#include "pracownicy.hpp"
#include "kredyt.hpp"

class Firma
{
public:
	Firma() {
		stan_konta = 10000;
		n_kred = 0;
		n_inz = 1;
		n_mag = 1;
		n_mkt = 1;
		n_rob = 1;
		w_kred = 0;
		inz[0].setprac("przyjaciel");
		mag[0].setprac(true);
		mkt[0].setprac(5000);
		rob[0].setprac(42.5);
		tura = 0;
	}
	void drukuj() {
		cout << "Inzynierowie:" << endl;
		for (int i = 0; i < n_inz; i++) inz[i].print();
		cout << "Magazynierzy:" << endl;
		for (int i = 0; i < n_mag; i++) mag[i].print();
		cout << "Marketerowie:" << endl;
		for (int i = 0; i < n_mkt; i++) mkt[i].print();
		cout << "Robotnicy:" << endl;
		for (int i = 0; i < n_rob; i++) rob[i].print();
	}
	void wez_kredyt() {
		double kwota;
		int czas;
		cout << "Ile? ";
		cin >> kwota;
		if (w_kred + kwota <= M*wartosc()) {
			cout << "Na jak dlugo? ";
			cin >> czas;
			kredyt.push_back(Kredyt(kwota, czas));
			n_kred++;
			w_kred += kredyt[n_kred - 1].getdlug();
		}
		else cout << "Suma kredytow przekracza wartosc firmy. Pozyczka nieudzielona" << endl;
	}
	void zatrudnij_inz() {
		if (n_inz < Z) {
			string wydzial;
			cout << "Jaki wydzial? ";
			cin >> wydzial;
			inz[n_inz].setprac(wydzial);
			n_inz++;
		}
		else cout << "Osiagnieto maksymalna liczbe inzynierow" << endl;
	}
	void zatrudnij_mag() {
		if (n_inz < Z) {
			bool obsl;
			cout << "Ma obslugiwac wozek? ";
			cin >> obsl;
			mag[n_mag].setprac(obsl);
			n_mag++;
		}
		else cout << "Osiagnieto maksymalna liczbe magazynierow" << endl;
	}
	void zatrudnij_mkt() {
		if (n_mkt < Z) {
			int follows;
			cout << "Ile sledzacych? ";
			cin >> follows;
			mkt[n_mkt].setprac(follows);
			n_mkt++;
		}
		else cout << "Osiagnieto maksymalna liczbe marketerow" << endl;
	}
	void zatrudnij_rob() {
		if (n_rob < Z) {
			double but;
			cout << "Jaki but? ";
			cin >> but;
			rob[n_rob].setprac(but);
			n_rob++;
		}
		else cout << "Osiagnieto maksymalna liczbe robotnikow" << endl;
	}
	int przychod() {
		int prod = n_rob * rob[0].CR;
		int poj=n_mag*mag[0].CMag;
		if (prod > poj) prod = poj;
		int popyt = n_mkt * mkt[0].CMkt;
		if (prod > popyt) prod = popyt;
		int cena = n_inz * inz[0].CI;
		return prod * cena;
	}
	int wynagrodzenie() {
		return n_rob * rob[0].X + n_mag * mag[0].X + n_mkt * mkt[0].X + n_inz * inz[0].X;
	}
	int splac() {
		double splata=0;
		for (int i = n_kred-1; i >=0; i--) {
			double rata = kredyt[i].splac();
			splata+=rata;
			w_kred -= rata;
			if (kredyt[i].getraty() == 0) {
				kredyt.erase(kredyt.begin() + i);
				n_kred--;
			}
		}
		return splata;
	}

	double wartosc() {
		double wartosc = (historia[(tura<3)? 0:tura-3] + historia[(tura < 1) ? 0 : tura-1] + historia[(tura < 2) ? 0 : tura-2]) / N;
		return wartosc;
	}
	void dochod() {
		int dochod = przychod() - wynagrodzenie() - splac();
		stan_konta += dochod;
		historia[tura] = przychod();
		cout << "Stan na ture " << tura + 1 << ": " << stan_konta << endl;
		tura++;
		cout << "Wartosc spolki wynosi: " << wartosc() << endl;
	}

	void stan() {
		cout << "Stan firmy:\nStan konta: " << stan_konta << "\nWartosc firmy: " << wartosc() << "\nPensje pracownikow w tej turze: " << wynagrodzenie() << endl;
		cout << "Przychod w tej turze: " << przychod() << "\nTura: " << tura+1 << endl;
	}

	void kredyty() {
		cout << "Stan kredytow: \nLiczba kredytow: " << n_kred << "\nLaczne zadluzenie: " << w_kred << "\nZaciagniete kredyty: " << endl;

		for (int i = 0; i < n_kred; i++) {
			cout << endl;
			cout << "Numer kredytu: " << i + 1 << "\nWartosc kredytu: " << kredyt[i].getdlugpocz() << "\nPozostalo do splaty: " << kredyt[i].getdlug() << endl;
			cout << "Liczba rat: " << kredyt[i].getratypocz() << "\nPozostalo rat: " << kredyt[i].getraty() << endl;
			
		}
	}

	bool victory() {
		bool stan = 0;
		if(stan_konta<0){
			cout << "Zbankrutowales\nPrzegrales!" << endl;
			stan = 1;
		}
		if(tura==120){
			cout << "Skonczyl sie czas\nPrzegrales!" << endl;
			stan = 1;
		}
		double warunek = wartosc() - w_kred;
		if (warunek >= zwyciestwo) {
			cout << "Osiagnales wymagana wartosc firmy\nWygrales!" << endl;
			stan = 1;
		}
		return stan;
	}

	~Firma(){}
private:
	int stan_konta;

	vector<Kredyt> kredyt;
	unsigned short int n_kred;
	double w_kred;

	unsigned short int n_inz;
	unsigned short int n_mag;
	unsigned short int n_mkt;
	unsigned short int n_rob;

	static const unsigned short int Z = 20;
	Inz inz[Z];
	Mag mag[Z];
	Mkt mkt[Z];
	Rob rob[Z];

	int historia[120];

	unsigned short int tura;
	static const unsigned short int N=3;
	static const unsigned short int M = 2;
	

	static const int zwyciestwo=100000;
};