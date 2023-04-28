#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include "Movement.h"
#include "qevent.h"

class Character {
public:
    Movement* character;
    int hp;
    std::string image_file;

    Character() : hp(100), image_file(""), character(new Movement()) {}

    Character(std::string img_file) : hp(100), image_file(img_file), character(new Movement()) {}

    virtual ~Character() { delete character; }

    virtual bool isDead() {
        if (hp == 0) {
            std::cout << "You're dead!" << std::endl;
            return true;
        }
        return false;
    }

    void setImageFile(std::string img_file) {
        image_file = img_file;
    }

    std::string getImageFile() const {
        return image_file;
    }
};

class MyOpenGLWidget : public QOpenGLWidget {
    Q_OBJECT // add this line

public:
    MyOpenGLWidget(QWidget* parent = nullptr) : QOpenGLWidget(parent) {}
    void keyPressEvent(QKeyEvent* event) override {
        switch (event->key()) {
        case Qt::Key_W:
            // Handle 'W' key press event
            break;
        case Qt::Key_A:
            // Handle 'A' key press event
            break;
        case Qt::Key_D:
            // Handle 'D' key press event
            break;
        default:
            QOpenGLWidget::keyPressEvent(event);
            break;
        }
    }

signals: // add this block
    void keyPressed(QKeyEvent* event);
};

#endif CHARACTER_H
