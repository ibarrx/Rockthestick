#ifndef PLAYER_H
#define PLAYER_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

#include "Movement.h"

class Player : public Movement 
{

	public:

	int hp;

	Player()
	{
		hp = 100;
	}

	bool isDead()
	{
		if (hp <= 0)
		{
			std::cout << "You Died" << std::endl;
			return true;
		}
		return false;
	}

	void action()
	{
		switch (Movement::keypress)
		{
			case 'W':

				break;

			case 'A':

				break;

			case 'D':

				break;

			case 'J':

				break;

			case 'L':

				break;

			default:
		}
	}
};

#endif
