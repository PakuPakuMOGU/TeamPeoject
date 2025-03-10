
#ifndef MAP_H
#define MAP_H

#include "DxLib.h"

struct Map {
    static const int mapWidth = 10;    // マップの横のサイズ
    static const int mapHeight = 8;    // マップの縦のサイズ
    static const int MapChipsize = 64; // マップチップのサイズ（仮置き）

    // マップデータ（0: 床, 1: 壁, 2: 壁, 3: ドアなど）
    int mapData[mapHeight][mapWidth];

    // グラフィックデータ
    int imgFloor;
    int imgWall;
    int imgPlayer;

    // コンストラクタ
    Map();

   
 void DrawMap() const;

    // グラフィックのロード
    void LoadGraphics();

    // グラフィックの解放
    void DeleteGraphics();

   
};





#endif // MAP_H