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
		~Movement(){}

		float horizontalPos = 0.0f;
		float verticalPos = 0.0f;
		float verticalVel = 0.0f;
		bool jump = false;

		void key_cb(GLFWwindow* window, unsigned char key, int action) {
			if (key == 'W' && action == GLFW_PRESS) {
				if (!jump) {
					verticalVel = JUMP_VEL;
					jump = true;
				}
			}
			if (key == 'A' && action == GLFW_PRESS) {
				horizontalPos -= MOVE_DIST;
			}
			if (key == 'D' && action == GLFW_PRESS) {
				horizontalPos += MOVE_DIST;
			}
		};

		void update(float delta) {
			if (jump) {
				verticalPos += verticalVel * delta;
				verticalVel -= GRAVITY * delta;
				if (verticalPos <= 0.0f) {
					verticalPos = 0.0f;
					verticalVel = 0.0f;
					jump = true;
				}
			}
		}
		void draw() {

		}
};

const float Movement::JUMP_VEL = 5.0f;
const float Movement::MOVE_DIST = 0.1f;
const float Movement::GRAVITY = 9.81f;

#endif