#include<Dxlib.h>
#include "enemy.h"

static const int windowWidth = 640;  // ウィンドウのサイズ(DxLibのデフォルトサイズと同じ)
static const int windowHeight = 480;
static const int colorDepth = 32;    // 32bit カラーを使用する
const int NUM_SLIMES = 2;  // 配置するスライムの数

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    SetGraphMode(windowWidth, windowHeight, colorDepth);
    ChangeWindowMode(TRUE);
    if (DxLib_Init() == -1) return -1;

    slime slimeArray[NUM_SLIMES] = {
        slime(0, 0),  // 初期位置を指定してスライムを作成
        slime(50, 50)
    };

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
    {
        for (int i = 0; i < NUM_SLIMES; i++)
        {
            slimeArray[i].Enemy_Update();
            slimeArray[i].Enemy_Draw();
        }
    }

    for (int i = 0; i < NUM_SLIMES; i++)
    {
        slimeArray[i].Enemy_Finalize();
    }
        DxLib_End();
        return 0;
}