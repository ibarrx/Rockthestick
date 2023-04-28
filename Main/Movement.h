#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <qmainwindow.h>
#include "qopenglwidget.h"

class Movement {
public:
    Movement() {}
    ~Movement() {}

    float xPos = 0.0f;
    float yPos = 0.0f;
    float yVel = 0.0f;
    bool jump = false;
    static char keypress;

    void key_cb(QOpenGLWidget* window, unsigned char key, int action) {
        if (key == 'w' && action == keypress) { // Jump
            jumpAction();
        }
        if (key == 'a' && action == keypress) { // Move left
            moveLeft();
            keypress = 'A';
        }
        if (key == 'd' && action == keypress) { // Move right
            moveRight();
            keypress = 'D';
        }
    }

    inline void moveLeft() {
        xPos -= MOVE_DIST;
    }

    inline void moveRight() {
        xPos += MOVE_DIST;
    }

    inline void jumpAction() {
        yVel = JUMP_VEL;
        jump = true;
    }

    inline void update(float delta) {
        if (jump) {
            yPos += yVel * delta;
            yVel -= GRAVITY * delta;
            if (yPos <= 0.0f) {
                yPos = 0.0f;
                yVel = 0.0f;
                jump = false;
            }
        }
    }
    static constexpr float JUMP_VEL = 5.0f;
    static constexpr float MOVE_DIST = 1.0f;
    static constexpr float GRAVITY = 9.81f;
    inline void draw() {}
};


#endif
