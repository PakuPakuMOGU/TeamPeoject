#include "DxLib.h"
#include "GameState.h"
#include "Input.h"


    void CheckForPause()
    {
        static bool push = false;  // pushをstaticにして状態を保持

        if (CheckHitKey(KEY_INPUT_P)) {
            // まだキーが押されていない場合（押下処理がまだ行われていない）
            if (push == false) {
                push = true;  // キーが押されたことを記録

                // ゲームがプレイ中の場合はポーズをかける
                if (gameState == GAME_PLAYING) {
                    ChangeState(GAME_PAUSED);
                }
                // ゲームがポーズ中の場合はゲームを再開する
                else if (gameState == GAME_PAUSED) {
                    ChangeState(GAME_PLAYING);
                }
            }
        }
        else {
            // Pキーが離れた場合、次回押されたときに反応できるようにする
            push = false;
        }
    }
    
  
   
