#pragma once
#include "stos.h"
#include "elementStosu.h"
using namespace std;

class Stos {
	ElementStosu *ostatni;
public:
	void dodaj(char *napis);
	char* pobierz();
	bool pusty();
	char* pokaz();
};