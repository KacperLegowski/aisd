#include <iostream>
int ilosc;
int c;
int wynik;
void f(bool *tab, int i, int *ceny, int *wagi) {
	if (i == ilosc) {
		int suma_cen = 0;
		int suma_wag = 0;
		for (int j = 0; j < ilosc; j++) {
			if (tab[j] == true) {
				suma_cen += ceny[j];
				suma_wag += wagi[j];
			}
		}
		if (suma_wag <= c && suma_cen > wynik) {
			wynik = suma_cen;
		}
	}
	else {
		tab[i] = true;
		f(tab, i + 1, ceny, wagi);
		tab[i] = false;
		f(tab,i + 1, ceny, wagi);
	}
}
int main()
{
	for (int a = 0; a < 500; a++) {
		scanf("%i", &ilosc);
		int *ceny = new int[ilosc];
		int *wagi = new int[ilosc];
		for (int i = 0; i < ilosc; i++) {
			scanf("%i", &ceny[i]);
		}
		for (int i = 0; i < ilosc; i++) {
			scanf("%i", &wagi[i]);
		}
		wynik = 0;
		scanf("%i", &c);
		bool *tab = new bool[ilosc];
		f(tab, 0, ceny, wagi);
		printf("%i \n", wynik);
	}
	return 0;
}