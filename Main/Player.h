#ifndef PLAYER_H
#define PLAYER_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

#include "Character.h"

class Player : public Character {
private:
	Character* player = new Character;

public:
	Player(){ }
	~Player() { delete player; }

	void action() {
		switch (Movement::keypress)
		{
		case 'W':
			// move up
			break;
		case 'A':
			// move left
			break;
		case 'D':
			// move right
			break;
		case 'J':
			// jump
			break;
		case 'L':
			// shoot
			break;
		default:
			// do nothing for other keypresses
			break;
		}
	}


	bool isDead() {
		if (player->hp <= 0) {
			std::cout << "You Died" << std::endl;
			return true;
		}
		return false;
	}
};

#endif
