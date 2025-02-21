#include<Dxlib.h>
#include "enemy.h"

static const int windowWidth = 640;  // ウィンドウのサイズ(DxLibのデフォルトサイズと同じ)
static const int windowHeight = 480;
static const int colorDepth = 32;    // 32bit カラーを使用する

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    SetGraphMode(windowWidth, windowHeight, colorDepth);
    ChangeWindowMode(TRUE);
    if (DxLib_Init() == -1) return -1;

    Enemy_Initialize();

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) 
    {
        Enemy_Update();
        Enemy_Draw();
    }

        Enemy_Finalize();

        DxLib_End();
        return 0;
}