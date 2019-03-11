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

void bstree::insert(int x)
{
	if (root == NULL)
	{
		root = new (nothrow) node{ x,NULL};
		if (root == NULL)
			exit(-1);
		return;
	}

	node *n = root;

	while (true)
	{
		if (x > n->data&&n->right != NULL)
		{
			n = n->right;
		}
		else if (x > n->data)
		{
			node *add = new node{ x, n};
			n->right = add;
			return;
		}
		else if (x <= n->data&&n->left != NULL)
		{
			n = n->left;
		}
		else if (x <= n->data)
		{
			node *add = new node{ x, n};
			n->left = add;
			return;
		}
	}
	return;
}

void bstree::inorder(ostream & os) const
{
	priv_printSRD(root, os);
}

void bstree::inorder() const
{
	priv_printSRD(root, cout);
}

void bstree::remove_node(int x)
{
	priv_remove_node(root, x);
}

void bstree::leaves(void)
{
	priv_leaves(root);
}

int bstree::depth(void)
{
	return priv_depth(root, 1);
}

void bstree::priv_insert(node * n, int x)
{
}

void bstree::priv_printSRD(const node * n, ostream & os) const
{
	if (n == NULL)
		return;
	priv_printSRD(n->left, os);
	os << n->data << " ";
	priv_printSRD(n->right, os);
}

void bstree::priv_leaves(node * n)
{
	if (n == NULL)
		return;

	if (n->left == NULL && n->right == NULL)
		cout << n->data << " ";
	else
	{
		priv_leaves(n->left);
		priv_leaves(n->right);
	}
}

int bstree::priv_depth(node * n, int level)
{
	int s, d;
	s = d = level;
	if (n->right != NULL)
		d = priv_depth(n->right, level + 1);
	if (n->left != NULL)
		s = priv_depth(n->left, level + 1);
	return s < d ? d : s;
}

void bstree::priv_remove_node(node * n, int x)
{
	//The node with value x is not in the BST
	if (n == NULL)
		return;

	//Found the node
	if (n->data == x)
	{
		//The node has at most one child
		if (n->left == NULL || n->right == NULL)
		{
			//The node has no children
			if (n->left == NULL && n->right == NULL)
			{
				//The node is the last one in the BST
				if (n == root)
				{
					root = NULL;
					delete n;
					return;
				}
				//Break the node from its father
				if (n->father->data < n->data)
					n->father->right = NULL;
				else
					n->father->left = NULL;
				//Free the memory
				delete n;
				return;
			}

			//The node has one child
			//Link the father of the node to the child
			if (n->data < n->father->data)
				n->father->left = (n->left == NULL) ? n->right : n->left;
			else
				n->father->right = (n->left == NULL) ? n->right : n->left;
			//Free memory
			delete n;
			return;
		}

		//The node has both children
		//Find the minimal node greather than this
		node *aux = n->right;
		while (aux->left != NULL)
			aux = aux->left;
		//Set the found node in place of the removed one
		n->data = aux->data;
		//Remove the found node
		priv_remove_node(aux, aux->data);
		return;
	}

	//Search for the node
	if (n->data < x)
		priv_remove_node(n->right, x);
	else
		priv_remove_node(n->left, x);
}

void bstree::priv_destructor(node * n)
{
	if (n == NULL)
		return;
	priv_destructor(n->left);
	priv_destructor(n->right);
	delete n;
}

void operator+(int x, bstree & bst)
{
	bst.insert(x);
}

ostream & operator<< (ostream &os,const bstree &a)
{
	a.inorder(os);
	return os;
}

std::istream & operator>>(std::istream & is, bstree &bst)
{
	int x;
	if (is >> x)
		bst.insert(x);
	
	return is;
}
