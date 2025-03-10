#include<Dxlib.h>
#include"enemy.h"
#include"system.h"

static const int windowWidth = 640;  // 繧ｦ繧｣繝ｳ繝峨え縺ｮ繧ｵ繧､繧ｺ(DxLib縺ｮ繝・ヵ繧ｩ繝ｫ繝医し繧､繧ｺ縺ｨ蜷後§)
static const int windowHeight = 480;
static const int colorDepth = 32;    // 32bit 繧ｫ繝ｩ繝ｼ繧剃ｽｿ逕ｨ縺吶ｋ

const int NUM_SLIMES = 2;  // 繧ｹ繝ｩ繧､繝縺ｮ謨ｰ.
const int ENEMY = 1;
int maxX = 100;
int minX = 0;

slime slimeArray[NUM_SLIMES] = {
        slime(0, 0),  // 蛻晄悄蛹厄ｼ滓枚蟄怜喧縺代＠縺ｦ縺ｦ蛻・°繧峨↑縺・
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

    slime slimeArray[NUM_SLIMES] = {
        slime(0, 0,minX,maxX),  // 初期位置を指定してスライムを作成
        slime(50, 50,minX,maxX)
    };


    DxLib_End();
    return 0;
}