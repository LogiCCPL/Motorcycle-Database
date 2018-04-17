#include "stdafx.h"
#include "Pojemnik.h"


Pojemnik::Pojemnik()
{
	
	fstream plik;
	string dane;
	unsigned int przebieg;
	float moc;
	unsigned short poj;
	short rocznik;

	plik.open("data_base.txt", std::ios::in);
	int iterator = 0;
	if (plik.good())
	{
		string linia;
		while (getline(plik, linia))
		{
			iterator++;
		}
	}
	else
	{
		cout << "ERROR: Can't open file to read data base." << endl;
	}

	plik.close();
	plik.open("data_base.txt", std::ios::in);
	if (plik.good())
	{
		for (int i = 0; i < iterator / 6; i++)
		{
			baza_danych.push_back(new Motocykl());
			plik >> dane;
			baza_danych[i]->setProducent(dane);
			plik >> dane;
			baza_danych[i]->setModel(dane);
			plik >> poj;
			baza_danych[i]->setPojemnosc(poj);
			plik >> moc;
			baza_danych[i]->setMoc(moc);
			plik >> rocznik;
			baza_danych[i]->setRocznik(rocznik);
			plik >> przebieg;
			baza_danych[i]->setPrzebieg(przebieg);
		}

	}
	plik.close();
}


Pojemnik::~Pojemnik()
{
}

void Pojemnik::dodajRekord()
{
	baza_danych.push_back(new Motocykl());
	int i = baza_danych.size();
	cout << i << ". ";
	baza_danych[i - 1]->wprowadzDane();
	cout << "Done !" << endl << endl;
}
void Pojemnik::wyswietlBaze()
{
	for (int i = 0; i < baza_danych.size(); i++)
	{
		baza_danych[i]->wyswietlDane(i + 1);
	}
}

void Pojemnik::usunRekord(int pozycja)
{
	baza_danych.erase(baza_danych.begin() + pozycja - 1);
	cout << "Done !" << endl << endl;
}

void Pojemnik::zmianaRekordu(int pozycja)
{
	baza_danych[pozycja - 1]->wprowadzDane();
	cout << "Done !" << endl << endl;
}

void Pojemnik::szukajRekordu(bool zmiana)
{
	cout << "SEARCHING FOR DATA.\n\n";
	szukaj.wprowadzDane();
	vector <int> wynik;
	for (int i = 0; i < baza_danych.size(); i++)
	{
		if ((szukaj.getProducent() == baza_danych[i]->getProducent() || szukaj.getProducent() == "0") &&  // NAPRAWIC IF
			(szukaj.getModel() == baza_danych[i]->getModel() || szukaj.getModel() == "0") &&
			(szukaj.getPojemnosc() == baza_danych[i]->getPojemnosc() || szukaj.getPojemnosc() == 0) &&
			(szukaj.getMoc() == baza_danych[i]->getMoc() || szukaj.getMoc() == 0) &&
			(szukaj.getRocznik() == baza_danych[i]->getRocznik() || szukaj.getRocznik() == 0) &&
			(szukaj.getPrzebieg() == baza_danych[i]->getPrzebieg() || szukaj.getPrzebieg() == 0))
			wynik.push_back(i);
	}

	
	cout << endl << "FOUND ID's: ";
	for (int i = 0; i < wynik.size(); i++)
		cout << wynik[i] + 1 << "  ";
	cout << endl << endl;
	for (int i = 0; i < wynik.size(); i++)
	{
		baza_danych[wynik[i]]->wyswietlDane(wynik[i] + 1);
	}
	cout << endl;

	if (zmiana)
	{
		for (int i = 0; i < wynik.size(); i++)
		{
			cout << wynik[i] + 1 << ". ";
			zmianaRekordu(wynik[i] + 1);
		}
	}
	else
	{
		cout << "Done !" << endl << endl;
		return;
	}
}

void Pojemnik::sortowanieBazy()
{
	int wybierz;
	do
	{
		cout << "SORTING DATA: \n1 - Capacity\n2 - Power\n3 - Yearbook\n4 - Course\n\nChoose parametr to sort data: ";
		cin >> wybierz;
		system("cls");
		if ((wybierz < 1 || wybierz > 4) && cin.good())
			cout << "Error! Wrong id ! Choose from 1 to 4 ..." << endl << endl;

	} while (cinSprawdzWyczysc() == false || wybierz > 4 || wybierz < 1);

	
	switch (wybierz)
	{
	case 1:
		for (int i = 0; i < baza_danych.size(); i++)
		{
			for (int j = 0; j < baza_danych.size() - 1; j++)
			{
				if (baza_danych[j]->getPojemnosc() < baza_danych[j + 1]->getPojemnosc())
					swap(baza_danych[j], baza_danych[j + 1]);
			}
		}
		break;
	case 2:
		for (int i = 0; i < baza_danych.size(); i++)
		{
			for (int j = 0; j < baza_danych.size() - 1; j++)
			{
				if (baza_danych[j]->getMoc() < baza_danych[j + 1]->getMoc())
					swap(baza_danych[j], baza_danych[j + 1]);
			}
		}
		break;
	case 3:
		for (int i = 0; i < baza_danych.size(); i++)
		{
			for (int j = 0; j < baza_danych.size() - 1; j++)
			{
				if (baza_danych[j]->getRocznik() < baza_danych[j + 1]->getRocznik())
					swap(baza_danych[j], baza_danych[j + 1]);
			}
		}
		break;
	case 4:
		for (int i = 0; i < baza_danych.size(); i++)
		{
			for (int j = 0; j < baza_danych.size() - 1; j++)
			{
				if (baza_danych[j]->getPrzebieg() < baza_danych[j + 1]->getPrzebieg())
					swap(baza_danych[j], baza_danych[j + 1]);
			}
		}
		break;
	default:
		break;
	}
	system("cls");
	cout << "Zrobione !" << endl << endl;

}

void Pojemnik::zapisDanych()
{
	fstream plik;

	plik.open("data_base.txt", ios::out | ios::trunc);
	if (plik.good() == true)
	{
		for (int i = 0; i < baza_danych.size(); i++)
		{
			plik << baza_danych[i]->getProducent() << endl;
			plik << baza_danych[i]->getModel() << endl;
			plik << baza_danych[i]->getPojemnosc() << endl;
			plik << baza_danych[i]->getMoc() << endl;
			plik << baza_danych[i]->getRocznik() << endl;
			plik << baza_danych[i]->getPrzebieg() << endl;
		}
		plik.close();
	}
	else
	{
		cout << "Error! Can't save data to file!" << endl;
	}
	
	
}