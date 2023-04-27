#ifndef ENEMY_H
#define ENEMY_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <random>

#include "Character.h"

class Enemy : public Character {
private:
	Character* enemy = new Character;
public:
	Enemy(){ }

	void randmove(){
		int randomTime = rand() % 3;
		if (randomTime == 0) {
			std::chrono::seconds waitTime(5);
		}
		else if (randomTime == 1) {
			std::chrono::seconds waitTime(3);
		}
		else {
			std::chrono::seconds waitTime(1);
		}

		int random = rand() % 100;
		if (random % 2 == 0) {
			enemy->character->moveLeft();
		}
		else {
			enemy->character->moveRight();
		}
	}

	bool isDead() {
		if (enemy->hp <= 0) { 
			std::cout << "You Win!" << std::endl; 
			return true;
		}
		else return false;
	}
};

#endif
