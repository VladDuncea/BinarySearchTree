#include <iostream>

using namespace std;


class nod
{
	int data;
	nod * stanga,* dreapta;
	friend class arborebinarcautare;

public:
	nod()
	{
		stanga = dreapta = NULL;
	}

	nod(int x)
	{
		stanga = dreapta = NULL;
		data = x;
	}
};


class arborebinarcautare
{
	
	nod *root;

	void priv_adaugare(nod *n, int x)
	{

	}

	void priv_afisare(nod *n,ostream &os)
	{
		if (n == NULL)
			return;
		priv_afisare(n->stanga,os);
		os << n->data<<" ";
		priv_afisare(n->dreapta,os);
	}

public:

	arborebinarcautare()
	{
		root = NULL;
	}

	void adaugare(int x)
	{
		if (root == NULL)
		{
			root = new nod { x };
			if (root == NULL)
				exit(-1);
			return;
		}

		nod *n = root;

		while (true)
		{
			if (x > n->data&&n->dreapta != NULL)
			{
				n = n->dreapta;
			}
			else if (x > n->data)
			{
				nod *add = new nod{ x };
				n->dreapta = add;
				return;
			}
			else if (x <= n->data&&n->stanga != NULL)
			{
				n = n->stanga;
			}
			else if (x <= n->data)
			{
				nod *add = new nod{ x };
				n->stanga = add;
				return;
			}
		}
		return;
	}

	void afisare(ostream &os)
	{
		priv_afisare(root,os);
	}

	void afisare()
	{
		priv_afisare(root, cout);
	}

	void  
};


ostream & operator<< (ostream &os,arborebinarcautare a)
{
	a.afisare();
	return os;
}

int main()
{
	arborebinarcautare a;
	//cout << a;
	a.adaugare(5);
	a.adaugare(3);
	a.adaugare(7);
	a.adaugare(10);
	a.adaugare(8);
	a.afisare();

	cout << a<<a;
	return 0;
}