#include <iostream>
#include <fstream>
#include <list>
#include "AdjacencyList.h"
#include "Stack.h"

using namespace std;

AdjacencyList::AdjacencyList()
{
	L = new node*[0];
	vect = 0;
};

void AdjacencyList::Input()
{
	char comastore;						//Used for storing temporary charcter while reading. Mostly comma
	ifstream Read("graph.txt");
	Read >> weighted;
	Read >> vect;
	L = new node *[vect];
	Stack <int> pat(vect);
	path = pat;							//Path will contain some garbage values
	for (int i = 0; i < vect; i++)									//Reading function
	{
		node *curr = new node;
		Read >> curr->data;
		curr->next = nullptr;
		Read >> comastore;

		if (weighted)
		{
			Read >> curr->weight;
			Read >> comastore;
		}
		else
			curr->weight = 1;				//Making weight of each node equal

		L[i] = curr;
		while (comastore != ';')
		{
			node *temp = new node;
			Read >> temp->data;
			temp->next = nullptr;
			Read >> comastore;

			if (weighted)
			{
				Read >> temp->weight;
				Read >> comastore;
			}
			else
				temp->weight = 1;

			curr->next = temp;
			curr = temp;
		}

	}

};

void AdjacencyList::Output()
{
	for (int i = 0; i < vect; i++)
	{
		node* curr;
		cout << "Vector = " << L[i]->data << ";" << " Nodes = ";
		curr = L[i]->next;
		while (curr != nullptr)
		{
			cout << curr->data;
			if (weighted)
				cout << " W-" << curr->weight;
			if (curr->next != nullptr)
				cout << ", ";
			curr = curr->next;
		}
		cout << endl;
	}
};


bool AdjacencyList::HamiltionCycle()
{
	bool *visited = new bool[vect];
	for (int i = 0; i < vect; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < vect; i++)						//For changing head of graph in case it doesnt work for one
	{
		node *curr = new node;
		visited[i] = true;								//First node is visited
		path.Push(i);
		if (path.Isfull())								//In case there is only  1 entry, in case of zero, loop wont run anyway
		{
			path_print();
			return true;
		}
		curr = L[i]->next;								//Storing next node
		while(curr != nullptr)							//For checking connections with all nodes of head
		{
			if (Hamiltion(visited, index(curr->data)))	//Will return true if a path is found with this head
			{
				cout << "The path exists:\n";
				path_print();
				cout << endl;
				return true;
			}
			else
			{
				curr = curr->next;
			}
		}
		visited[i] = false;
		path.pop(i);
	}
	cout << "The path doesn't exist.";
	return false;
};

bool AdjacencyList::Hamiltion(bool* visited, int head)
{
	if (visited[head])									//In case the next node is already visited
	{
		return false;
	}
	else
	{
		visited[head] = true;								//visiting this node
		path.Push(head);
		if (path.Isfull())									//Incase a path is found
		{
			return true;									//In case all nodes are found
		}
		else
		{
			node *curr = new node;
			curr = L[head]->next;								//Storing next node
			while (curr != nullptr)							//For checking connections with all nodes of head
			{
				if (Hamiltion(visited, index(curr->data)))		//Here index forwards the the location of next node
				{
					return true;
				}
				else
				{
					curr = curr->next;
				}
			}
		}
		visited[head] = false;
		path.pop(head);
		return false;

	}
}


void AdjacencyList::DFS()
{
	bool *visited = new bool[vect];
	for (int i = 0; i < vect; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < vect; i++)
	{
		if (!visited[i])
		{
			DFS_visit(i, visited);
		}
	}
};

void AdjacencyList::DFS_visit( int i, bool* visited)
{
	cout << L[i]->data << endl;
	visited[i] = true;
	node *curr = L[i]->next;
	while (curr != nullptr)
	{	
		if(!visited[curr->data])
		{
			DFS_visit(index(curr->data), visited);
			
		}
		curr = curr->next;
	}
};

int AdjacencyList::index(int n)
{
	for (int i = 0; i < vect; i++)
	{
		if (L[i]->data == n)
			return i;
	}
	return -1;
};

void AdjacencyList::path_print()
{
	if (!path.IsEmpty())
	{
		int n;
		path.pop(n);
		path_print();
		cout << L[n] -> data << " -> ";
	}
};

bool AdjacencyList::MinHamiltonianCycle()
{
	bool *visited = new bool[vect];
	for (int i = 0; i < vect; i++)
	{
		visited[i] = false;
	}
	mins.minpath = path;
	mins.min_weight = 1000000000;					//Basically storing a large value
	int weights = 0;
	for (int i = 0; i < vect; i++)						//For changing head of graph in case it doesnt work for one
	{
		node *curr = new node;
		visited[i] = true;								//First node is visited
		path.Push(i);
		weights = L[i]->weight;
		if (path.Isfull())								//In case there is only  1 entry, in case of zero, loop wont run anyway
		{
			if (mins.min_weight > weights)				//Stores the new minimum path if weight is smaller
			{
				mins.min_weight = weights;
				mins.minpath = path;
			}
			visited[i] = false;
			path.pop(i);

			return true;
		}
		curr = L[i]->next;								//Storing next node
		while (curr != nullptr)							//For checking connections with all nodes of head
		{
			MinHamiltion(visited, index(curr->data), weights + curr->weight);
			curr = curr->next;
		}
		visited[i] = false;
		path.pop(i);
	}
	if (mins.min_weight == 1000000000)
	{
		cout << "The path doesn't exist.\n";
		return false;
	}
	else
	{
		cout << "The path exists:\n";
		cout << "Total weight = " << mins.min_weight << endl;
		path = mins.minpath;
		path_print();
		return true;
	}
	
}

bool AdjacencyList::MinHamiltion(bool* visited, int head, int weights)
{
	if (visited[head])									//In case the next node is already visited
	{
		return false;
	}
	else
	{
		visited[head] = true;								//visiting this node
		path.Push(head);
		if (path.Isfull())									//Incase a path is found
		{
			if (mins.min_weight > weights)				//Stores the new minimum path if weight is smaller
			{
				mins.min_weight = weights;
				mins.minpath = path;
			}
			visited[head] = false;
			path.pop(head);
			return true;									//In case all nodes are found
		}
		else
		{
			node *curr = new node;
			curr = L[head]->next;								//Storing next node
			while (curr != nullptr)							//For checking connections with all nodes of head
			{
				MinHamiltion(visited, index(curr->data), weights + curr->weight);		//Here index forwards the the location of next node
				curr = curr->next;
			}
		}
		visited[head] = false;
		path.pop(head);
		return false;
	}
}