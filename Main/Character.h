#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <time.h>
#include <random>

#include <Movement.h>

typedef class Character {
public:	
	Movement* character = new Movement;
	int hp;

	Character() : hp(100) {	}
	~Character() { delete character; }

	virtual bool isDead() {
		if (hp == 0) {
			std::cout << "You're dead!" << std::endl;
			return true;
		}
		return false;
	}

} ch; 


#endif CHARACTER_H