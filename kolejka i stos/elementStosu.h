#pragma once
#include <iostream>
using namespace std;

class ElementStosu {
public:
	ElementStosu *poprzedni;
	char *wyraz;

	ElementStosu(char *napis);
	ElementStosu(ElementStosu *poprzedni, char *napis);
};