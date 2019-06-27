#include <iostream>
#include "Tree.h"

using namespace std;


void main()
{
	Tree <int> t;
	cout << "Inserting nodes.\n";
	t.Insert(5);	
	t.Insert(8);	
	t.Insert(3);	
	t.Insert(12);	
	t.Insert(9);

	cout << "Inorder traversal:\n";	
	t.Inorder();	
	cout << "\nPreorder traversal:\n";	
	t.Post();	
	cout << "\nPostorder traversal:\n";	
	t.Pre();

}