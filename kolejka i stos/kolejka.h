#pragma once
#include "elementKolejki.h"
#include "kolejka.h"
using namespace std;

class Kolejka {
	ElementKolejki *pierwszy;
	ElementKolejki *ostatni;
public:
	Kolejka();
	void dodaj(char *napis);
	char* pobierz();
	bool pusty();
	char* pokaz();
};