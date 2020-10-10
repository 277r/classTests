#include <iostream>
#include <random>
#include <ctime>
#include "matlib.h"
class Enemy
{
public:
	int x, y;
	float health;
};

class Player
{
public:
	int x, y;
	int closestEnemy; // enemy integer number
	int closestEnemyDistance;
	void GetClosestEnemy(int amountOfEnemies, Enemy enemies[])
	{
		closestEnemyDistance = 10000;
		for (int i = 0; i < amountOfEnemies; i++)
		{
			// get closest enemy by coordinates, mathematically incorrect
			if (turnPositive((enemies[i].x + enemies[i].y) - (x + y)) < closestEnemyDistance)
			{
				closestEnemyDistance = turnPositive((enemies[i].x + enemies[i].y) - (x + y));
				closestEnemy = i;
			}
		}
		return;
	}
};

int main()
{
	Player player1;
	player1.x = 37;
	player1.y = 1;
	Enemy enemies[100];
	for (int i = 0; i < 100; i++)
	{
		enemies[i].health = rand() % 10;
		enemies[i].x = i;
		enemies[i].y = 5;
	}
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
	std::cout << "enemy ID: " << player1.closestEnemy;
}