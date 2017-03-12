#include <iostream>
#include <stdio.h>
#include "stos.h"
#include "elementStosu.h"
#include "elementKolejki.h"
#include "kolejka.h"
using namespace std;


Kolejka *k = new Kolejka();
Stos *s = new Stos();

void add(char gdzie, char* tekst) { //dodawania do stosu lub kolejki
	if (gdzie == 's') {
		s->dodaj(tekst);
	}
	else{
		k->dodaj(tekst);
	}
}

void del(char skad) {
	if (skad == 's') {
		s->pobierz();
	}
	else {
		k->pobierz();
	}
}

void powiel(char zrodlo, char cel) {
	if ((zrodlo == 's' && s->pusty()) || (zrodlo == 'k' && k->pusty()))
		return;
	char* temp = (char*)malloc(3002 * sizeof(char));
	if (zrodlo == 's' && cel == 'k') {
			temp = s->pokaz();
			k->dodaj(temp);
	}
	else if (zrodlo == 'k' && cel == 's') {
			temp = k->pokaz();
			s->dodaj(temp);
	}
	else if (zrodlo == 's' && cel == 's') {
			temp = s->pokaz();
			s->dodaj(temp);
	}
	else {
			temp = k->pokaz();
			k->dodaj(temp);
	}
	//free(temp);
}

void przenies(char zrodlo, char cel) {
	if ((zrodlo == 's' && s->pusty()) || (zrodlo == 'k' && k->pusty()))
		return;
	char* temp = (char*)malloc(3002 * sizeof(char));
	if (zrodlo == 's') {
		temp = s->pobierz();
	}
	else {
		temp = k->pobierz();
	}
	if (cel == 's') {
		s->dodaj(temp);
	}
	else {
		k->dodaj(temp);
	}
}

char* laczenie(char *pierwszy, char* drugi) {
	int i = 0, j = 0, x = 0, l = 0;
	while (pierwszy[i] != '\0') {
		i++;
	}
	while (drugi[j] != '\0') {
		j++;
	}
	char *nowy = (char*)malloc((i + j)*sizeof(char));
	for (l;l < i;l++) {
		nowy[l] = pierwszy[l];
	}
	for (x;x < j;x++) {
		nowy[l + x] = drugi[x];
	}
	nowy[i + j] = '\0';
	return nowy;
}

void polacz(char zrodlo, char cel) {
	char * temp = (char*)malloc(3002 * sizeof(char));
	char * temp1 = (char*)malloc(3002 * sizeof(char));
	char * temp2 = (char*)malloc(3002 * sizeof(char));
	temp1 = k->pokaz();
	temp2 = s->pokaz();
	if (zrodlo == 'k' && cel == 's') {
		temp = laczenie(temp1, temp2);
		s->dodaj(temp);
	}
	else if (zrodlo == 's' && cel == 'k') {
		temp = laczenie(temp2, temp1);
		k->dodaj(temp);
	}
	else if (zrodlo == 's' && cel == 's'){
		temp = laczenie(temp2, temp1);
		s->dodaj(temp);
	}
	else {
		temp = laczenie(temp1, temp2);
		k->dodaj(temp);
	}
	/*free(temp);
	free(temp1);
	free(temp2);*/
}

void wyswietl(char zrodlo) {
	if (zrodlo == 's') {
		cout << s->pokaz() << endl;
	}
	else {
		cout << k->pokaz() << endl;
	}
}

int main() {
	char *polecenie = new char[256];
	int liczbaPolecen;
	char *tekst;
	cin >> liczbaPolecen;
	int dlugosc = 0;
	bool dodawanie = false;
	for (int i = 0; i < liczbaPolecen;i++) {
		tekst = (char*)malloc(3002 * sizeof(char));
		cin >> polecenie;
		switch (polecenie[0]) {
		case 'a': //dodawanie aD tekst
			cin >> tekst;
			add(polecenie[1], tekst);
			break;
		case 'd': //usuniecie dè
			del(polecenie[1]);
			break;
		case 'c': //powielanie cèD
			powiel(polecenie[1], polecenie[2]);
			break;
		case 'm': //przenoszenie mèD
			przenies(polecenie[1], polecenie[2]);
			break;
		case 'j': //≥πczenie jèD
			polacz(polecenie[1], polecenie[2]);
			break;
		case 's': //wyswietlanie sè
			wyswietl(polecenie[1]);
			break;
		}
	}
	return 0;
}