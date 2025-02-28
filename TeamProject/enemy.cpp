#include "DxLib.h"
#include "enemy.h"

/*static int m_image;//画像
static int m_y;//y座標
static int m_x;//x座標

//初期化
void Enemy_Initialize() {
	m_image = LoadGraph("../aseets/Enemy1.png"); // 画像読み込み
	m_x = 0;//座標
	m_y = 0;
}

//動きの計算
void Enemy_Update() {
	//m_y++;
	//m_x++;
}

//描画
void Enemy_Draw() {
	DrawExtendGraph(m_x, m_y, 40, 40, m_image, TRUE);
	//DrawExtendGraph(m_x, m_y, m_x+40, m_y+40, m_image, TRUE);
}

//終了
void Enemy_Finalize() {
	DeleteGraph(m_image);
}*/

slime::slime(int x, int y) :m_x(x), m_y(y){
	m_image = LoadGraph("../aseets/参考スライム.png"); // 画像読み込み
}

/*slime::~slime() {
	DeleteGraph(m_image);
}*/

//動きの計算
void slime::Enemy_Update() {
	m_y++;
	m_x++;
}

//描画
void slime::Enemy_Draw() {
	DrawExtendGraph(m_x, m_y, m_x+40, m_y+40, m_image, TRUE);
}

//座標を設定
void slime::SetPosition(int x, int y) {
	m_x = x;
	m_y = y;
}

void slime::Enemy_Finalize() {
	DeleteGraph(m_image);
}
