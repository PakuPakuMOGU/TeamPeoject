#include "System.h"
#include "DxLib.h"
#include "enemy.h"
#include "Player.h"

#define CHARASPEED 0.002

#define NUM_SLIMES 2        // 発生させるスライムの数.
#define ENEMY 1             // 発生させるゴーストの数.

int maxX = 100;
int minX = 0;
int minY = 0;
int maxY = 100;
float move = 0.0001f;
float moveX = 0.0001f;
float moveY = 0.0001f;

// プレイヤーの生成.
Player Player(0, 0, 45.0f, 50.0, 10);

// スライムの生成.
slime slimeArray[NUM_SLIMES] = {
        slime( 0,  0, minX, maxX, move),
        slime(50, 50, minX, maxX, move)
};

// ゴーストの生成.
goes goesArray[ENEMY] = {
        goes( 30, 30, minX, maxX, minY, maxY, moveX, moveY)
};

// タスク処理.
typedef enum Task_GameState
{
    Task_GameState_InGame,		// ゲーム開始.
    Task_GameState_NowGame,		// ゲーム中.
    Task_GameState_Attack,		// 攻撃する.
    Task_GameState_Defense,		// 攻撃を受ける.
    Task_GameState_GetItem,		// アイテムの発見.
    Task_GameState_EndGame,		// ゲーム終了.
};

// メイン処理.
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

        /* ---------------------------------------------------------- */
        /* ---------------------------------------------------------- */
        /* --------- この辺りにアイテムを拾う・装備する処理 --------- */
        /* ---------------------------------------------------------- */
        /* ---------------------------------------------------------- */

        // プレイヤーの移動.
        // 斜め移動のときに速度を変えない.
        if (speedX == speedY || speedX == -speedY)
        {
            speedX *= 0.707f;     
            speedY *= 0.707f;
        }   
        Player.RunPosition(speedX, speedY);         // ポジション設定.
        Player.PlayerGameIn();                      // 画面外に行かせない.

        // モンスターの移動.
        for (int i = 0; i < NUM_SLIMES; i++)    slimeArray[i].Enemy_Update();
        for (int i = 0; i < ENEMY;      i++)     goesArray[i].Goes_Update();

        /* ------------------------------------------ */
        /* ------------------------------------------ */
        /* --------- 多分この辺りに攻撃判定 --------- */
        /* ------------------------------------------ */
        /* ------------------------------------------ */

        if (!Player.ReHP())    break;       // プレイヤーのHPがなくなったら終了する.


        // 描画処理.
        ClearDrawScreen();      // 画面初期化.

        Player.Player_Draw();                                               // プレイヤー描画.
        for (int i = 0; i < NUM_SLIMES; i++)  slimeArray[i].Enemy_Draw();   // スライム  描画.
        for (int i = 0; i < ENEMY;      i++)   goesArray[i].Goes_Draw();    // ゴースト  描画.
    }

    Player.Player_Finalize();                                               // プレイヤーの終了処理.
    for (int i = 0; i < NUM_SLIMES; i++)    slimeArray[i].Enemy_Finalize(); // スライム  の終了処理.
    for (int i = 0; i < ENEMY;      i++)     goesArray[i].Goes_Finalize();  // ゴースト  の終了処理.

    return true;
}