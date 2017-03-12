#include <iostream>

using namespace std;

int tab[100][100];


int main()
{
	for (int test = 0; test < 20; test++)
	{
		int rozmiar, licznik = 0, odp = 1;
		cin >> rozmiar;
		char *macierz = new char[rozmiar*rozmiar];
		cin >> macierz;

		
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar; j++)
			{
				tab[i][j] = 0;
				if (macierz[licznik++] == '1') {
					tab[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar; j++)
			{
				for (int k = 0; k < rozmiar; k++)
				{
					for (int l = 0; l < rozmiar; l++)
					{
						if (tab[i][j] == 1 && tab[k][j] == 1 && tab[l][j] == 1 && tab[l][k] == 0 && tab[i][k] == 0 && tab[l][i] == 0 && i != j && i != k && i != l && j != k && j != l && l != k)
							odp = 0;
						}
					}
				}
			}
	if(odp == 0)
		cout << '0' << endl;
	else
		cout << '1' << endl;
	}

	return 0;
}