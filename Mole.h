#pragma once
#include "DxLib.h"

class Mole
{
private:
    VECTOR pos;
    bool visible;

    float height;
    float lifeTime;

    int imageHandle;

public:
    Mole();

    void SetPos(VECTOR p);

    void Show();
    void Hide();

    void Update();
    void Draw();

    bool IsVisible() const;

    VECTOR GetPos() const;
};