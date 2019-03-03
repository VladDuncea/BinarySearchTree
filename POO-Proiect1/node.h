#pragma once
#include <iostream>

class node
{
	int data;
	node * stanga, *dreapta, *father;
	friend class bstree;

public:
	node();

	node(int x);
};
