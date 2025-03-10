#include<Dxlib.h>
#include"enemy.h"
#include"system.h"

static const int colorDepth = 32;    // ÉJÉâÅ[

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{  
    ChangeWindowMode(TRUE);
    if (DxLib_Init() == -1) return -1;

    System_Main();

    DxLib_End();
    return 0;
}