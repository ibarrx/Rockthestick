#include "Movement.h"


void Movement::handleKeyPress(QKeyEvent* event) {
    switch (event->key()) {
    case Qt::Key_W: // Jump
        jumpAction();
        break;
    case Qt::Key_A: // Move left
        moveLeft();
        break;
    case Qt::Key_D: // Move right
        moveRight();
        break;
    }
}
