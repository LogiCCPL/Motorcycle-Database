#pragma once
#include <string>
#include <iostream>
#include "Motocykl.h"
#include <vector>
#include "Pojemnik.h"


class Menu
{
	Pojemnik baza_Danych;
	int wybierz, id;
	bool exit;

public:
	Menu();
	~Menu();
	void pierwszaOpcja();
	void drugaOpcja();
	void trzeciaOpcja();
	void czwartaOpcja();
	void piataOpcja();
	void szostaOpcja();
	void siodmaOpcja();

	void Uruchom();

};

