#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

#include "Character.h"

class Player : public Character {
public:
	Player() : Character() {}

	int kick() { return 20; }

	int punch() {
		if (rand() % 100 < 20) { // 20% chance of miss
			return 0;
		}
		else {
			return 40;
		}
	}

	int special_attack() {
		if (rand() % 100 < 40) { // 40% chance of hit
			return 80;
		}
		else {
			return 0;
		}
	}

	void handleEvent(QEvent* event) {
		switch (event->type()) {
		case QEvent::KeyPress:
			if (static_cast<QKeyEvent*>(event)->key() == Qt::Key_J) {
				// btnPunch pressed
				int damage = punch();
				// do something with damage, like subtract it from enemy health
			}
			else if (static_cast<QKeyEvent*>(event)->key() == Qt::Key_K) {
				// btnKick pressed
				int damage = kick();
				// do something with damage, like subtract it from enemy health
			}
			else if (static_cast<QKeyEvent*>(event)->key() == Qt::Key_L) {
				// btnSpecial pressed
				int damage = special_attack();
				// do something with damage, like subtract it from enemy health
			}
			break;
		default:
			break;
		}
	}

	bool isDead() {
		if (hp <= 0) {
			std::cout << "You Died" << std::endl;
			return true;
		}
		return false;
	}
};

#endif
