#pragma once
#include <time.h>
#include <stdlib.h>

struct node { node *backward;  int value; node *forward; };

class MyList
{

public:
	MyList();
	MyList(MyList &m);
	~MyList();
	node *front();
	node *back();
	bool isEmpty();
	int size();
	void pushFront(int value);
	void pushBack(int value);
	void popFront();
	void popBack();
	void remove(int value);
	void shiftLeft();
	void shiftRight();
	void reverse();

private:
	size_t listSize;
	node *first;
	node *last;
};
