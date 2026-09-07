#include "Game.h"
#include "DxLib.h"
#include <ctime>
#include <cstdlib>
#include <cmath>

Game::Game()
{
    score = 0;
    spawnTimer = 0.0f;
}

void Game::Initialize()
{
    srand((unsigned int)time(nullptr));

    startTime = GetNowCount();

    holes.push_back(Hole(VGet(-15, 0, 15)));
    holes.push_back(Hole(VGet(0, 0, 15)));
    holes.push_back(Hole(VGet(15, 0, 15)));

    holes.push_back(Hole(VGet(-15, 0, -15)));
    holes.push_back(Hole(VGet(0, 0, -15)));
    holes.push_back(Hole(VGet(15, 0, -15)));
}

void Game::Update()
{
    player.Update();

    spawnTimer += 1.0f / 60.0f;

    if (spawnTimer >= 2.0f)
    {
        int index = rand() % holes.size();

        mole.SetPos(holes[index].GetPos());

        mole.Show();

        spawnTimer = 0.0f;
    }

    if (CheckHitKey(KEY_INPUT_SPACE))
    {
        if (mole.IsVisible())
        {
            VECTOR playerPos = player.GetPos();
            VECTOR molePos = mole.GetPos();

            float dx = playerPos.x - molePos.x;
            float dz = playerPos.z - molePos.z;

            float dist = sqrtf(dx * dx + dz * dz);

            if (dist < 8.0f)
            {
                score += 100;

                mole.Hide();
            }
        }
    }
}

void Game::Draw()
{
    VECTOR playerPos = player.GetPos();

    SetCameraPositionAndTarget_UpVecY(
        VGet(
            playerPos.x,
            playerPos.y + 25.0f,
            playerPos.z - 35.0f),
        playerPos);

    DrawCube3D(
        VGet(-50, -2, -50),
        VGet(50, 0, 50),
        GetColor(0, 180, 0),
        GetColor(0, 180, 0),
        TRUE);

    for (size_t i = 0; i < holes.size(); i++)
    {
        holes[i].Draw();
    }

    player.Draw();
    mole.Draw();

    int remainTime =
        60 - ((GetNowCount() - startTime) / 1000);

    if (remainTime < 0)
        remainTime = 0;

    DrawFormatString(
        20,
        20,
        GetColor(255, 255, 255),
        "Score : %d",
        score);

    DrawFormatString(
        20,
        50,
        GetColor(255, 255, 0),
        "Time : %d",
        remainTime);

    if (remainTime <= 0)
    {
        DrawFormatString(
            250,
            200,
            GetColor(255, 0, 0),
            "GAME OVER");

        DrawFormatString(
            220,
            240,
            GetColor(255, 255, 255),
            "FINAL SCORE : %d",
            score);
    }
}