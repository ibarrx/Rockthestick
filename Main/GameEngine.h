#pragma once
#include <QObject>
#include "Character.h"
#include "Movement.h"

class GameEngine : public QObject {
    Q_OBJECT

public:
    explicit GameEngine(QObject* parent = nullptr);
    ~GameEngine();

    void update(float delta); // Update game state based on elapsed time

private:
    Character* player1;
    Character* player2;
    Movement* player1Movement;
    Movement* player2Movement;

    void checkCollisions(); // Check for collisions between characters or stage boundaries
};
