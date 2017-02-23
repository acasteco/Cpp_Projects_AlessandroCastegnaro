#include <iostream>
#include <string>
#include <ctime>





enum class Weapon { FISTS, GUN, SHOTGUN, REVOLVER, SNIPER, MACHINE_GUN, MAX };

class Zombie;

class Player {
public:
	Weapon weapon;
	float precision;
	int life;

	std::string weaponString() {
		switch (weapon)
		{
		case Weapon::FISTS:return "fist";
			break;
		case Weapon::GUN:return "gun";
			break;
		case Weapon::SHOTGUN:return "shotgun";
			break;
		case Weapon::REVOLVER:return "revolver";
			break;
		case Weapon::SNIPER:return "sniper";
			break;
		case Weapon::MACHINE_GUN:return "machine gun";
			break;
		case Weapon::MAX:return "max";
			break;
		default:
			break;
		}

	}

	Player::Player() {
		weapon = Weapon(rand() % static_cast<int>(Weapon::MAX));//static_cast<int>(Weapon::MAX) = weaponDamage(MAX)
		precision = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		life = rand() % 100;
	}
	Player::Player(Weapon t_weapon, float t_precision, int t_life) {
		weapon = t_weapon;
		precision = t_precision;
		life = t_life;
	}

	void atack(Zombie &zombie);
		

	bool isAlive();

	



};

class Zombie {
public:
	int distanceToPlayer; //20-200
	float speed;		  // [0.f, 20.f)
	float damage;		 //  [0.f, 20.f)
	int life;				//0-100

	Zombie::Zombie() {
		distanceToPlayer = rand() % 180 + 20;
		speed = static_cast <float> (rand()) / static_cast <float> (RAND_MAX/20.0);
		damage = static_cast <float> (rand()) / static_cast <float> (RAND_MAX/20.0);
		life = rand() % 100;
	}
	void atack(Player &player);
	bool isAlive();
	
};


void Player::atack(Zombie &zombie) {
	zombie.life = zombie.life - static_cast<int>(weapon)*precision; //static_cast<int>(weapon) == weaponDamage()
}

bool Player::isAlive() {
	return life > 0;
}

void Zombie::atack(Player &player) {
	if (distanceToPlayer <= 0)
		player.life = player.life - damage;
	else
		distanceToPlayer = distanceToPlayer - speed;
}

bool Zombie::isAlive() {
	return life > 0;
}

int main()
{
	srand(time(nullptr));
	Player player;
	const int NUMZOMBIES = 10;
	Zombie arr[NUMZOMBIES];
	bool zombiesAlive = true;
	int zombiesLast;

	do {
		zombiesLast = NUMZOMBIES;
		for (int i = 0; i < NUMZOMBIES; i++) {
			if (arr[i].isAlive()) {
				player.atack(arr[i]);
				std::cout << "PLAYER:" << std::endl << "	weapon:" << player.life << " weapon:" << player.weaponString() << " precision" << player.precision << std::endl;
				arr[i].atack(player);
				std::cout << "ZOMBIE:" << i << std::endl << "	life:" << arr[i].life << " distance:" << arr[i].distanceToPlayer << " speed" << arr[i].speed << " damage:" << arr[i].damage << std::endl;
			}
			else
				zombiesLast--;

			if (zombiesLast == 0)
				zombiesAlive = false;
		}
		std::cout << "-----------------------------------------------------" << std::endl;

	} while (player.isAlive() && zombiesAlive);
	return 0;
}