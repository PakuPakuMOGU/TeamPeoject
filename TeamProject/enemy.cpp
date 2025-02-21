#include "DxLib.h"
#include "enemy.h"

static int m_image;//画像
static int m_y;//座標

//初期化
void Enemy_Initialize() {
	m_image = LoadGraph("../aseets/参考スライム.png");
	m_y = 0;
}

//動きの計算
void Enemy_Update() {
	m_y++;
}

//描画
void Enemy_Draw() {
	DrawGraph(0, m_y, m_image, TRUE);
}

//終了
void Enemy_Finalize() {
	DeletGraph(m_image);
}