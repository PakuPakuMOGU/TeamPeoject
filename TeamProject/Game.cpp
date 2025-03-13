#include "System.h"
#include "DxLib.h"
#include "enemy.h"

#define CHARASPEED 0.002

#define NUM_SLIMES 2
#define ENEMY 1

#define GAMESIZE 10     // ゲーム画面のサイズ調整用.

int maxX = 100;
int minX = 0;
int minY = 0;
int maxY = 100;
float move = 0.0001f;
float moveX = 0.0001f;
float moveY = 0.0001f;

slime slimeArray[NUM_SLIMES] = {
        slime( 0,  0, minX, maxX,move), // 初期位置を指定してスライムを作成
        slime(50, 50, minX, maxX,move)
};

goes goesArray[ENEMY] = {
        goes(30,30,minX, maxX,minY,maxY,moveX,moveY)
};

struct Player {
    float x;    // プレイヤーの座標.
    float y;    // プレイヤーの座標.
    float imagesize;
    float sizeX;
    float sizeY;
    bool left;

    float speedX;       // プレイヤーのx軸移動.
    float speedY;       // プレイヤーのy軸移動.
};

Player player;

typedef enum Task_GameState
{
    Task_GameState_InGame,				// ゲーム開始.
    Task_GameState_EndGame,				// ゲーム終了.
};

static int imgPlayer;

/* プレイヤーの画像読み込み */
int Init()
{
    imgPlayer = LoadGraph("../assets/Player.png");      
    if (imgPlayer == -1) return false;
}

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
    player.sizeX = 46.0f;
    player.sizeY = 51.0f;
    player.left = false;
    player.speedX = 0;
    player.speedY = 0;

    Init();
    for (int i = 0; i < NUM_SLIMES; i++) {
        slimeArray[i].InitSlime();      // スライムの初期化.
    }
    for (int i = 0; i < ENEMY; i++) {
        goesArray[i].InitGoes();      // スライムの初期化.
    }
    
    while (1) {
        if (CheckHitKey(KEY_INPUT_ESCAPE)) break;   // ESCAPEで終了.

        /* --- キーボード操作 --- */
        player.speedX *= CHARASPEED;
        if (CheckHitKey(KEY_INPUT_A)) { player.speedX = -CHARASPEED; player.left = true; }
        if (CheckHitKey(KEY_INPUT_D)) { player.speedX =  CHARASPEED; player.left = false; }

        player.speedY *= CHARASPEED;
        if (CheckHitKey(KEY_INPUT_W))   player.speedY = -CHARASPEED;
        if (CheckHitKey(KEY_INPUT_S))   player.speedY =  CHARASPEED;

        player.x += player.speedX;
        player.y += player.speedY;


        // プレイヤーの移動処理.
        if (player.x < -GAMESIZE)
            player.x = -GAMESIZE;

        else if (player.x > GAME_SCREEN_WIDTH - player.sizeX - GAMESIZE)
            player.x = GAME_SCREEN_WIDTH - player.sizeX - GAMESIZE;

        if (player.y < -GAMESIZE)
            player.y = -GAMESIZE;

        else if (player.y > GAME_SCREEN_HEIGHT - player.sizeY - GAMESIZE)
            player.y = GAME_SCREEN_HEIGHT - player.sizeY - GAMESIZE;

        //モンスターの移動
        for (int i = 0; i < NUM_SLIMES; i++)
        {
            slimeArray[i].Enemy_Update();
        }

        for (int i = 0; i < ENEMY; i++)
        {
            goesArray[i].Goes_Update();
        }

        ClearDrawScreen();      // 画面初期化.

        if (player.left)    DrawTurnGraph(player.x, player.y, imgPlayer, TRUE);
        else                DrawGraph(player.x, player.y, imgPlayer, TRUE);

        DrawFormatString(10, 10, GetColor(255, 255, 255), "X : %0.2f", player.x);
        DrawFormatString(10, 30, GetColor(255, 255, 255), "Y : %0.2f", player.y);

        for (int i = 0; i < NUM_SLIMES; i++) { slimeArray[i].Enemy_Draw(); }
        for (int i = 0; i < ENEMY;      i++) { goesArray[i].Goes_Draw(); }
    }

    DeleteGraph(imgPlayer);
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