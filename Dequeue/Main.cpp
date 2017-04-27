/*
deque (doble cola) [deq] : sabe donde esta cada elemento, pero los valores no estan consecutivamente en memeoria (no como vector).
permite acceso directo, i la insercion es barata
Dinamico
(aunque la insercion es mas compleja)
queue:
[value|siguiente elemento]
deque:
[valor anterior|value|siguiente valor]

deque-> acceso a elemento de posicion i []
		acceso al primer elemento front
		ultimo back

		insert primero push_front
		insert ultimo push_back
		delete pop_front || pop_back
		insert
		erase


declaration:
std::deque<int> d1;
std::deque<std::string> d2(5);
std::deque<int> d4({1,2,3,4});

d1.push_back(1);
d1.push_back(2);
d1.push_front(3);

d1[0] = 44;
d1[5] = 1; //error, esa posicion de memoria no existe

iteradores:
for(auto &x : d3){std::cout << x << "-"};

for(int i = 0; i < d3.size(); i++){
	std::cout << d3[i] << "-";
}

for(auto it = d3.begin(); it != d3.end(); ++it){
	std::cout << *it << "-";
}

example:
std::deque<int> d6;
for(int i = 1; i < 6; i++) d6.push_back(i);
std::deque<int>::iterator it = d6.insert(d6.begin()+2, 10);
d6.insert(it, 2, 20);

it = d6.begin() + 2;
std::vector<int> myvector(2, 30);
d6.insert(it, myvector.begin(). myvector.end());
//1 2 30  30 20 20 10 2 3 4 5


<queue>
(fifo->fisrt in first out)
Simula una cola normal-> solo se puede hacer un push() insertar por el final, o un pop() eliminar el primero
las queues no soportan iteradores, no se puede recorrer sin perder informacion

priority_queue:
#include <queue>

...
std::priority_queue<int> mypq;
mypq.push(30);

*/
#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <time.h>

std::priority_queue<int> SuperMergeP(std::priority_queue<int> a, std::priority_queue<int> b) {
	std::priority_queue<int> mergepq;
	while (!a.empty()) {
		mergepq.push(a.top());
		a.pop();
	}
	while (!b.empty())
	{
		mergepq.push(b.top());
		b.pop();
	}
	return mergepq;
}

std::queue<std::string> concatQueue(std::queue<std::string> a, std::queue<std::string> b) {
	std::queue<std::string> concatq;
	while (a.size() != 0) {
		concatq.push(a.front());
		a.pop();
	}
	while (b.size() != 0) {
		concatq.push(b.front());
		b.pop();
	}
}

std::queue<int> shiftRight(std::queue<int> a) {
	std::queue<int> shiftedq;
	shiftedq.push(rand());
	while (a.size() != 0) {
		shiftedq.push(a.front());
		a.pop();
	}
}

std::queue<int> shiftLeft(std::queue<int> a) {
	std::queue<int> shiftedq;

	a.push(a.front());
	a.pop();
	return a;

}

std::deque<int> eraseValue(std::deque<int> a, int v) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == v)
			a.erase(i);
	}
}



int main() {

	srand(time(NULL));


	std::deque<float> prices(10);
	for (int i = 0; i < prices.size(); ++i)
		prices[i] = 10.5;

	prices[prices.size() - 1] = 32.43;
	
	prices.pop_front();

	std::deque<float> newDeque(prices);
	//newDeque = prices;
	//newDeque.insert(newDeque.begin(), prices.begin(), prices.end());

	newDeque.push_front(5.64);
	newDeque.push_front(20.31);

	newDeque.insert(newDeque.begin()+1, 10);

	for (std::deque<float>::reverse_iterator rit = prices.rbegin(); rit != prices.rend(); ++rit) {
		std::cout << *rit << "-";
	}
	std::cout << std::endl;

	while (newDeque.size() != 0) {
		std::cout << newDeque.back() << "-";
		newDeque.pop_back();
	}
	std::cout << std::endl;



	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//EJ 2:
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	std::vector<float> prices2(10);
	for (int i = 0; i < prices.size(); ++i)
		prices[i] = 10.5;

	prices2[prices2.size() - 1] = 32.43;

	prices2.erase(prices2.begin());

	std::vector<float> newVector;
	newVector.insert(newVector.begin(), prices2.begin(), prices2.end());

	newVector.insert(newVector.begin(), 5.64);
	newVector.insert(newVector.begin(), 20.31);

	newVector.insert(newVector.begin() + 1, 10);

	for (std::vector<float>::reverse_iterator rit = prices2.rbegin(); rit != prices2.rend(); ++rit) {
		std::cout << *rit << "-";
	}
	std::cout << std::endl;

	while (newVector.size() != 0) {
		std::cout << newVector.front() << "-";
		newVector.erase(newVector.end() - 1);
	}
	std::cout << std::endl;


	return 0;
}

