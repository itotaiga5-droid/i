#pragma once
#include "DxLib.h"

class Player
{
private:
    VECTOR pos;

public:
    Player();

    void Update();
    void Draw();

    VECTOR GetPos() const;
};
