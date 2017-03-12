#include "elementStosu.h"
#include <iostream>
using namespace std;


ElementStosu::ElementStosu(char *napis) {
	this->wyraz = napis;
	this->poprzedni = NULL;
}

ElementStosu::ElementStosu(ElementStosu *poprzedni, char *napis) {
	this->wyraz = napis;
	this->poprzedni = poprzedni;
}

