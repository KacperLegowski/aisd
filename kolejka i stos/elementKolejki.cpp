#include "elementKolejki.h"
#include <iostream>
using namespace std;


ElementKolejki::ElementKolejki(char *napis) {
	this->wyraz = napis;
	this->nastepny = NULL;
}

ElementKolejki::ElementKolejki(ElementKolejki *nastepny, char *napis) {
	this->wyraz = napis;
	this->nastepny = nastepny;
}

