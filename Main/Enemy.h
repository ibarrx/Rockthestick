#ifndef ENEMY_H
#define ENEMY_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

#include "Movement.h"

class Enemy : public Movement {

public:

	int hp;

	Enemy()
	{
		hp = 100;
	}

	bool isDead()
	{
		if (hp <= 0)
		{
			std::cout << "You Win" << std::endl;
			return true;
		}
		return false;
	}

	void randmove()
	{

	}
};

#endif
