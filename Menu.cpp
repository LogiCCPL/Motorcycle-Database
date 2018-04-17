#include "stdafx.h"
#include "Menu.h"


Menu::Menu()
{
	exit = false;
}


Menu::~Menu()
{
}


void Menu::pierwszaOpcja()
{
	system("cls");
	baza_Danych.wyswietlBaze();
	baza_Danych.zapisDanych();
}
void Menu::drugaOpcja()
{
	system("cls");
	baza_Danych.dodajRekord();
	baza_Danych.zapisDanych();
}
void Menu::trzeciaOpcja()
{
	system("cls");
	do
	{
		baza_Danych.wyswietlBaze();
		cout << "Delete record. Choose ID to delete: ";
		cin >> id;
		system("cls");
		if((id < 1 || id > baza_Danych.getSize()) && cin.good())
			cout << "Error! Wrong id ! Choose from 1 to " << baza_Danych.getSize() << "..." << endl << endl;

	} while (cinSprawdzWyczysc() == false || id > baza_Danych.getSize() || id < 1);
	baza_Danych.usunRekord(id);
	baza_Danych.zapisDanych();
	
}
void Menu::czwartaOpcja()
{
	system("cls");
	do
	{
		baza_Danych.wyswietlBaze();
		cout << "Change record. Choose ID to change: ";
		cin >> id;
		system("cls");
		if ((id < 1 || id > baza_Danych.getSize()) && cin.good())
			cout << "Error! Wrong id ! Choose from 1 to " << baza_Danych.getSize() << "..." << endl << endl;

	} while (cinSprawdzWyczysc() == false || id > baza_Danych.getSize() || id < 1);
	baza_Danych.zmianaRekordu(id);
	baza_Danych.zapisDanych();
}
void Menu::piataOpcja()
{
	system("cls");
	baza_Danych.szukajRekordu(false);
	baza_Danych.zapisDanych();
}
void Menu::szostaOpcja()
{
	system("cls");
	baza_Danych.szukajRekordu(true);
	baza_Danych.zapisDanych();
}
void Menu::siodmaOpcja()
{
	system("cls");
	baza_Danych.sortowanieBazy();
	baza_Danych.zapisDanych();
}

void Menu::Uruchom()
{
	do
	{
		cout << "Menu:\n1 - Show data base\n2 - Add record\n3 - Delete record\n4 - Change record with ID\n5 - Find records with data\n6 - Find and change records with data\n7 - Sort data base";
		cout << endl << endl << "Choose what to do: ";
		cin >> wybierz;
		if (cin.fail())
		{
			system("cls");
			cout << "Error! Wrong symbol. Try again..." << endl << endl;
		}
			
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
		

		switch (wybierz)
		{
		case 1:
			pierwszaOpcja();
			break;
		case 2:
			drugaOpcja();
			break;
		case 3:
			trzeciaOpcja();
			break;
		case 4:
			czwartaOpcja();
			break;
		case 5:
			piataOpcja();
			break;
		case 6:
			szostaOpcja();
			break;
		case 7:
			siodmaOpcja();
			break;
		case 8:
			exit = true;
			break;
		default:
			system("cls");
			cout << "Error! Wrong symbol. Try again..." << endl << endl;
			break;
		}


	} while (exit == false);
}