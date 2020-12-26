#pragma once

class Kredyt
{
public:
	Kredyt() { dlug = 0; rata = 0; lrat = 0; }
	Kredyt(double kwota, int czas){
		if (czas > X) czas = X;
		dlug = kwota+kwota*czas/100;
		lrat = czas;
		rata = dlug / lrat;
		dlug_pocz = dlug;
		lrat_pocz = lrat;
	}
	double splac() {
		dlug -= rata;
		lrat--;
		return rata;
	}
	int getraty() { return lrat; };
	double getdlug() { return dlug; };
	double getdlugpocz() { return dlug_pocz; };
	int getratypocz() { return lrat_pocz; };
	~Kredyt(){}
private:
	double dlug;
	double dlug_pocz;
	double rata;
	int lrat_pocz;
	unsigned short int lrat;
	static const unsigned short int X = 12;
};