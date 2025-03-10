#include<Dxlib.h>

static const int windowWidth = 640;  // ウィンドウのサイズ(DxLibのデフォルトサイズと同じ)
static const int windowHeight = 480;
static const int colorDepth = 32;    // 32bit カラーを使用する

const int NUM_SLIMES = 2;  // �z�u����X���C���̐�
const int ENEMY = 1;

    slime slimeArray[NUM_SLIMES] = {
        slime(0, 0),  // �����ʒu���w�肵�ăX���C�����쐬
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

    int a = 0;
    while (a == 0) {
        DrawFormatString(10, 25, GetColor(255, 255, 255), "HelloWorld!!");
        if (CheckHitKey(KEY_INPUT_A))    a++;
    }
    DxLib_End();
    return 0;

}