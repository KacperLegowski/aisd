#include "elementKolejki.h"
#include "kolejka.h"
using namespace std;

Kolejka::Kolejka() {
	this->ostatni = NULL;
	this->pierwszy = NULL;
}

void Kolejka::dodaj(char *napis) {
	if (pierwszy == NULL) {
		pierwszy = new ElementKolejki(napis);
		ostatni = pierwszy;
	}
	else if (ostatni == NULL) {
		ElementKolejki *temp = new ElementKolejki(napis);
		pierwszy->nastepny = temp;
		ostatni = temp;
	}
	else {
		ElementKolejki *temp = new ElementKolejki(napis);
		ostatni->nastepny = temp;
		ostatni = temp;
	}
}

char* Kolejka::pobierz() {
	if (pierwszy == NULL) {
		char *koniec = "#";
		return koniec;
	}
	else {
		char *napis = pierwszy->wyraz;
		ElementKolejki *temp1 = pierwszy->nastepny;
		delete pierwszy;
		pierwszy = temp1;
		return napis;
	}
}

bool Kolejka::pusty() {
	if (pierwszy == NULL) {
		return true;
	}
	else {
		return false;
	}
}

char* Kolejka::pokaz() {
	if (pierwszy == NULL) {
		return "#";
	}
	return pierwszy->wyraz;
}