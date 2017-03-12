#pragma once
#include"Elewator.h"

struct element {
	Elewator *elewator;
};

class Elewatory {
public:
	Elewator **elewatory;
	Elewator *max;
	Elewator *min;

	element **heapMAX;
	element **heapMIN;

	int liczbaElewatorow;

	Elewatory(int liczba, int *start);

	

	int rodzic(int index) {
		return (index - 1) / 2;
	}
	int lewy(int index) {
		return 2 * index + 1;
	}
	int prawy(int index) {
		return 2 * index + 2;
	}
	void znajdzMAX();
	void znajdzMIN();
	void heapify(int i, int czyMAX);
	void gora(int i, int czyMAX);
	void stworzKopiec(int czyMAX);
	void zamien(int a, int b, int czyMAX);
	void polecenia();
};