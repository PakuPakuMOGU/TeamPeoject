
#include "DxLib.h"

void DrawMenuBoxes()
{
    unsigned int Cr = GetColor(255, 255, 255);  // 白色
    unsigned int Cr2 = GetColor(200, 200, 255); // 薄い青色

    // 1つ目のボックス
    DrawBoxAA(400.0f, 0.0f, 500.0f, 480.0f, Cr, TRUE);

    // 2つ目のボックス
    DrawBoxAA(0.0f, 0.0f, 100.0f, 480.0f, Cr2, TRUE);
}