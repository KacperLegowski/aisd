#include "stos.h"
#include "elementStosu.h"
using namespace std;

void Stos::dodaj(char *napis) {
	if (ostatni == NULL) {
		ostatni = new ElementStosu(napis);
	}
	else {
		ElementStosu *temp = new ElementStosu(napis);
		temp->poprzedni = ostatni;
		ostatni = temp;
	}
}

char* Stos::pobierz() {
	if (ostatni == NULL) {
		char *koniec = "#";
		return koniec;
	}
	else {
		char *napis = ostatni->wyraz;
		ElementStosu *temp = ostatni->poprzedni;
		delete ostatni;
		ostatni = temp;
		return napis;
	}
}

bool Stos::pusty() {
	if (ostatni == NULL) {
		return true;
	}
	else {
		return false;
	}
}

char* Stos::pokaz() {
	if (ostatni == NULL) {
		return "#";
	}
	return ostatni->wyraz;
}