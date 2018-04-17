#pragma once
#include <string>
#include <iostream>
#include "Motocykl.h"
#include <vector>
#include <fstream>
using namespace std;

class Pojemnik
{
	Motocykl szukaj;
	vector <Motocykl*> baza_danych;

public:
	Pojemnik();
	~Pojemnik();
	void dodajRekord();
	void wyswietlBaze();
	void usunRekord(int pozycja);
	void zmianaRekordu(int pozycja);
	void szukajRekordu(bool zmiana);
	void sortowanieBazy();
	void zapisDanych();
	int getSize() { return baza_danych.size(); }

};

