/*
stack(pila)->LIFO last in fisrt out
top-	consulta del elemento de la cola (top())
push-	inserta un elemento en el final de la pila (push_back())
pop-	elimina el ultimo elemento de la pila (pop_back())
size-	retorna el tamaño de la pila en un entero (size());

declaracion:
std::stack<int> d1;
d1.push(1);
d2.push(2);



struct Person{
	std::string name;
	int age;

	Person(std::string n, int a){
		name = n;
		age = a;
	}
}
std:: stack<Person> s2;
s2.push(person("ana", 20));
s2.emplace("pepe", 22);

std::stack<person>s3(s2); //constructor de copia

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
("template") class myStack{
	struct node{
		int value;
		node *next;
		}

*/

#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>
#include <queue>
#include <string>
#include "myStack.h"

//funcion que imprime una pila:
void PrintStack(myStack a){
	while (!a.isEmpty()) {
		std::cout << a.top() << std::endl;
		a.pop();
	}
}

//
////recibe 2 stacks ordeandos de mayor a menor y devuelve una sola pila ordenada:
//std::stack<int> SuperMeger(std::stack<int> a, std::stack<int> b) {
//	std::deque<int> aux;
//	std::stack<int> res;
//	while (!a.empty()) {
//		aux.push_back(a.top());
//		a.pop();
//	}
//	while (!b.empty()) {
//		aux.push_back(b.top());
//		b.pop();
//	}
//
//	std::sort(aux.begin(), aux.end());
//	for (int i = 0; i < aux.size(); i++) {
//		res.push(aux[i]);
//	}
//	//aux.clear();
//	return res;
//}
//
//std::stack<std::string> PutHat(std::stack<std::string> s1, std::stack<std::string> s2) {
//	std::stack<std::string> aux;
//	while (!s1.empty()) {
//		aux.push(s1.top());
//		s1.pop();
//	}
//	while (!aux.empty()) {
//		s2.push(aux.top());
//		aux.pop();
//	}
//	return s2;
//}
//
//std::queue<int> TransformToQ(std::stack<int> a) {
//	std::queue<int> res;
//	while (!a.empty()) {
//		res.push(a.top());
//		a.pop();
//	}
//	return res;
//}
//
//bool isHat(std::stack<int> a, std::stack<int> b) {
//	while (!a.empty()) {
//		if (a.top() != b.top())
//			return false;
//		a.pop();
//		b.pop();
//	}
//	return true;
//}
//
//bool balancedP(std::queue<char> a) {
//	int aux = 0;
//	while (!a.empty()) {
//		if (a.front() == '(')
//			aux++;
//		if (a.front() == ')')
//			aux--;
//		a.pop();
//		if (aux < 0)
//			return false;
//	}
//	return aux == 0;
//	
//}
//
//std::stack<int> change(std::stack<int> a) {
//	int top;
//	std::deque<int> aux;
//	top = a.top();
//	while (!a.empty()) {
//		aux.push_front(a.top());
//		a.pop();
//	}
//	top = aux.front();
//	aux[0] = aux[aux.size()];
//	aux[aux.size()] = top;
//	for (int i = 0; i < aux.size(); i++) {
//		a.push(aux[i]);
//	}
//}

int main() {
	/*std::stack<int> m1;
	for (int i = 0; i < 10; i++) {
		m1.push(i);
	}
	std::stack<int> m2(m1);

	//PrintStack(SuperMeger(m1, m2));

	std::stack<std::string> p1({"7","4","9","2"});
	std::stack<std::string> p2({ "5","5","6"});

	std::stack<std::string>p3 = PutHat(p1, p2);
	PrintStack(p3);*/
	int a[] = { 4,5,6,7 };
	myStack s1;
	s1.push(4);
	//PrintStack(s1);


	return 0;
}

