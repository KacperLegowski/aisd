#include <stdio.h>
#include <iostream>
#include "Wezel.h"
using namespace std;

int main() {
	int krawedzie, sciezki;
	scanf_s("%d %d", &krawedzie, &sciezki);
	Wezel **drzewo = new Wezel*[krawedzie + 2];
	int poczatek, koniec, kwiaty;
	for (int j = 1;j < krawedzie + 2;j++) {
		drzewo[j] = new Wezel(j, sciezki);
	}
	for (int i = 1;i < krawedzie + 1;i++) {
		scanf_s("%d %d %d", &poczatek, &koniec, &kwiaty);
		drzewo[poczatek]->dodajWezel(drzewo[koniec], kwiaty);
		drzewo[koniec]->dodajWezel(drzewo[poczatek], kwiaty);
	}
	drzewo[1]->lewy = drzewo[1]->tab[0];
	drzewo[1]->lewy->rodzic = drzewo[1];
	drzewo[1]->lewy->budujDrzewo(drzewo[1]);
	int wynik = drzewo[1]->szukaj(sciezki);
	printf_s("%d", wynik);
	for (int k = 1; k < krawedzie + 2;k++) {
		delete drzewo[k];
	}
	return 0;
}
