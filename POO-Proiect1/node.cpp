#include "node.h"



node::node()
{
	left = right = NULL;
}


node::node(int x,node *father)
{
	left = right = NULL;
	this->father = father;
	data = x;
}
