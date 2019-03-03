#include <iostream>
#include "bstree.h"

using namespace std;

int main()
{
	bstree bst;
	int x = 8;
	//Adding
	bst.insert(5);
	bst.insert(3);
	bst.insert(7);
	bst.insert(10);
	x + bst;
	cin >> bst>>bst>>bst;

	bst.remove_node(23);
	bst.inorder();
	cout << endl;
	bst.leaves();
	cout << endl;
	cout << bst.depth();

	return 0;
}
