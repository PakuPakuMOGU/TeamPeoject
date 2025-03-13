#include "DxLib.h"
void DrawItem()
{
    int GHandle;

    // 画像ファイルを読み込み、グラフィックハンドルを取得
    GHandle = LoadGraph("test1.bmp");

    // 読みこんだグラフィックを拡大描画
    DrawExtendGraph(100, 0, 100 + 130 * 2, 0 + 480, GHandle, TRUE);

    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph(GHandle);

    
    DxLib_End();  // ＤＸライブラリ使用の終了処理
}