#include "DxLib.h"
#include "GameState.h"
#include "Draw.h"

void DrawGame() {
    // ゲーム中の描画処理
    ClearDrawScreen();
    DrawString(200, 200, "ゲーム中", GetColor(100, 255, 255));
}

void DrawPause() {
    // ポーズ画面の描画
    ClearDrawScreen();
    DrawString(200, 200, "ポーズ中", GetColor(100, 255, 255));
    DrawString(200, 220, "Pキーでゲーム再開", GetColor(100, 255, 255));
}