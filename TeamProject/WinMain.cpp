#include<Dxlib.h>
#include "enemy.h"

static const int windowWidth = 640;  // �E�B���h�E�̃T�C�Y(DxLib�̃f�t�H���g�T�C�Y�Ɠ���)
static const int windowHeight = 480;
static const int colorDepth = 32;    // 32bit �J���[���g�p����
const int NUM_SLIMES = 2;  // �z�u����X���C���̐�

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    SetGraphMode(windowWidth, windowHeight, colorDepth);
    ChangeWindowMode(TRUE);
    if (DxLib_Init() == -1) return -1;

    slime slimeArray[NUM_SLIMES] = {
        slime(0, 0),  // �����ʒu���w�肵�ăX���C�����쐬
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