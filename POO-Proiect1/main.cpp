#include <iostream>
#include "bstree.h"

using namespace std;

int main()
{
	bstree a;
	int x = 8;
	//cout << a;
	a.adaugare(5);
	a.adaugare(3);
	a.adaugare(7);
	a.adaugare(10);
	x + a;
	cin >> a;
	a.afisareSRD();
	cout << endl;
	a.afisare_frunze();
	cout << endl;
	cout << a.adancime();

	return 0;
}
