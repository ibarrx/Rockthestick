#pragma once

#include <iostream>
#include <string>
#include "qevent.h"

class Character {
public:
    int hp;

    Character() : hp(100) {}

    virtual ~Character() { }

    virtual bool isDead() {
        if (hp == 0) {
            std::cout << "You're dead!" << std::endl;
            return true;
        }
        return false;
    }

};