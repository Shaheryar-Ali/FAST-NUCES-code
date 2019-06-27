#include <iostream>
#include "linked list.h"

using namespace std; 

list::list()
{
	head = nullptr;
};

node* list::begin()
{
	return head;
};

node* list::end()
{
	node* temp = head;
	while (temp->next != nullptr)
		temp = temp->next;
	return temp;
};

bool list::isEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
};


void list::insert(char c, char d)
{
	node* temp = new node;
	if (isEmpty())
	{
		temp->data = d;
		temp->next = nullptr;
		head = temp;
	}
	else
	{
		temp = head;
		while (temp != nullptr && temp->data != c)
			temp = temp->next;
		if (temp != nullptr)
		{
			node * temp2 = new node;
			temp2->data = d;
			temp2->next = temp->next;
			temp->next = temp2->next;

		}
	}

};

void list::remove(char c)
{
	node* temp = new node;
	if (isEmpty())
	{
		cout << "List is empty\n";

	}
	else if (head->next == nullptr)
	{
		temp = head;
		delete temp;
	}
	else
	{
		temp = head;
		while (temp->next != nullptr && temp->data != c)		//Lo
			temp = temp->next;
		if (temp->next != nullptr)
		{
			node* temp2 = new node;
			temp2 = temp->next;
			temp->next = temp->next->next;
			delete temp2;			//Delete node next to the key one
		}
	}

}

void list::insertatstart(char d)
{
	node* temp = new node;
	temp->data = d;
	if (isEmpty())
	{
		temp->next = nullptr;
		head = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
}

void list::removeFromStart()
{
	node* temp = new node;
	if (isEmpty())
	{
		cout << "list is already empty";
	}
	else if (head->next == nullptr)
	{
		temp = head;
		delete temp;
	}
	else
	{
		temp = head;
		head = head->next;
		delete temp;
	}

};