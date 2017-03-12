#include <iostream>
using namespace std;




int symbolNewtona(int n) {
	return n*(n - 1) / 2;
}


int mnozeniemac(int **A, int **B, int **C,int rozmiar) {
	int i, j, k;
	for (i = 0; i < rozmiar; i++)
		for (j = 0; j < rozmiar; j++)
			C[i][j] = 0;
	for (i = 0; i < rozmiar; i++)
		for (j = 0; j < rozmiar; j++)
			for (k = 0; k < rozmiar; k++)
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
	return 0;
}

int main() {
	
	int liczba;
	cin >> liczba;
	for (int x = 0;x < liczba;x++) {
		int rozmiar;
		cin >> rozmiar;
		int **tab = new int*[rozmiar];
		for (int i = 0;i < rozmiar;i++) {
			tab[i] = new int[rozmiar];
		}
		int **tab2 = new int*[rozmiar];
		for (int i = 0;i < rozmiar;i++) {
			tab2[i] = new int[rozmiar];
		}
		for (int i = 0;i < rozmiar;i++) {
			for (int j = 0;j < rozmiar;j++) {
				cin >> tab[i][j];
			}
		}
		mnozeniemac(tab, tab, tab2, rozmiar);
		int suma = 0;
		for (int i = 0;i < rozmiar - 1;i++) {
			for (int j = i + 1;j < rozmiar;j++) {
				suma += symbolNewtona(tab2[i][j]);
			}
		}

		suma = suma / 2;
		cout << suma << endl;
	}

	return 0;
}