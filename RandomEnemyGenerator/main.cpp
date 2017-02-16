#include <iostream>
#include <ctime>

using std::string;

enum class EnemyType{ ZOMBIE, VAMPIRE, GHOST, WITCH };//majuscules

string names[20] = { "Felipa", "Mercedes", "Jana", "Trudi", "Willette", "Yael", "Ramona",
					 "Dennise", "Sharee", "Tamie", "Aracelis", "Agnus", "Dreama", "Jacquelin",
					 "Manda", "Willa", "Darnell", "Greta", "Nerissa", "Edmundo" };

struct Enemy {
	EnemyType type;
	string name;
	int health;
};

Enemy CreateRandomEnemy() { 
	return Enemy{EnemyType(rand()%4), names[rand()%20], rand()%1000};
}

void fillEnemiesArr(Enemy arr[], int l) {
	for (int i = 0; i < l; i++)
		arr[i] = CreateRandomEnemy();
}

void printEnemies(Enemy arr[], int l) {
	std::cout << "List of Enemies" << std::endl;
	for (int i = 0; i < l; i++)
		std::cout << arr[i].name << " is a " << arr[i].type << " whose life is " << arr[i].health << std::endl;
}

bool operator== (Enemy a, Enemy b ){
	return (a.type == b.type && a.name == b.name && a.health && b.health);
}

int main() {
	srand(time(NULL));
	
	Enemy enemies[5];

	fillEnemiesArr(enemies, 5);
	printEnemies(enemies, 5);

	return 0;
}