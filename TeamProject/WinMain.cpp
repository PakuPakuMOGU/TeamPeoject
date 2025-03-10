#include<Dxlib.h>
#include <Windows.h>

#include "enemy.h"
#include "System.h"
#include "Game.h"

const int NUM_SLIMES = 2;  // ・ｽz・ｽu・ｽ・ｽ・ｽ・ｽX・ｽ・ｽ・ｽC・ｽ・ｽ・ｽﾌ撰ｿｽ
const int ENEMY = 1;
int maxX = 100;
int minX = 0;

    slime slimeArray[NUM_SLIMES] = {
        slime(0, 0,minX,maxX),  // 初期位置を指定してスライムを作成
        slime(50, 50,minX,maxX)
    };

    goes goesArray[ENEMY] = {
        goes(30,30)
    };


int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{  
    ChangeWindowMode(TRUE);
    SetGraphMode(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, 32);
    if (DxLib_Init() == -1) return false;

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
    {
        for (int i = 0; i < NUM_SLIMES; i++)
        {
            slimeArray[i].Enemy_Update();
            slimeArray[i].Enemy_Draw();
        }
        for (int i = 0; i < ENEMY; i++)
        {
            goesArray[i].Goes_Update();
            goesArray[i].Goes_Draw();
        }
    }

    for (int i = 0; i < NUM_SLIMES; i++)
    {
        slimeArray[i].Enemy_Finalize();
    }
    for (int i = 0; i < ENEMY; i++)
    {
        goesArray[i].Goes_Finalize();
    }
    

    Game_Main();
    
    DxLib_End();
    return 0;

}