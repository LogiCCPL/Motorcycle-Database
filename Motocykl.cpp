#include "stdafx.h"
#include "Motocykl.h"




Motocykl::Motocykl()
{
	this->model = new string("Unknown");
	this->producent = new string("Unknown");
	this->moc = new float(0);
	this->pojemnosc = new unsigned short(0);
	this->przebieg = new unsigned int(0);
	this->rocznik = new short(0);

}
Motocykl::Motocykl(string _producent, string _model, unsigned short _pojemnosc, float _moc, short _rocznik, unsigned int _przebieg )
{
	this->model = new string(_model);
	this->producent = new string(_producent);
	this->moc = new float(_moc);
	this->pojemnosc = new unsigned short(_pojemnosc);
	this->przebieg = new unsigned int(_przebieg);
	this->rocznik = new short(_rocznik);

}

Motocykl::Motocykl(const Motocykl & kopia)
{
	this->model = kopia.model;
	this->moc = kopia.moc;
	this->pojemnosc = kopia.pojemnosc;
	this->przebieg = kopia.przebieg;
	this->rocznik = kopia.rocznik;
	this->producent = kopia.producent;
}

const Motocykl & Motocykl::operator = (const Motocykl &motocyklRef)
{
	model = motocyklRef.model;
	pojemnosc = motocyklRef.pojemnosc;

	return *this;
}


Motocykl::~Motocykl()
{
}

void Motocykl::setRocznik(short _rocznik)
{
	this->rocznik = new short(_rocznik);
}
void Motocykl::setModel(string _model)
{
	this->model = new string(_model);
}
void Motocykl::setPrzebieg(unsigned int _przebieg)
{
	this->przebieg = new unsigned int(_przebieg);
}
void Motocykl::setMoc(float _moc)
{
	this->moc = new float(_moc);
}
void Motocykl::setPojemnosc(unsigned short _pojemnosc)
{
	this->pojemnosc = new unsigned short(_pojemnosc);
}
void Motocykl::setProducent(string _producent)
{
	this->producent = new string(_producent);
}


short Motocykl::getRocznik()
{
	return *rocznik;
}
string Motocykl::getModel()
{
	return *model;
}
unsigned int Motocykl::getPrzebieg()
{
	return *przebieg;
}
float Motocykl::getMoc()
{
	return *moc;
}
unsigned short Motocykl::getPojemnosc()
{
	return *pojemnosc;
}
string Motocykl::getProducent()
{
	return *producent;
}


void Motocykl::wyswietlDane(int i)
{
	cout << i << ". Motorcycle data: " << endl;
	cout << "Manufacturer: " << *producent << endl;
	cout << "Model: " << *model << endl;
	cout << "Capacity: " << *pojemnosc << endl;
	cout << "Power (KM): " << *moc << endl;
	cout << "Yearbook: " << *rocznik << endl;
	cout << "Course: " << *przebieg << endl << endl;
}

void Motocykl::wprowadzDane()
{
	do {

		cout << "Enter motorcycle data: " << endl;
		cout << "Manufacturer: "; cin >> *producent;
		cout << "Model: "; cin >> *model;
		cout << "Capacity: "; cin >> *pojemnosc;
		cout << "Power (KM): "; cin >> *moc;
		cout << "Yearbook: "; cin >> *rocznik;
		cout << "Course: "; cin >> *przebieg;
		cout << endl;
		system("cls");

	} while (cinSprawdzWyczysc() == false);
	
}

bool cinSprawdzWyczysc()
{
	bool cin_good;
	if (cin.fail())
	{
		cin_good = false;
		cout << "Error! Wrong symbol. Try again..." << endl << endl;
	}
	else
		cin_good = true;

	cin.clear();
	cin.ignore(numeric_limits < streamsize >::max(), '\n');

	return cin_good;


}