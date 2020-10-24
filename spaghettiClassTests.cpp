#include <iostream>
#include <random>
#include <ctime>
#include "tMathMain.cpp" // requires my matlib library
class Enemy
{
public:
	int x, y;
	float health;
	bool isAlive;
	bool isHittable(Player player)
	{
		if (turnPositive(x - player.x) + turnPositive(y - player.y) < 5)
		{
			return true;
		}
		return false;
	}
};

class Player
{
public:
	int x, y;
	int closestEnemy; // enemy integer number
	int closestEnemyDistance;
	int enemyKillCount;

	void GetClosestEnemy(int amountOfEnemies, Enemy enemies[])
	{
		closestEnemyDistance = 10000; // must fix to have set field size
		for (int i = 0; i < amountOfEnemies; i++)
		{
			// get closest enemy by coordinates, mathematically might be correct
			if (turnPositive(enemies[i].x - x) + turnPositive(enemies[i].y - y) < closestEnemyDistance)
			{
				closestEnemyDistance = turnPositive((enemies[i].x + enemies[i].y) - (x + y));
				closestEnemy = i;
			}
		}
		return;
	}
	bool allEnemiesDead(int amountOfEnemies, Enemy enemies[])
	{
		for (int i = 0; i < amountOfEnemies; i++)
		{
			if (enemies[i].isAlive == true)
			{
				return false;
			}
		}
		return true;
	}
	void killenemy(Enemy &enemy)
	{
		if (enemy.isAlive == true && enemy.isHittable(*this))
		{
			enemy.isAlive = false;
			enemyKillCount += 1;
		}
		return;
	}
};

int main()
{
	srand(time(NULL));

	Player player1;
	player1.x = rand() % 100 - 50;
	player1.y = rand() % 100 - 50;
	Enemy enemies[100]; // the 100 here stands for something to later use as in a formula, make 100 enemies, make 1000 enemies, MAKE 100000 ENEMIESZ!!!!!!!!!
	for (int i = 0; i < 100; i++)
	{
		enemies[i].health = rand() % 10;
		enemies[i].x = rand() % 100 - 50;
		enemies[i].y = rand() % 100 - 50;
	}
	while (!player1.allEnemiesDead(100, enemies))
	{
		for (int i = 0; i < 100; i++)
		{
			std::cout << "enemy: " << i << std::endl;
			std::cout << "health: " << enemies[i].health << '.' << std::endl;
			std::cout << "coordinates: (" << enemies[i].x << "; " << enemies[i].y << ")" << std::endl
					  << std::endl;
		}
		player1.GetClosestEnemy(100, enemies);
		std::cout << "coordinates of player1 : (" << player1.x << "; " << player1.y << ")" << std::endl;
		std::cout << "(" << enemies[player1.closestEnemy].x << "; " << enemies[player1.closestEnemy].y << ")" << std::endl;
		std::cout << "enemy ID: " << player1.closestEnemy << std::endl;
		int currentenemyID;

		std::cout << "what enemy to kill? ";
		std::cin >> currentenemyID;
		player1.killenemy(enemies[currentenemyID]);
	}
}