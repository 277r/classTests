#include <cmath>
#include <iostream>
#include <random>
#include "tMathMain.cpp"

int maxHitDistance = 10; // expirimental

// 9 bytes i thinK?
class Enemy
{
public:
	int x, y;
	float health;
	bool isAlive;

	void kill()
	{
		isAlive = false;
	}
	bool isHittable(int playerx, int playery)
	{
		// distance 	if (player)
		if (isAlive && turnPositive(playerx - x) + turnPositive(playery - y) < maxHitDistance)
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
	int closestAliveEnemy; // enemy integer number
	int closestEnemyDistance;
	int closestEnemyID;
	int enemyKillCount;
	void killEnemy(Enemy &enemy)
	{
		if (enemy.isAlive)
		{
			enemy.kill();
			enemyKillCount++;
		}
	}
	bool allEnemiesDead(int amountOfEnemies, Enemy enemies[])
	{
		for (int i = 0; i < amountOfEnemies; i++)
		{
			if (enemies[i].isAlive)
			{
				return false;
			}
		}
		return false;
	}
	void getClosestEnemy(int amountOfEnemies, Enemy enemies[])
	{ // remove function later, useless, takes time
		for (int i = 0; i < amountOfEnemies; i++)
		{
			if (enemies[i].isAlive && turnPositive(enemies[i].x - x) + turnPositive(enemies[i].y - y) < closestEnemyDistance)
			{
				closestEnemyID = i;
			}
		}
	}
};

long long int calculateEnemiesThisRound(int mode, long long int round, int a, int b)
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
	int factorA, factorB;
	Player player1;
	bool inGame = true;
	for (long long int round = 0; inGame; round++)
	{
		long long int enemiesThisRound = calculateEnemiesThisRound(0, round, factorA, factorB);
		std::cout << "amount of enemies this round: " << enemiesThisRound << std::endl;
		std::cout << "continue? ";
		std::cin >> inGame;

		Enemy *enemies = new Enemy[enemiesThisRound];


		for (long long int i = 0; i < enemiesThisRound; i++) // for loop here is to simulate locations, not in real game
		{
			enemies[i].x = rand() % 200 - 100;
			enemies[i].y = rand() % 200 - 100;
			enemies[i].isAlive = true;
		}

		while (!player1.allEnemiesDead(enemiesThisRound, enemies))
		{			
			for (long long int i = 0; i < enemiesThisRound; i++)
			{
				if (enemies[i].isAlive)
				{
					std::cout << "enemy ID: " << i << '\n';
					std::cout << "(x, y) = (" << enemies[i].x << ", " << enemies[i].y << ")\n\n";
				}
			}

			std::cout << "current killcount: " << player1.enemyKillCount << std::endl;
			int currentEnemyID;
			std::cout << "what enemy to kill? (ID): ";
			std::cin >> currentEnemyID;
			player1.killEnemy(enemies[currentEnemyID]);
		}
	}
}