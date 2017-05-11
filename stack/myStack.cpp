#include "myStack.h"

myStack::myStack()
{
	first = nullptr;
	s = 0;
}

myStack::myStack(myStack & s)
{
	node * it = s.first;						//creo un it que apunta a la primera posicion de s, para recorrer el stack
	first = new node({ s.first->value, nullptr});	//creo un nodo que va ser mi valor first i le digo que le ponga el valor de it
	node * t = first;							//creo un valor temporal t que usare para escribir en el nodo actual

	node * temp;								//creo un valor temp que me sirve para crear el siguiente nodo
	for(int i = 1; i <= s.size(); i++)
	{
		temp = new node({ it->value, nullptr });
		it = it->next;
		t->next = temp;
		t = temp;
	}
}

myStack::myStack(int * a, int sizeOfArray)
{
	node * actual = new node({a[0], nullptr});			
	node * siguiente;
	for (int i = 1; i < sizeOfArray; i++) {
		siguiente = new node({ a[i], nullptr });
		actual->next = siguiente;
		actual = siguiente;
	}
}

myStack::myStack(int num, int element)
{
	s = 0;
	for (int i = 0; i != num; i++) push(element);
}

myStack::~myStack()
{
	while (s != 0) pop();
}

void myStack::pop()
{
	node * temp = first;
	first = first->next;
	delete temp;
	s--;
}

void myStack::push(int element)
{
	first = new node({ element, first });
	s++;
	/* esta linia hace totod esto junto:
	node *temp = new node({element, first});
	temp->value = element;
	temp->next = first;
	first = temp;*/
}

int myStack::top()
{
	return first->value;
}

bool myStack::isEmpty()
{
	return s==0;
}

int myStack::size()
{
	return s;
}
