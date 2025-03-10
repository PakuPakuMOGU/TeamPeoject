#include "DxLib.h"
#include "Map.h"
#include "Menu.h"
int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
   
   
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

        // Menu.cpp の DrawMenuBoxes 関数を呼び出す
        DrawMenuBoxes();  // ここでボックスを描画

        ScreenFlip();  // バックバッファを画面に反映
       
       
    }

    map.DeleteGraphics();  // グラフィックの解放
    DxLib_End();
    return 0;
}