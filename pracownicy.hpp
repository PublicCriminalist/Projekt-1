#pragma once
#include <iostream>
#include <string>
#include "RNG.hpp"
using namespace std;

class Inz
{
public:
	Inz() {}
	void setprac(string rwydzial) { imie = get_random_name(); wydzial = rwydzial; }
	void print() { cout << imie << ", " << wydzial << endl; }
	~Inz() {}
	static const int CI = 700;
	static const int X = 3000;
private:
	string imie;
	string wydzial;
	
};

class Mag
{
public:
	Mag(){}
	void setprac(bool robsl) { imie = get_random_name(); obsl=robsl; }
	void print() { cout << imie << ", " << obsl << endl; };
	~Mag() {};
	static const int CMag = 10;
	static const int X = 1000;
private:
	string imie;
	bool obsl;
	
};

class Mkt
{
public:
	Mkt() {}
	void setprac(int rfollows) { imie = get_random_name(); follows = rfollows; }
	void print() { cout << imie << ", " << follows << endl; };
	~Mkt(){}
	static const int CMkt = 20;
	static const int X = 2000;
private:
	string imie;
	int follows;
	
};

class Rob
{
public:
	Rob() {}
	void setprac(double rbut) { imie = get_random_name(); but = rbut; }
	void print() { cout << imie << ", " << but << endl; };
	~Rob(){}
	static const int CR = 10;
	static const int X = 1000;
private:
	string imie;
	double but;
	
};