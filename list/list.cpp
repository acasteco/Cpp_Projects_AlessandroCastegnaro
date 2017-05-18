/*
|	|	|	list	|	|	|

[v1]<=>[v4]<=>[v3]<=>[v2]<=>[v5]

son implementadas como listas doblemente enlazadas
puede hacer push, push_front, pop, pop_front
soporta operadores bidireccionales (aunque no existe el begin()+n)
no tenemos acceso posicional pero es mucho mas eficiente

map va muy bien para acceder a elementos pero no tanto para insertar
list va muy bien para insertar elementos pero no tanto para acceder (es mas caro)

std::list<int> mylist;
std::list<int>iterator it;

for(int i = 1; i <= 5; i++) mylist.push_back(i); // 12345

it = mylist.begin(); //it apunta a 1
++it;
mylist.insert(it, 10); //1 10 2 3 4 5

mylist.insert(2, 20) // 1 10 20 20 2 3 4 5

--it;

std::vector<int> myvector(2, 30);
mylist.insert(it, myvector.begin(), myvector.end()); //1 10 20 30 30 20 2 3 4 5

it = mylist.begin(); //1 10 20 30 30 20 2 3 4 5
					 //^
std::advance(it, 6); //1 10 20 30 30 20 2 3 4 5
					 //                 ^
*it = 15;			 //1 10 20 30 30 20 15 3 4 5

*/
#include <iostream>
#include "MyList.h"
#include <string>

int main() {
	srand(time(NULL));
	MyList lista;
	lista.pushFront(3);
	lista.pushBack(5);
	std::cout << lista.front()->value << lista.back()->value << std::endl;
	system("pause");
	return 0;
}