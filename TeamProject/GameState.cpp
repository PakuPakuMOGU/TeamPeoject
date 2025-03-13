
#include "DxLib.h"
#include "GameState.h"

GameState gameState = GAME_PLAYING;  // ‰Šúó‘Ô‚ÍƒQ[ƒ€’†

void InitGameState() {
    gameState = GAME_PLAYING;
}

void ChangeState(GameState newState) {
    gameState = newState;
}