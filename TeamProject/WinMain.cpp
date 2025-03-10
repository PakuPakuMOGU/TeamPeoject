#include<Dxlib.h>
#include"enemy.h"
#include"system.h"

static const int windowWidth = 640;  // ウィンドウのサイズ(DxLibのデフォルトサイズと同じ)
static const int windowHeight = 480;
static const int colorDepth = 32;    // 32bit カラーを使用する

const int NUM_SLIMES = 2;  // スライムの数.
const int ENEMY = 1;

slime slimeArray[NUM_SLIMES] = {
        slime(0, 0),  // 初期化？文字化けしてて分からない.
        slime(50, 50)
};

goes goesArray[ENEMY] = {
        goes(30,30)
};

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{  
    ChangeWindowMode(TRUE);
    if (DxLib_Init() == -1) return -1;

    System_Main();

    DxLib_End();
    return 0;
}