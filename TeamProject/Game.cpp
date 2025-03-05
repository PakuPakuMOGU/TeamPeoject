#include "System.h"
#include "DxLib.h"

#define CHARASPEED 0.002;

struct Player {
    float x;    // 画像左上のX座標.
    float y;    // 画像左上のY座標.
    int size;

    bool directionLeft; // 画像の向き指定.
    float speedX;       // X軸方向の速度.
    float speedY;       // Y軸方向の速度.
};

typedef enum Task_GameState
{
    Task_GameState_InGame,				// ゲーム中.
    Task_GameState_EndGame,				// ゲーム終了.
}Task_GameState;

static int imgPlayer;

int Init()
{
    imgPlayer = LoadGraph("../assets/参考スライム.png");      // プレイヤーの画像.
    if (imgPlayer == -1) return false;
}

Player player;

int ReX(void)
{
    return player.x;
}
int ReY(void)
{
    return player.y;
}

bool Game_Main(void)
{
    player.x = 0.0f;
    player.y = 0.0f;
    player.size = 40 * 0.7;
    player.speedX = 0; // 初期速度.
    player.speedY = 0; // 初期速度.

    Init();
    
    while (1) {
        if (CheckHitKey(KEY_INPUT_ESCAPE)) break;   // ESCAPEで終了.

        /* --- キーボード入力 --- */
        player.speedX *= CHARASPEED;
        if(CheckHitKey(KEY_INPUT_A))      player.speedX  = -CHARASPEED;
        if(CheckHitKey(KEY_INPUT_D))      player.speedX  =  CHARASPEED;                       

        player.speedY *= CHARASPEED;
        if(CheckHitKey(KEY_INPUT_W))      player.speedY  = -CHARASPEED;
        if(CheckHitKey(KEY_INPUT_S))      player.speedY  =  CHARASPEED;    

        player.x += player.speedX;
        player.y += player.speedY;


        // マップ外に行かせない.
        if (player.x < -player.size * 0.45)   
            player.x = -player.size * 0.4;

        else if (player.x > GAME_SCREEN_WIDTH - player.size * 2)
                 player.x = GAME_SCREEN_WIDTH - player.size * 2;

        if (player.y < 0 - player.size * 0.45)
            player.y = 0 - player.size * 0.45;

        else if (player.y > GAME_SCREEN_HEIGHT - player.size * 2.2)
                 player.y = GAME_SCREEN_HEIGHT - player.size * 2.2;

        
        ClearDrawScreen();      // 描画の消去.

        DrawGraph(player.x, player.y, imgPlayer, TRUE);
        DrawFormatString(10, 10, GetColor(255, 255, 255), "X : %0.2f", player.x);
        DrawFormatString(10, 30, GetColor(255, 255, 255), "Y : %0.2f", player.y);
    }
    //DeleteGraph(imgPlayer);

    return true;
}