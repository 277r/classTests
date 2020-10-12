#include <iostream>
#include <random>
#include <ctime>
#include "tMathMain.cpp" // requires my matlib library

class Enemy
{
public:
	int x, y;
	float health;
	bool isAlive = true;
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
			if (enemies[i].isAlive == false)
			{
				// isDead
			}
			// get closest enemy by coordinates, mathematically might be correct
			else if (turnPositive(enemies[i].x - x) + turnPositive(enemies[i].y - y) < closestEnemyDistance)
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
	bool killenemy( Enemy enemie)
	{
		if (enemie.isAlive == true)
		{
			enemie.isAlive = false;
			enemyKillCount += 1;
			return true;
		}
		return false;
	}
};

int calculateEnemiesThisRound(int mode, int round, int a, int b)
{
	if (mode == 0)
	{
		// logarithmic
		return pow(10, round);
	}
	else if (mode == 1)
	{
		// quadratic ax^b
		return a * pow(mode, b);
	}
	else if (mode == 2)
	{
		// linear a * round
		return a * round;
	}
	else if (mode == 3)
	{
		// exponential a*b^round
		return a * pow(b, round);
	}
	else if (mode == 4)
	{
		// easter egg hyperbolic, a /
		return a / (0 - mode + b);
	}
	return 1;
}

int main()
{
	int mode, factorA, factorB;
	std::cout << "mode: ";
	std::cin >> mode;
	std::cout << "a: ";
	std::cin >> factorA;
	std::cout << "b: ";
	std::cin >> factorB;

	int round;
	for (bool inGame = true; inGame != false; inGame = inGame) // quality for loop abusing, do things until the inGame is set to false
	{
		round += 1;
		srand(time(NULL));
		int amountOfEnemies = 10;
		Player player1;
		player1.x = rand() % 100 - 50;
		player1.y = rand() % 100 - 50;
		Enemy enemies[amountOfEnemies]; // the 100 here stands for something to later use as in a formula, make 100 enemies, make 1000 enemies, MAKE 100000 ENEMIESZ!!!!!!!!!
		while (!player1.allEnemiesDead(amountOfEnemies, enemies))
		{
			for (int i = 0; i < amountOfEnemies; i++)
			{
				enemies[i].health = rand() % 10;
				enemies[i].x = rand() % 100 - 50;
				enemies[i].y = rand() % 100 - 50;
			}
			for (int i = 0; i < amountOfEnemies; i++)
			{
				if (!enemies[i].isAlive){
					std::cout << "enemy: " << i << std::endl;
					std::cout << "health: " << enemies[i].health << '.' << std::endl;
					std::cout << "coordinates: (" << enemies[i].x << "; " << enemies[i].y << ")" << std::endl
							  << std::endl;
				}
			}
		
			player1.GetClosestEnemy(amountOfEnemies, enemies);
			std::cout << "coordinates of player1 : (" << player1.x << "; " << player1.y << ")" << std::endl;
			std::cout << "(" << enemies[player1.closestEnemy].x << "; " << enemies[player1.closestEnemy].y << ")" << std::endl;
			std::cout << "enemy ID: " << player1.closestEnemy << std::endl;
			int currentenemyID;
			std::cout << "what enemy to kill? ";
			std::cin >> currentenemyID;
			player1.killenemy(enemies[currentenemyID]);
		}
	}
}