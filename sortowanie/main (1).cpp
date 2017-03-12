#include <iostream>
#include <string>
using namespace std;


void wstawianie(long long tab[], int ct)
{
	for (int i = 1; i < ct; i++)
	{
		int k = i;
		while (tab[k] < tab[k - 1] && k > 0)
		{
			swap(tab[k], tab[k - 1]);
			k--;
		}
	}
}

void wybieranie(long long tab[], int ct) {
	long long minimumIndex;
	for (int i = 0; i < ct; i++) {
		minimumIndex = i;
		for (int k = i + 1;k < ct;k++) {
			if (tab[k] < tab[minimumIndex]) {
				minimumIndex = k;
				swap(tab[i], tab[minimumIndex]);
			}
		}
	}
}

long long * scal(long long tab1[], long long tab2[], int l1, int l2)
{
	long long * tabS = new long long[l1 + l2];
	int i = 0, j = 0, k = 0;
	while (j < l1 || k < l2)
	{
		if (j < l1 && k < l2)
		{
			if (tab1[j] <= tab2[k])
			{
				tabS[i] = tab1[j];
				j++;
				i++;
			}
			else
			{
				tabS[i] = tab2[k];
				k++;
				i++;
			}
		}
		else if (j < l1 && k >= l2)
		{
			tabS[i] = tab1[j];
			j++;
			i++;
		}
		else
		{
			tabS[i] = tab2[k];
			k++;
			i++;
		}
	}
	return tabS;
}

int main() {
	long long *tablica;
	long long *temp1;
	long long *temp2;
	int length;
	int iter1 = 0, iter2 = 0;
	cin >> length;
	tablica = new long long[length];
	temp1 = new long long[length / 2];
	temp2 = new long long[length / 2];


	for (int i = 0;i < length; i++) {
		if (i % 2 == 0) {
			cin >> temp1[iter1];
			iter1++;
		}
		else {
			cin >> temp2[iter2];
			iter2++;
		}
	}
	wybieranie(temp1, iter1);
	for (int x = 0; x < iter1; x++) {
		cout << temp1[x] << endl;
	}
	wstawianie(temp2, iter2);
	for (int y = 0; y < iter2; y++) {
		cout << temp2[y] << endl;
	}
	tablica = scal(temp1, temp2, iter1, iter2);
	for (int g = 0;g < length;g++) {
		cout << tablica[g] << endl;
	}
	return 0;
}