#include <iostream>
#include <random>
#include <ctime>
#include "tMathMain.cpp" // requires my matlib library
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
};

int main()
{
	srand(time(NULL));

	Player player1;
	player1.x = rand() % 100 -50;
	player1.y = rand() % 100 -50;
	Enemy enemies[100]; // the 100 here stands for something to later use as in a formula, make 100 enemies, make 1000 enemies, MAKE 100000 ENEMIESZ!!!!!!!!!
	for (int i = 0; i < 100; i++)
	{
		enemies[i].health = rand() % 10;
		enemies[i].x = rand() % 100 - 50;
		enemies[i].y = rand() % 100 - 50;
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