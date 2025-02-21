#include "DxLib.h"
//ウィンドウサイズ仮置き
static const int windowWidth = 500;
static const int windowHeight = 400;
//32bitカラー使用
static const int colorDepth = 32;
//マップチップサイズ仮置き
static const int MapChipsize = 64;
//マップサイズ仮置き
static const int mapWidth = 10;      
static const int mapHeight = 8; 

static const int mapData[mapHeight][mapWidth] =
{
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
    { 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
    { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
    { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    ChangeWindowMode(TRUE); // ウィンドウモードに変更
    SetGraphMode(windowWidth, windowHeight, colorDepth); // 解像度とカラー設定
    
    if (DxLib_Init() == -1) 
    {
        return -1; // 初期化失敗の場合、終了
    }

    //画像読み込み仮置き
    int imgPlayer = LoadGraph("../assets/player.png");
    int imgFloor = LoadGraph("../assets/floor.png");
    int imgWall = LoadGraph("../assets/wall.png");

    SetDrawScreen(DX_SCREEN_BACK);
    while (1)
    {
        ClearDrawScreen();

        for (int j = 0; j < mapHeight; ++j) {
            for (int i = 0; i < mapWidth; ++i) {
                // 描画する座標を計算する
                int x = i * MapChipsize;
                int y = j * MapChipsize;

                // mapDataを参照して背景かブロックかを描き分ける
                if (mapData[j][i] == 0) {
                    // 床
                    DrawGraph(x, y, imgFloor, FALSE);
                }
                else if (mapData[j][i] == 1) {
                    // 壁
                    DrawGraph(x, y, imgWall, TRUE);
                }
            }
        }
    }
    DeleteGraph(imgFloor);
    DeleteGraph(imgWall);
    DeleteGraph(imgPlayer);
    DxLib_End();
    return 0;

    
}