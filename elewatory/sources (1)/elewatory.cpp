#include "Elewatory.h"
#include <iostream>
#include <string>
using namespace std;

Elewatory::Elewatory(int liczba, int *start) {
	liczbaElewatorow = liczba;
	elewatory = new Elewator*[liczba];
	heapMAX = new element*[liczba];
	heapMIN = new element*[liczba];

	for (int i = 0;i < liczba;i++) {
		elewatory[i] = new Elewator(start[i], i);
		heapMAX[i] = new element;
		heapMIN[i] = new element;
		elewatory[i]->numerMAX = i;
		elewatory[i]->numerMIN = i;
		elewatory[i]->numer = i;
		heapMAX[i]->elewator = elewatory[i];
		heapMIN[i]->elewator = elewatory[i];
	}

	stworzKopiec(1);
	stworzKopiec(0);
	znajdzMAX();
	znajdzMIN();
}

void Elewatory::znajdzMAX() {

	max = heapMAX[0]->elewator;

}

void Elewatory::znajdzMIN() {
	min = heapMIN[0]->elewator;
}

void Elewatory::heapify(int i, int czyMAX) {
	if (czyMAX == 1) {
		int najwiekszy;
		int l = lewy(i);
		int r = prawy(i);


		if (l < liczbaElewatorow) {
			if (heapMAX[l]->elewator->zboze > heapMAX[i]->elewator->zboze) {
				najwiekszy = l;
			}
			else if (heapMAX[l]->elewator->zboze == heapMAX[i]->elewator->zboze
				&& heapMAX[l]->elewator->numer < heapMAX[i]->elewator->numer) {
				najwiekszy = l;
			}
			else najwiekszy = i;
		}
		else najwiekszy = i;

		if (r < liczbaElewatorow) {
			if (heapMAX[r]->elewator->zboze > heapMAX[najwiekszy]->elewator->zboze) {
				najwiekszy = r;
			}
			else if (heapMAX[r]->elewator->zboze == heapMAX[najwiekszy]->elewator->zboze
				&& heapMAX[r]->elewator->numer < heapMAX[najwiekszy]->elewator->numer) {
				najwiekszy = r;
			}
		}

		if (najwiekszy != i) {
			zamien(i, najwiekszy, 1);
			heapify(najwiekszy, 1);
		}
	}
	if (czyMAX == 0) {
		int najmniejszy;
		int l = lewy(i);
		int r = prawy(i);

		if (l < liczbaElewatorow) {
			if (heapMIN[i]->elewator->zwrot() > heapMIN[l]->elewator->zwrot()) {
				najmniejszy = l;
			}
			else if (heapMIN[l]->elewator->zwrot() == heapMIN[i]->elewator->zwrot()
				&& heapMIN[l]->elewator->numer < heapMIN[i]->elewator->numer) {
				najmniejszy = l;
			}
			else najmniejszy = i;
		}
		else najmniejszy = i;

		if (r < liczbaElewatorow) {
			if (heapMIN[najmniejszy]->elewator->zwrot() > heapMIN[r]->elewator->zwrot()) {
				najmniejszy = r;
			}
			else if (heapMIN[r]->elewator->zwrot() == heapMIN[najmniejszy]->elewator->zwrot()
				&& heapMIN[r]->elewator->numer < heapMIN[najmniejszy]->elewator->numer) {
				najmniejszy = r;
			}
		}

		if (najmniejszy != i) {
			zamien(i, najmniejszy, 0);
			heapify(najmniejszy, 0);
		}
	}
}

void Elewatory::gora(int i, int czyMAX) {
	if (czyMAX == 1) {
		if (i > 0) {
			int par = rodzic(i);

			if (heapMAX[i]->elewator->zboze > heapMAX[par]->elewator->zboze) {
				zamien(i, par, 1);
				gora(par, 1);
			}
			else if (heapMAX[i]->elewator->zboze == heapMAX[par]->elewator->zboze
				&& heapMAX[i]->elewator->numer < heapMAX[par]->elewator->numer) {
				zamien(i, par, 1);
				gora(par, 1);
			}
		}
	}
	if (czyMAX == 0) {
		if (heapMIN[i]->elewator->zboze == 0) {
			heapify(i, 0);
			return;
		}


		if (i > 0) {
			int par = rodzic(i);

			if (heapMIN[i]->elewator->zwrot() < heapMIN[par]->elewator->zwrot()) {
				zamien(i, par, 0);
				gora(par, 0);
			}
			else if (heapMIN[i]->elewator->zwrot() == heapMIN[par]->elewator->zwrot()
				&& heapMIN[i]->elewator->numer < heapMIN[par]->elewator->numer) {
				zamien(i, par, 0);
				gora(par, 0);
			}
		}
	}
}

void Elewatory::zamien(int a, int b, int czyMAX) {
	if (czyMAX == 1) {
		element *temp = heapMAX[a];
		int tmp1 = heapMAX[a]->elewator->numerMAX;
		int tmp2 = heapMAX[b]->elewator->numerMAX;
		heapMAX[a] = heapMAX[b];
		heapMAX[b] = temp;
		heapMAX[b]->elewator->numerMAX = tmp2;
		heapMAX[a]->elewator->numerMAX = tmp1;
	}
	if (czyMAX == 0) {
		element *temp = heapMIN[a];
		int tmp1 = heapMIN[a]->elewator->numerMIN;
		int tmp2 = heapMIN[b]->elewator->numerMIN;
		heapMIN[a] = heapMIN[b];
		heapMIN[b] = temp;
		heapMIN[b]->elewator->numerMIN = tmp2;
		heapMIN[a]->elewator->numerMIN = tmp1;
	}
}

void Elewatory::stworzKopiec(int czyMAX) {
	if (czyMAX == 1) {
		for (int i = (liczbaElewatorow + 1) / 2;i >= 0;i--) {
			heapify(i, 1);
		}
	}
	if (czyMAX == 0) {
		for (int i = (liczbaElewatorow + 1) / 2;i >= 0;i--) {
			heapify(i, 0);
		}
	}
}

void Elewatory::polecenia() {
	int masa;
	int nr;
	string polecenie;
	cin >> polecenie;

	if (polecenie == "nm") {
		cin >> masa;
		min->dodajZboze(masa);
		gora(min->numerMAX, 1);
		heapify(min->numerMIN, 0);
		gora(min->numerMIN, 0);
		znajdzMIN();
		znajdzMAX();
	}
	else if (polecenie == "nM") {
		cin >> masa;
		max->dodajZboze(masa);
		gora(max->numerMAX, 1);
		heapify(max->numerMIN, 0);
		gora(max->numerMIN, 0);
		znajdzMIN();
		znajdzMAX();
	}
	else if (polecenie == "n") {
		cin >> nr;
		cin >> masa;
		elewatory[nr]->dodajZboze(masa);
		gora(elewatory[nr]->numerMAX, 1);
		heapify(elewatory[nr]->numerMIN, 0);
		gora(elewatory[nr]->numerMIN, 0);
		znajdzMIN();
		znajdzMAX();
	}
	else if (polecenie == "rm") {
		cin >> masa;
		min->zabierzZboze(masa);
		heapify(min->numerMAX, 1);
		gora(min->numerMIN, 0);
		znajdzMIN();
		znajdzMAX();
	}
	else if (polecenie == "rM") {
		cin >> masa;
		max->zabierzZboze(masa);
		heapify(max->numerMAX, 1);
		gora(max->numerMIN, 0);
		znajdzMIN();
		znajdzMAX();
	}
	else if (polecenie == "r") {
		cin >> nr;
		cin >> masa;
		elewatory[nr]->zabierzZboze(masa);
		heapify(elewatory[nr]->numerMAX, 1);
		gora(elewatory[nr]->numerMIN, 0);
		znajdzMIN();
		znajdzMAX();
	}
	else if (polecenie == "wm") {
		cout << min->zboze << endl;
	}
	else if (polecenie == "wM") {
		cout << max->zboze << endl;
	}
	else if (polecenie == "w") {
		cin >> nr;
		cout << elewatory[nr]->zboze << endl;
	}
}