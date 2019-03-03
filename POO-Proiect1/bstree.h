#pragma once
#include "node.h"
#include <iostream>

class bstree
{
	node *root;

	void priv_adaugare(node *n, int x);
	void priv_afisareSRD(node *n, std::ostream &os);
	void priv_afisare_frunze(node *n);
	int priv_adancime(node *n, int level);
	void priv_stergere(node *n, int x);
	void priv_destructor(node *n);

public:

	bstree();
	~bstree();

	void adaugare(int);

	void afisareSRD(std::ostream &);

	void afisareSRD();

	void stergere(int);

	void afisare_frunze(void);

	int adancime(void);

	friend void operator+ (int x,bstree &bst);
	friend std::ostream & operator<< (std::ostream &, bstree &);
	friend std::istream & operator>> (std::istream &, bstree &);
};


