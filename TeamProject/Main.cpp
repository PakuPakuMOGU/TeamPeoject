#include "DxLib.h"
#include "Map.h"
#include "Menu.h"
#include "GameState.h"
#include "Input.h"
#include "Draw.h"

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{

    

    // 解像度とカラー設定
    SetGraphMode(1920, 1080, 32);
    if (DxLib_Init() == -1) {
        return -1; // 初期化失敗の場合、終了
    }

    // Mapインスタンスの作成
    Map map;
    map.LoadGraphics();  // グラフィックの読み込み

    // ゲーム状態の初期化
    InitGameState();

    SetDrawScreen(DX_SCREEN_BACK);

    while (1) {
        ClearDrawScreen();  // 画面をクリア
        // メニューを描画 (ポーズ中に表示するメニューなど)
        DrawMenuBoxes();  // メニューのボックスを描画
        // 入力処理 (ポーズ状態の切り替えなど)
        CheckForPause();

        // ゲームの状態に応じた描画処理
        if (gameState == GAME_PLAYING) {
            map.DrawMap();  // ゲーム中のマップ描画
        }
        else if (gameState == GAME_PAUSED) {
            DrawPause();  // ポーズ画面の描画
        }

      

        // 画面更新
        ScreenFlip();

        if (CheckHitKey(KEY_INPUT_ESCAPE)) {
            break; // ESCキーで終了
        }
    }

    // 終了処理
    map.DeleteGraphics();  // グラフィックの解放
    DxLib_End();
    return 0;
}