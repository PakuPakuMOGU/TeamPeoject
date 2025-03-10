#include<Dxlib.h>
#include"enemy.h"
#include"system.h"

static const int windowWidth = 640;  // ウィンドウのサイズ
static const int windowHeight = 480;
static const int colorDepth = 32;    // カラー

const int NUM_SLIMES = 2;  // スライムの数
const int ENEMY = 1;
int maxX = 100;
int minX = 0;

slime slimeArray[NUM_SLIMES] = {
        slime(0, 0,minX,maxX),  // スライムの数だけ初期化
        slime(50, 50,minX,maxX)
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

    slime slimeArray[NUM_SLIMES] = {
        slime(0, 0,minX,maxX),  // 初期位置を指定してスライムを作成
        slime(50, 50,minX,maxX)
    };


    DxLib_End();
    return 0;
}