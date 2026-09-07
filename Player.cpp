#include "Player.h"

Player::Player()
{
    pos = VGet(0.0f, 2.0f, 0.0f);
}

void Player::Update()
{
    if (CheckHitKey(KEY_INPUT_W))
        pos.z += 0.4f;

    if (CheckHitKey(KEY_INPUT_S))
        pos.z -= 0.4f;

    if (CheckHitKey(KEY_INPUT_A))
        pos.x -= 0.4f;

    if (CheckHitKey(KEY_INPUT_D))
        pos.x += 0.4f;
}

void Player::Draw()
{
    DrawSphere3D(
        pos,
        2.0f,
        16,
        GetColor(0, 0, 255),
        GetColor(0, 0, 255),
        TRUE);
}

VECTOR Player::GetPos() const
{
    return pos;
}