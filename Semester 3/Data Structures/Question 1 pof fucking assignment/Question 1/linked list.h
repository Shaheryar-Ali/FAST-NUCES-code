

#ifndef HEAD_H
#define HEAD_H

struct node
{
	char data;
	node* next;
};

class list
{
public:
	node *head;
	list();
	virtual node* begin();
	node* end();
	void insert(char c, char d);
	void remove(char c);
	void insertatstart(char d);
	void removeFromStart();
	bool isEmpty();
};

#endif HEAD_H