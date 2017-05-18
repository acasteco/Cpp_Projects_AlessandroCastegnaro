#include "MyList.h"

MyList::MyList()
{
	first = nullptr;
	last = nullptr;
	listSize = 0;
}

MyList::MyList(MyList & m)
{
	node * t = m.first;
	while (t != nullptr) {
		pushBack(t->value);
		t = t->forward;
	}
}

MyList::~MyList()
{
	while (listSize > 0) {
		popFront();
	}
}

node * MyList::front()
{
	return first;
}

node * MyList::back()
{
	return last;
}

bool MyList::isEmpty()
{
	return listSize == 0;
}

int MyList::size()
{
	return listSize;
}

void MyList::pushFront(int value)
{
	if (listSize == 0) {
		first = new node({ nullptr, value, nullptr });
		last = first;
	}
	else {
		first->backward = new node( {nullptr, value, first} );
		first = first->backward;
	}
	listSize++;
}

void MyList::pushBack(int value)
{
	if (listSize == 0) {
		first = new node ( {nullptr, value, nullptr} );
		last = first;
	}
	else {
		last->forward = new node( { last, value, nullptr } );
		last = last->forward;
	}
	listSize++;
}

void MyList::popFront()
{
	if (isEmpty())
		return;
	if (listSize == 1) {
		delete first;
		listSize == 0;
		return;
	}
	node * aux = first;
	first = first->forward;
	delete aux;
	listSize--;
}

void MyList::popBack()
{
	if (isEmpty())
		return;
	if (listSize == 1) {
		delete first;
		listSize == 0;
		return;
	}
	node * aux = last;
	last = last->backward;
	delete aux;
	listSize--;
}

void MyList::remove(int value)
{
	node * t = first;
	while (t != nullptr) {
		if (t->value == value) {
			t->backward->forward = t->forward;
			t->forward->backward = t->backward;
			delete t;
		}
		t = t->forward;
	}
}

void MyList::shiftLeft()
{
	popFront();
	pushBack(static_cast<int>(rand()));
}

void MyList::shiftRight()
{
	popBack();
	pushFront(static_cast<int>(rand()));
}

void MyList::reverse()
{
	node * tempBackward = last;
	node * tempForward = first;


}

