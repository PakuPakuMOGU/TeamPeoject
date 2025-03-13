#include "DxLib.h"
#include "enemy.h"


//スライム用
slime::slime(float x, float y, float minX, float maxX,float move) :m_x(x), m_y(y),m_minX(minX),m_maxX(maxX),m_move(move){
	m_image = -1;
}

int slime::InitSlime()
{
	m_image = LoadGraph("../assets/Enemy40.png"); // 画像読み込み
	if (m_image == -1)return -1;
}

//動きの計算
void slime::Enemy_Update() {
	m_x += m_move;

	if (m_x >= m_maxX || m_x <= m_minX) {
		m_move *= -1;
	}
}

//描画
void slime::Enemy_Draw() {
	//DrawFormatString(10, 100, GetColor(255, 255, 255), " x: %0.2f,   y: %d\n", m_x, m_y);
	DrawGraph(m_x, m_y, m_image, TRUE);
}

//座標を設定
void slime::SetPosition(float x, float y, float minX, float maxX, float move) {
	m_x = x;
	m_y = y;
	m_minX = minX;
	m_maxX = maxX;
	m_move = move;
}

//アタック
void slime::Enemy_Attack() {

}

//終了時のメモリ開放
void slime::Enemy_Finalize() {
	DeleteGraph(m_image);
}

//動き１
goes::goes(int x, int y, float minX, float maxX, float minY, float maxY, float moveX, float moveY)
	: g_x(x), g_y(y), g_minX(minX), g_maxX(maxX), g_minY(minY), g_maxY(maxY), g_moveX(moveX), g_moveY(moveY) {
	g_image = -1;
}

int goes::InitGoes()
{
	g_image = LoadGraph("../assets/Enemy9.png"); // 画像読み込み
	if (g_image == -1)return -1;
}

//動きの計算
void goes::Goes_Update() {
	g_y += g_moveY;
	g_x += g_moveX;

	if (g_x >= g_maxX || g_x <= g_minX) {
		g_moveX *= -1;
	}
	if (g_y >= g_maxY || g_y <= g_minY) {
		g_moveY *= -1;
	}
}

//描画
void goes::Goes_Draw() {
	
	DrawGraph(g_x, g_y, g_image, TRUE);
}

//座標を設定
void goes::GoesSetPosition(int x, int y, float minX, float maxX, float minY, float maxY, float moveX, float moveY) {
	g_x = x;
	g_y = y;
	g_minX = minX;
	g_maxX = maxX;
	g_minY = minY;
	g_maxY = maxY;
	g_moveX = moveX;
	g_moveY = moveY;
}

//終了時のメモリ開放
void goes::Goes_Finalize() {
	DeleteGraph(g_image);
}