#pragma once
#include <iostream>
using namespace std;


class ElementKolejki
{
public:
	ElementKolejki *nastepny;
	char *wyraz;

	ElementKolejki(char *napis);
	ElementKolejki(ElementKolejki *nastepny, char *napis);


};