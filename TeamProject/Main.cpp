#include "DxLib.h"
#include "Map.h"

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    unsigned int Cr;
    unsigned int Cr2;
   
    ChangeWindowMode(TRUE); // ウィンドウモードに変更
    SetGraphMode(500, 400, 32); // 解像度とカラー設定

    if (DxLib_Init() == -1)
    {
        return -1; // 初期化失敗の場合、終了
    }

    // Mapインスタンスの作成
    Map map;
   
    map.LoadGraphics();  // グラフィックの読み込み

    SetDrawScreen(DX_SCREEN_BACK);

   

    while (1)
    {
        ClearDrawScreen();

        if (CheckHitKey(KEY_INPUT_ESCAPE)) { // ESCキーが押された場合
            break; // ループを抜けて終了処理へ
        }

        map.DrawMap();  // マップを描画
        Cr = GetColor(255, 255, 255);
        Cr2 = GetColor(200, 200, 255);
      DrawBoxAA(400.0f, 0.0f, 500.0f, 480.0f, Cr, TRUE);
        DrawBoxAA(0.0f, 0.0f, 100.0f, 480.0f, Cr, TRUE);
        ScreenFlip();  // バックバッファを画面に反映
       
    }

    map.DeleteGraphics();  // グラフィックの解放
    DxLib_End();
    return 0;
}