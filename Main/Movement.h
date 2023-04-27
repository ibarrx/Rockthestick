#pragma once
#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>


class Movement {
private:
	static const float JUMP_VEL;
	static const float MOVE_DIST;
	static const float GRAVITY;
public:
	Movement(){	}
	~Movement() {}

	float xPos = 0.0f;
	float yPos = 0.0f;
	float yVel = 0.0f;
	bool jump = false;
	char keypress;

	void key_cb(GLFWwindow* window, unsigned char key, int action) {
		if (key == 'W' && action == GLFW_PRESS) {
			if (!jump) {
				moveLeft();
				keypress = 'W';
			}
		}
		if (key == 'A' && action == GLFW_PRESS) {
			moveRight();
			keypress = 'A';
		}
		if (key == 'D' && action == GLFW_PRESS) {
			moveLeft();
			keypress = 'D';
		}
	};

	void moveLeft() {
		xPos -= MOVE_DIST;
	}
	
	void moveRight() {
		xPos += MOVE_DIST;
	}
	
	void jump() {
		yVel = JUMP_VEL;
		jump = true;
	}

	void update(float delta) {
		if (jump) {
			yPos += yVel * delta;
			yVel -= GRAVITY * delta;
			if (yPos <= 0.0f) {
				yPos = 0.0f;
				yVel = 0.0f;
				jump = true;
			}
		}
	}
	void draw() {

	}
};

const float Movement::JUMP_VEL = 5.0f;
const float Movement::MOVE_DIST = 1.0f;
const float Movement::GRAVITY = 9.81f;

#endif