#include "DxLib.h"
#include "enemy.h"

//スライム用

slime::slime(int x, int y) :m_x(x), m_y(y){
	m_image = LoadGraph("../assets/Enemy40.png"); // 画像読み込み
}
//動きの計算
void slime::Enemy_Update() {
	//m_y++;
	m_x++;
}

//描画
void slime::Enemy_Draw() {
	DrawGraph(m_x+40, m_y+40, m_image, TRUE);
}

//座標を設定
void slime::SetPosition(int x, int y) {
	m_x = x;
	m_y = y;
}

//終了時のメモリ開放
void slime::Enemy_Finalize() {
	DeleteGraph(m_image);
}


//動き１
goes::goes(int x, int y) :m_x(x), m_y(y) {
	g_image = LoadGraph("../assets/Enemy9.png"); // 画像読み込み
}

//動きの計算
void goes::Goes_Update() {
	m_y++;
	m_x++;
}

//描画
void goes::Goes_Draw() {
	DrawGraph(m_x, m_y, g_image, TRUE);
}

//座標を設定
void goes::GoesSetPosition(int x, int y) {
	m_x = x;
	m_y = y;
}

//終了時のメモリ開放
void goes::Goes_Finalize() {
	DeleteGraph(g_image);
}