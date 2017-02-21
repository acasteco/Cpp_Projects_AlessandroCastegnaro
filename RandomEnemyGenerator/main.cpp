#include <iostream>
#include <ctime>
#include <string>

//using std::string; //permet fer servir els strings durant tot el document sense tenir la llibreria namespace i sense posar std::string cada cop


enum class EnemyType{ ZOMBIE, VAMPIRE, GHOST, WITCH, WEREWOLF, MAX };//majuscules i el MAX indica el nombre d'elements que hi ha a la classe

/*string names[20] = { "Felipa", "Mercedes", "Jana", "Trudi", "Willette", "Yael", "Ramona",
					 "Dennise", "Sharee", "Tamie", "Aracelis", "Agnus", "Dreama", "Jacquelin",
					 "Manda", "Willa", "Darnell", "Greta", "Nerissa", "Edmundo" }; VARIABLE GLOBAL*/

struct Enemy {
	EnemyType type;
	std::string name;//std::string name;
	int health;

	std::string getenemyTypeString() {
		switch (type) {
		case EnemyType::ZOMBIE: return "zombie";
		case EnemyType::VAMPIRE: return "vampire";
		case EnemyType::GHOST: return "ghost";
		case EnemyType::WITCH: return "witch";
		case EnemyType::WEREWOLF: return "werewolf";
		default: return"";
		}
	}
};




bool operator== (const Enemy &a, const Enemy &b ){ //(Enemy a, Enemy b ) seria lu basic perque funciones ||const fa que no es modifiqui el valor dins la funcio||& ho pasa per parametre
	return (a.type == b.type && a.name == b.name && a.health && b.health);
}


static Enemy CreateRandomEnemy() {
	static const int MAX_LIFE{ 500 };//vida maxima
	static const std::string NAMES[]{ "Felipa", "Mercedes", "Jana", "Trudi", "Willette", "Yael", "Ramona",
								 "Dennise", "Sharee", "Tamie", "Aracelis", "Agnus", "Dreama", "Jacquelin",
								 "Manda", "Willa", "Darnell", "Greta", "Nerissa", "Edmundo" };


	return Enemy{ //Enemy{EnemyType(rand()%4), names[rand()%20], rand()%1000};
		static_cast<EnemyType>(rand() % static_cast<int>(EnemyType::MAX)), 
		NAMES[rand() % (sizeof NAMES / sizeof std::string)], //(sizeof NAMES / sizeof std::string)Et diu el tamany de l'array (tots el bits/tamany de cada array)
		rand() %  MAX_LIFE
	};
}



int main() {
	srand(static_cast<unsigned>(time(nullptr)));
	const int MAX_ENEMIES{ 5 };
	Enemy enemies[MAX_ENEMIES];

	{
		int i{ 0 };
		while (i < MAX_ENEMIES) {
			enemies[i] = CreateRandomEnemy();
			int j{ i - 1 };
			while (j >= 0) {
				if (enemies[i] == enemies[j]) {
					--i;
					break;
				}
				j--;
			}
			++i;
		}
	}

	//Print the array of enemies
	std::cout << "List of Enemies:\n";
	for (auto &enemy : enemies) {
		std::cout << enemy.name <<
			"is a " << enemy.getenemyTypeString() <<
			" whose life is " << enemy.health << std::endl;
	}
	

	return 0;
}


/*
void fillEnemiesArr(Enemy arr[], int l) {
	for (int i = 0; i < l; i++)
		arr[i] = CreateRandomEnemy();
}

void printEnemies(Enemy arr[], int l) {
	cout << "List of Enemies" << std::endl;
	for (int i = 0; i < l; i++) {
		cout << arr[i].name << " is a " << arr[i].type << " whose life is " << arr[i].health << std::endl;
	}
}

*/