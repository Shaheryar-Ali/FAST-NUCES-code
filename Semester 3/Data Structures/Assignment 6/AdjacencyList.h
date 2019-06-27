#pragma once
#include "Stack.h"
#include <list>
class AdjacencyList
{
	private:
		struct node
		{
			int data;
			int weight;
			node* next;
		};
		struct minstack
		{
			Stack <int> minpath;
			int min_weight;
		};
		node** L;
		int vect;					//Stores no. of vector that is no. of data members
		bool weighted;				//Indicates if the list is weighted or not;
		Stack <int> path;
		bool Hamiltion(bool* visited, int head);
		void DFS_visit(int i, bool *visited);
		minstack mins;
		bool MinHamiltion(bool* visited, int head, int weights);
	public:
		AdjacencyList();
		void Input();
		void Output();
		bool HamiltionCycle();
		void DFS();
		int index(int n);
		void path_print();
		bool MinHamiltonianCycle();
};