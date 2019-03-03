#include "bstree.h"

using namespace std;

bstree::bstree()
{
	root = NULL;
}

bstree::~bstree()
{
	priv_destructor(root);
}

void bstree::adaugare(int x)
{
	if (root == NULL)
	{
		root = new node{ x };
		if (root == NULL)
			exit(-1);
		return;
	}

	node *n = root;

	while (true)
	{
		if (x > n->data&&n->dreapta != NULL)
		{
			n = n->dreapta;
		}
		else if (x > n->data)
		{
			node *add = new node{ x };
			n->dreapta = add;
			return;
		}
		else if (x <= n->data&&n->stanga != NULL)
		{
			n = n->stanga;
		}
		else if (x <= n->data)
		{
			node *add = new node{ x };
			n->stanga = add;
			return;
		}
	}
	return;
}


void bstree::afisareSRD(ostream & os)
{
	priv_afisareSRD(root, os);
}

void bstree::afisareSRD()
{
	priv_afisareSRD(root, cout);
}

void bstree::stergere(int x)
{
	priv_stergere(root, x);
}

void bstree::afisare_frunze(void)
{
	priv_afisare_frunze(root);
}

int bstree::adancime(void)
{
	return priv_adancime(root, 1);
}

void bstree::priv_adaugare(node * n, int x)
{
}

void bstree::priv_afisareSRD(node * n, ostream & os)
{
	if (n == NULL)
		return;
	priv_afisareSRD(n->stanga, os);
	os << n->data << " ";
	priv_afisareSRD(n->dreapta, os);
}

void bstree::priv_afisare_frunze(node * n)
{
	if (n == NULL)
		return;

	if (n->stanga == NULL && n->dreapta == NULL)
		cout << n->data << " ";
	else
	{
		priv_afisare_frunze(n->stanga);
		priv_afisare_frunze(n->dreapta);
	}
}

int bstree::priv_adancime(node * n, int level)
{
	int s, d;
	s = d = level;
	if (n->dreapta != NULL)
		d = priv_adancime(n->dreapta, level + 1);
	if (n->stanga != NULL)
		s = priv_adancime(n->stanga, level + 1);
	return s < d ? d : s;
}

void bstree::priv_stergere(node * n, int x)
{

	if (n == NULL)
		return;

	if (n->data == x)
	{
		if (n->stanga == NULL || n->dreapta == NULL)
		{
			if (n->stanga == NULL && n->dreapta == NULL)
			{
				if (n->father->data < n->data)
					n->father->dreapta = NULL;
				else
					n->father->stanga = NULL;
				delete n;
				return;
			}

			if (n->data < n->father->data)
				n->father->stanga = (n->stanga == NULL) ? n->dreapta : n->stanga;
			else
				n->father->dreapta = (n->stanga == NULL) ? n->dreapta : n->stanga;

			delete n;
			return;
		}

		//The node has both children
		node *aux = n->dreapta;
		while (aux->stanga != NULL)
			aux = aux->stanga;

	}

	if (n->data < x)
		priv_stergere(n->dreapta, x);
	else
		priv_stergere(n->stanga, x);
}

void bstree::priv_destructor(node * n)
{
	if (n == NULL)
		return;
	priv_destructor(n->stanga);
	priv_destructor(n->dreapta);
	delete n;
}

void operator+(int x, bstree & bst)
{
	bst.adaugare(x);
}

ostream & operator<< (ostream &os, bstree &a)
{
	a.afisareSRD(os);
	return os;
}

std::istream & operator>>(std::istream & is, bstree &bst)
{
	int x;
	if (is >> x)
		bst.adaugare(x);
	
	return is;
}
