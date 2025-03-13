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

//ゴースト
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



//上下に動く
fly::fly(float x, float y, float minY, float maxY, float move) :f_x(x), f_y(y), f_minY(minY), f_maxY(maxY), f_move(move){
	f_image = -1;
   }

int fly::InitFly()
{
	f_image = LoadGraph("../assets/Enemy2.png"); // 画像読み込み
	if (f_image == -1)return -1;
}

//動きの計算
void fly::Fly_Update() {
	f_y += f_move;

	if (f_y >= f_maxY || f_y <= f_minY) {
		f_move *= -1;
	}
}

//描画
void fly::Fly_Draw() {
	DrawGraph(f_x, f_y, f_image, TRUE);
}

//座標を設定
void fly::SetPosition(float x, float y, float minY, float maxY, float move) {
	f_x = x;
	f_y = y;
	f_minY = minY;
	f_maxY = maxY;
	f_move = move;
}

//アタック
void fly::Fly_Attack() {

}

//終了時のメモリ開放
void fly::Fly_Finalize() {
	DeleteGraph(f_image);
}


//四角く動く
cow::cow(int x, int y, float minX, float maxX, float minY, float maxY, float moveX, float moveY)
	: c_x(x), c_y(y), c_minX(minX), c_maxX(maxX), c_minY(minY), c_maxY(maxY), c_moveX(moveX), c_moveY(moveY) {
	c_image = -1;
}

int cow::InitCow()
{
	c_image = LoadGraph("../assets/Enemy4.png"); // 画像読み込み
	if (c_image == -1)return -1;
}

//動きの計算
void cow::Cow_Update() 
{
	switch (moveDirection)
	{
	case 0:  // 右へ
		c_x += c_moveX;
		if (c_x >= c_maxX) {
			c_x = c_maxX;  moveDirection = 1;
		}
		break;
	case 1:  // 下へ
		c_y += c_moveY;
		if (c_y >= c_maxY) {
			c_y = c_maxY;  moveDirection = 2; // 次は左へ
		}
		break;

	case 2:  // 左へ
		c_x -= c_moveX;
		if (c_x <= c_minX) {
			c_x = c_minX;  moveDirection = 3; // 次は上へ
		}
		break;

	case 3:  // 上へ
		c_y -= c_moveY;
		if (c_y <= c_minY) {
			c_y = c_minY;  moveDirection = 0; // 次は右へ
		}
		break;
	}
}

//描画
void cow::Cow_Draw() {

	DrawGraph(c_x, c_y, c_image, TRUE);
}

//座標を設定
void cow::CowSetPosition(int x, int y, float minX, float maxX, float minY, float maxY, float moveX, float moveY) {
	c_x = x;
	c_y = y;
	c_minX = minX;
	c_maxX = maxX;
	c_minY = minY;
	c_maxY = maxY;
	c_moveX = moveX;
	c_moveY = moveY;
}

//終了時のメモリ開放
void cow::Cow_Finalize() {
	DeleteGraph(c_image);
}

//戦車（動かない）
tank::tank(float x, float y) :t_x(x),t_y(y){
	t_image = -1;
}

int tank::InitTank()
{
	t_image = LoadGraph("../assets/Enemy31.png"); // 画像読み込み
	if (t_image == -1)return -1;
}

//描画
void tank::Tank_Draw() {
	//DrawFormatString(10, 100, GetColor(255, 255, 255), " x: %0.2f,   y: %d\n", m_x, m_y);
	DrawGraph(t_x, t_y, t_image, TRUE);
}

//座標を設定
void tank::TankSetPosition(float x, float y) {
	t_x = x;
	t_y = y;
}

//アタック
void tank::Tank_Attack() {

}

//終了時のメモリ開放
void tank::Tank_Finalize() {
	DeleteGraph(t_image);
}