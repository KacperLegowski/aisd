
#pragma once

class Wezel {
public:
	int kwiaty;
	int nr;
	int *wynikiLewy;
	int *wynikiPrawy;
	int tabKwiaty[3];
	Wezel *lewy;
	Wezel *prawy;
	Wezel *rodzic;
	Wezel *tab[3];


	Wezel();
	Wezel(int nr, int ruchy);
	//~Wezel();
	void budujDrzewo(Wezel* rodzic);
	void dodajWezel(Wezel *x, int kwiaty);
	int szukaj(int ruchy);
};
