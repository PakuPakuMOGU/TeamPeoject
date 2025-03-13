#include "System.h"
#include "DxLib.h"
#include "enemy.h"
#include "Player.h"

#define CHARASPEED 0.002

#define NUM_SLIMES 2
#define ENEMY 1

int maxX = 100;
int minX = 0;
int minY = 0;
int maxY = 100;
float move = 0.0001f;
float moveX = 0.0001f;
float moveY = 0.0001f;

slime slimeArray[NUM_SLIMES] = {
        slime( 0,  0, minX, maxX, move), // 初期位置を指定してスライムを作成
        slime(50, 50, minX, maxX, move)
};

goes goesArray[ENEMY] = {
        goes( 30, 30, minX, maxX, minY, maxY, moveX, moveY)
};

Player Player(0, 0, 45.0f, 50.0, 10);

typedef enum Task_GameState
{
    Task_GameState_InGame,				// ゲーム開始.
    Task_GameState_EndGame,				// ゲーム終了.
};

bool Game_Main(void)
{
    float speedX = 0.0f;
    float speedY = 0.0f;

    Player.InitPlayer();
    for (int i = 0; i < NUM_SLIMES; i++) {
        slimeArray[i].InitSlime();      // スライムの初期化.
    }
    for (int i = 0; i < ENEMY; i++) {
        goesArray[i].InitGoes();        // スライムの初期化.
    }
    
    while (1) {
        if (CheckHitKey(KEY_INPUT_ESCAPE)) break;   // ESCAPEで終了.

        /* --- キーボード操作 --- */
        speedX *= CHARASPEED;
        if (CheckHitKey(KEY_INPUT_A)) { speedX = -CHARASPEED;  Player.left = true; }
        if (CheckHitKey(KEY_INPUT_D)) { speedX =  CHARASPEED;  Player.left = false; }

        speedY *= CHARASPEED;
        if (CheckHitKey(KEY_INPUT_W))   speedY = -CHARASPEED;
        if (CheckHitKey(KEY_INPUT_S))   speedY =  CHARASPEED;

        if (speedX == speedY)
        {
            speedX = speedX * 0.707;      // 斜め移動のときに速度を変えない.
            speedY = speedY * 0.707;
        }

        // プレイヤーの移動.
        Player.RunPosition(speedX, speedY);
        Player.PlayerGameIn();

        // モンスターの移動.
        for (int i = 0; i < NUM_SLIMES; i++)
        {
            slimeArray[i].Enemy_Update();
        }

        for (int i = 0; i < ENEMY; i++)
        {
            goesArray[i].Goes_Update();
        }

        ClearDrawScreen();      // 画面初期化.

        if (!Player.ReHP())    break;

        Player.Player_Draw();
        for (int i = 0; i < NUM_SLIMES; i++) { slimeArray[i].Enemy_Draw(); }
        for (int i = 0; i < ENEMY;      i++) { goesArray[i].Goes_Draw(); }
    }

    Player.Player_Finalize();
    for (int i = 0; i < NUM_SLIMES; i++)
    {
        slimeArray[i].Enemy_Finalize();
    }
    for (int i = 0; i < ENEMY; i++)
    {
        goesArray[i].Goes_Finalize();
    }

    return true;
}