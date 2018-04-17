#pragma once
#include <string>
#include <iostream>
using namespace std;

class Motocykl
{
	short * rocznik;
	string * model, * producent;
	unsigned int * przebieg;
	float * moc;
	unsigned short * pojemnosc;

public: 
	Motocykl();
	Motocykl(string, string, unsigned short, float, short, unsigned int );
	Motocykl(const Motocykl &);
	const Motocykl & operator = (const Motocykl &motocyklRef);
	~Motocykl();

	void setRocznik(short);
	void setModel(string);
	void setPrzebieg(unsigned int);
	void setMoc(float);
	void setPojemnosc(unsigned short);
	void setProducent(string);

	short getRocznik();
	string getModel();
	unsigned int getPrzebieg();
	float getMoc();
	unsigned short getPojemnosc();
	string getProducent();

	void wyswietlDane(int);
	void wprowadzDane();

};

bool cinSprawdzWyczysc();


