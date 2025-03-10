
#include "DxLib.h"

void DrawMenuBoxes()
{
    unsigned int Cr = GetColor(255, 255, 255);  // 白色
    unsigned int Cr2 = GetColor(255, 255, 255); // 薄い青色

    // 1つ目のボックス
   DrawBoxAA(1680.0f, 0.0f, 1980.0f, 1080.0f, Cr, TRUE);

    // 2つ目のボックス
    DrawBoxAA(0.0f, 0.0f, 300.0f, 1080.0f, Cr2, TRUE);
}