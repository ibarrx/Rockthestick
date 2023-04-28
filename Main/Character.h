#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include "Movement.h"

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

#endif CHARACTER_H
