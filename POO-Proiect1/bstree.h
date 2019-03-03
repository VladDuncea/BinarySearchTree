#pragma once
#include "node.h"
#include <iostream>

class bstree
{
	node *root;

	void priv_insert(node *n, int x);
	void priv_printSRD(node *n, std::ostream &os);
	void priv_leaves(node *n);
	int priv_depth(node *n, int level);
	void priv_remove_node(node *n, int x);
	void priv_destructor(node *n);

public:

	bstree();
	~bstree();

	void insert(int);

	void inorder(std::ostream &);

	void inorder();

	void remove_node(int);

	void leaves(void);

	int depth(void);

	friend void operator+ (int x,bstree &bst);
	friend std::ostream & operator<< (std::ostream &, bstree &);
	friend std::istream & operator>> (std::istream &, bstree &);
};


