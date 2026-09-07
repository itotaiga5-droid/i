#pragma once

#include <vector>
#include "Player.h"
#include "Hole.h"
#include "Mole.h"

class Game
{
private:
    Player player;

    std::vector<Hole> holes;

    Mole mole;

    int score;
    int startTime;

    float spawnTimer;

public:
    Game();

    void Initialize();

    void Update();

    void Draw();
};
int hitSE;
int bgm;
