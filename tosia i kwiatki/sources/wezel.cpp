#pragma once
#include "Wezel.h"
#include <iostream>
using namespace std;




Wezel::Wezel(int nr, int ruchy) {
	this->kwiaty = 0;
	this->nr = nr;
	this->lewy = nullptr;
	this->prawy = nullptr;
	this->rodzic = nullptr;
	this->tab[1] = nullptr;
	this->tab[2] = nullptr;
	this->tab[0] = nullptr;
	this->tabKwiaty[1] = 0;
	this->tabKwiaty[2] = 0;
	this->tabKwiaty[0] = 0;
	this->wynikiLewy = new int[ruchy];
	this->wynikiPrawy = new int[ruchy];
	for (int i = 0;i < ruchy;i++) {
		this->wynikiLewy[i] = 0;
		this->wynikiPrawy[i] = 0;
	}
}

Wezel::Wezel() {
	int kwiaty = 0;
	this->nr = 0;
	this->prawy = nullptr;
	this->rodzic = nullptr;
	this->tab[1] = nullptr;
	this->tab[2] = nullptr;
	this->tab[0] = nullptr;
	this->wynikiLewy = nullptr;
	this->wynikiPrawy = nullptr;
	this->tabKwiaty[1] = 0;
	this->tabKwiaty[2] = 0;
	this->tabKwiaty[0] = 0;
}

void Wezel::budujDrzewo(Wezel *parent) {
	this->rodzic = parent;
	if (this->tab[0] == parent) {
		this->kwiaty = this->tabKwiaty[0];
		this->lewy = tab[1];
		this->prawy = tab[2];
	}
	else if (this->tab[1] == parent) {
		this->kwiaty = this->tabKwiaty[1];
		this->lewy = tab[0];
		this->prawy = tab[2];
	}
	else if (this->tab[2] == parent) {
		this->kwiaty = this->tabKwiaty[2];
		this->lewy = tab[0];
		this->prawy = tab[1];
	}
	if (this->lewy != nullptr) {
		this->lewy->budujDrzewo(this);
	}
	if (this->prawy != nullptr) {
		this->prawy->budujDrzewo(this);
	}
	return;
}


void Wezel::dodajWezel(Wezel *x, int kwiaty) {
	if (this->tab[0] == nullptr) {
		this->tab[0] = x;
		this->tabKwiaty[0] = kwiaty;
	}
	else if (this->tab[1] == nullptr) {
		this->tab[1] = x;
		this->tabKwiaty[1] = kwiaty;
	}
	else if (this->tab[2] == nullptr) {
		this->tab[2] = x;
		this->tabKwiaty[2] = kwiaty;
	}
}


int Wezel::szukaj(int ruchy) {
      if (ruchy == 0) {
              return this->kwiaty;
      }
      else if (this->lewy == nullptr || this->prawy == nullptr) {
              if (this->lewy != nullptr) {
                      return this->lewy->szukaj(ruchy - 1) + this->kwiaty;
              }
              else if (this->prawy != nullptr) {
                      return this->prawy->szukaj(ruchy - 1) + this->kwiaty;
              }
      }
	  else if (this->lewy == nullptr && this->prawy == nullptr) {
		  return this->kwiaty;
	  }
      else if(this->lewy != nullptr && this->prawy != nullptr) {
              int max = 0;
              for (int i = ruchy, j = 0;j <= ruchy && i >= 0;i--, j++) {
                              int suma = 0;
                              if (i > 0) {
                                      if (this->wynikiLewy[i-1] != 0) {
                                              suma += this->wynikiLewy[i-1];
                                      }
                                      else {
                                              this->wynikiLewy[i-1] = this->lewy->szukaj(i-1);
                                              suma += this->wynikiLewy[i-1];
                                      }
                              }
                              if (j > 0) {
                                      if (this->wynikiPrawy[j-1] != 0) {
                                              suma += this->wynikiPrawy[j-1];
                                      }
                                      else  {
                                              this->wynikiPrawy[j-1] = this->prawy->szukaj(j-1);
                                              suma += this->wynikiPrawy[j-1];
                                      }
                              }
                              if (suma > max) {
                                      max = suma;
                              }
              }
              return max + this->kwiaty;
      }
      else {
              return this->kwiaty;
      }
      return 0;
}




//Wezel::~Wezel() {
//delete this->rodzic;
//delete this->lewy;
//delete this->prawy;
//}