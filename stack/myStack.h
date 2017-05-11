#pragma once
class myStack
{
public:
	myStack(); //crea un null pointer
	myStack(myStack &s); //crea un stack por copia
	myStack(int *a, int tam);//crea un stack a partir de una lista
	myStack(int num, int element); //crea un stack que tiene num veces el elemento
	~myStack();

	void pop();//elimina ultimo elemento
	void push(int element);//inserta un elemnto en la ultima posicion
	int top();//devuelve el utlimo elemento de la pila
	bool isEmpty();
	int size();

private:

	struct node {
		int value;
		node *next;
	};
	size_t s;
	node *first;
};
