#include <iostream>
using namespace std;
void palindrom(int liczba, char* tablica, int x) {
	char binarne[] = { '1','0' };
	int k = 0;
	do {
		tablica[x] = tablica[liczba - x - 1] = binarne[k];
		k++;
		if ((liczba % 2 == 0 && x == liczba / 2 - 1) || (liczba % 2 == 1 && x == liczba / 2)) {
			cout << tablica;
		}
		else palindrom(liczba, tablica,x+1);
	} while (k < 2);
}

int main() {
	int liczba= 0;
	char *test;
	for (int j = 0; j < 50;j++) {
		cin >> liczba;
		test = new char[liczba + 1];
		for (int i = 0;i < liczba;i++)
			test[i] = '1';
		test[liczba] = '\0';
		palindrom(liczba,test, 0);
		delete[] test;
		cout << endl;
	}
	return 0;
}