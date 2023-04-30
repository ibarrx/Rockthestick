#ifndef ATTACKS_H
#define ATTACKS_H

#include <cstdlib> // for random number generation

class Character {
public:
    int hp; // current health points
    int max_hp; // maximum health points
    int attack; // base attack points

    Character() : hp(100), max_hp(100), attack(20) {}
    virtual ~Character() {}

    virtual int take_damage(int damage) {
        hp -= damage;
        if (hp < 0) hp = 0;
        return damage;
    }

    virtual bool is_alive() const { return hp > 0; }
};

class Player : public Character {
public:
    Player() {
        // set up player-specific attributes here
    }

    int punch() { return 20; }

    int kick() {
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
};

class Enemy : public Character {
public:
    Enemy() {
        // set up enemy-specific attributes here
    }

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
};

#endif // ATTACKS_H
