#pragma once
#include <iostream>

class node
{
	int data;
	node * left, *right, *father;
	friend class bstree;

public:
	node();

	node(int x,node *father);
};
