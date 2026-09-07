#include "DxLib.h"
#include "Game.h"

int WINAPI WinMain(
    HINSTANCE,
    HINSTANCE,
    LPSTR,
    int)
{
    ChangeWindowMode(TRUE);

    if (DxLib_Init() == -1)
    {
        return -1;
    }

    SetDrawScreen(DX_SCREEN_BACK);

    Game game;

    game.Initialize();

    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();

        game.Update();

        game.Draw();

        ScreenFlip();
    }

    DxLib_End();

    return 0;
}