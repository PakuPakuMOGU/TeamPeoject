
#ifndef GAMESTATE_H
#define GAMESTATE_H

enum GameState {
    GAME_PLAYING,   // ゲーム中
    GAME_PAUSED     // ポーズ中
};

extern GameState gameState;  // ゲーム状態

void InitGameState();         // ゲーム状態の初期化
void ChangeState(GameState newState);  // ゲーム状態の変更

#endif