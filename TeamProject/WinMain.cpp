#include<Dxlib.h>
#include "System.h"
#include "Game.h"

#include <Windows.h>

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{  
    ChangeWindowMode(TRUE);
    SetGraphMode(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, 32);
    if (DxLib_Init() == -1) return false;

    Game_Main();
    
    DxLib_End();
    return 0;
}