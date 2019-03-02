#include <iostream>

using namespace std;


class nod
{
	int data;
	nod * stanga,* dreapta,*father;
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

	void priv_afisareSRD(nod *n,ostream &os)
	{
		if (n == NULL)
			return;
		priv_afisareSRD(n->stanga,os);
		os << n->data<<" ";
		priv_afisareSRD(n->dreapta,os);
	}

	void priv_afisare_frunze(nod *n);
	int priv_adancime(nod *n,int level);
	void priv_stergere(nod *n,int x);

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

	void afisareSRD(ostream &os)
	{
		priv_afisareSRD(root,os);
	}

	void afisareSRD()
	{
		priv_afisareSRD(root, cout);
	}

	void stergere(int x);

	void afisare_frunze(void);

	int adancime(void);
};


ostream & operator<< (ostream &os,arborebinarcautare a)
{
	a.afisareSRD(os);
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
	a.afisareSRD();
	cout << endl;
	a.afisare_frunze();
	cout << endl;
	cout << a.adancime();

	return 0;
}

void arborebinarcautare::priv_afisare_frunze(nod * n)
{
	if (n == NULL)
		return;

	if (n->stanga == NULL && n->dreapta == NULL)
		cout << n->data<<" ";
	else
	{
		priv_afisare_frunze(n->stanga);
		priv_afisare_frunze(n->dreapta);
	}
}

int arborebinarcautare::priv_adancime(nod * n,int level)
{
	int s,d;
	s = d = level;
	if (n->dreapta != NULL)
		d = priv_adancime(n->dreapta, level + 1);
	if (n->stanga != NULL)
		s = priv_adancime(n->stanga, level + 1);
	return s < d ? d : s;
}

void arborebinarcautare::priv_stergere(nod * n,int x)
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
		nod *aux=n->dreapta;
		while (aux->stanga != NULL)
			aux = aux->stanga;

	}
	
	if (n->data < x)
		priv_stergere(n->dreapta, x);
	else
		priv_stergere(n->stanga, x);
		
}

void arborebinarcautare::stergere(int x)
{
	priv_stergere(root,x);
}

void arborebinarcautare::afisare_frunze(void)
{
	priv_afisare_frunze(root);
}

int arborebinarcautare::adancime(void)
{
	return priv_adancime(root,1);
}
