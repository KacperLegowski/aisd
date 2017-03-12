#pragma once
#include <iostream>
#include <string>

class Elewator {
public:
	int zboze;
	int numer;
	int numerMAX;
	int numerMIN;

	Elewator(int masa, int numer) {
		zboze = masa;
	}
	void dodajZboze(int masa) {
		zboze += masa;
	}
	void zabierzZboze(int masa) {
		if ((zboze - masa) < 0) {
			zboze = 0;
			return;
		}
		else {
			zboze -= masa;
		}
	}

	int zwrot(){
		if (this->zboze == 0) {
			return 2000000001;
		}
		else {
			return this->zboze;
		}
	}
};