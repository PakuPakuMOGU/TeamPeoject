#include "DxLib.h"
#include "enemy.h"


slime::slime(int x, int y) :m_x(x), m_y(y){
	m_image = LoadGraph("../assets/Enemy3.png"); // 画像読み込み
}

//メモリ開放のだったが動かない
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
	DrawExtendGraph(m_x, m_y, m_x+60, m_y+60, m_image, TRUE);
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
