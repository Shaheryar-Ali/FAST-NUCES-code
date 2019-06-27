#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct node
{
	int data;
	node *next;
};


void main()
{
	srand(time(0));
	node *head = new node;
	int p;							//For counting no of people
	int n, m;

	do
	{
		cout << "Enter the number of people you want to enter" << endl;
		cin >> p;
		if (p <= 0)
			cout << "The input must be a positive integer\n";
	} while (p <= 0);

	cout << "Enter an input = ";
	cin >> n;
	head->data = n;
	head->next = nullptr;
	node *curr = head;

	for (int i = 1; i < p; i++)
	{
		node *temp = new node;
		cout << "Enter input = ";
		cin >> n;
		temp->data = n;
		if (i == p - 1)
			temp->next = head;
		else
			temp->next = nullptr;
		curr->next = temp;
		curr = curr->next;
	}

	curr = head;
	node *curr2 = head;

	while (curr2->next != curr)
	{
		m = rand() % 10;
		system("cls");
		curr = head;
		do
		{
			cout << curr->data << " ";
			curr = curr->next;
		} while (curr != head);

		for (int i = 1; i < m; i++)
		{
			curr2 = curr2->next;
		}
		if (curr2->next == head)
			head = curr2->next->next;
		node *temp = curr2->next;
		curr2->next = curr2->next->next;
		Sleep(1000);
		if(curr!=curr->next)
		delete temp;
	}
	system("cls");
	do
	{
		cout << curr->data << " ";
		curr = curr->next;
	} while (curr != head);
}