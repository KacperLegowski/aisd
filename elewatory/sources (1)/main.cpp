#include<iostream>
#include<string>
#include"Elewatory.h"

using namespace std;


int main() {

	int liczbaElewatorow, liczbaPolecen, *tab;

	cin >> liczbaElewatorow;
	cin>> liczbaPolecen;
	tab = new int[liczbaElewatorow];
	for (int i = 0;i < liczbaElewatorow;i++) {
		cin >> tab[i];
	}
	Elewatory elewatory(liczbaElewatorow, tab);
	for (int i = 0;i < liczbaPolecen;i++) {
		elewatory.polecenia();
	}



	return 0;
}

