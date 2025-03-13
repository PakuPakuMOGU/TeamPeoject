#include "DxLib.h"
#include "System.h"
#include "Player.h"

Player::Player(float x, float y, float size_x, float size_y, int hp) :playerX(x), playerY(y), sizeX(size_x), sizeY(size_y), player_hp(hp)
{
	player_image = -1;
}

// プレイヤーの画像の読み込み.
int Player::InitPlayer()
{
	player_image = LoadGraph("../assets/Player.png");
	if (player_image == -1) return false;
}

// 座標を設定.
void Player::SetPosition(float x, float y) {
	playerX = x;
	playerY = y;
}

// 指定した分移動.
void Player::RunPosition(float x, float y) {
	playerX += x;
	playerY += y;
}

// 攻撃判定.
void Player::Player_Attack()
{

}

// 現在のHPの変動.
void Player::AddDelHP(int hp)
{
	player_hp += hp;

	// 最大HPを超えないように設定.
	if (player_hp > player_maxhp)
		player_hp = player_maxhp;

	// HPがマイナスにならないように設定.
	else if (player_hp < 0)
		player_hp = 0;
}

// 最大HPの変動.
void Player::AddDelMAXHP(int hp)
{
	player_maxhp += hp;

	// 1を下回らないように設定.
	if (player_maxhp < 1)
		player_maxhp = 1;
}

// ATKの変動.
void Player::AddDelATK(int atk)
{
	player_atk += atk;

	// 1を下回らないように設定.
	if (player_atk < 1)
		player_atk = 1;
}

// DEFの変動.
void Player::AddDelDEF(int def)
{
	player_def += def;

	// 1を下回らないように設定.
	if (player_def < 1)
		player_def = 1;
}

// 画面外に行かないように設定.
void Player::PlayerGameIn()
{
	if (playerX < -GAMESIZE)
		playerX = -GAMESIZE;

	else if (playerX > GAME_SCREEN_WIDTH - sizeX - GAMESIZE)
		playerX = GAME_SCREEN_WIDTH - sizeX - GAMESIZE;

	if (playerY < -GAMESIZE)
		playerY = -GAMESIZE;

	else if (playerY > GAME_SCREEN_HEIGHT - sizeY - GAMESIZE)
		playerY = GAME_SCREEN_HEIGHT - sizeY - GAMESIZE;
}

// プレイヤーの描画.
void Player::Player_Draw() {
	if (left)    DrawTurnGraph(playerX, playerY, player_image, TRUE);	// 左向きに描画.
	else         DrawGraph(	   playerX, playerY, player_image, TRUE);	// 右向きに描画.

	DrawFormatString(10, 10, GetColor(255, 255, 255), "X : %0.2f", playerX);
	DrawFormatString(10, 30, GetColor(255, 255, 255), "Y : %0.2f", playerY);
}

// プレイヤーのX座標を返す.
float Player::ReX(void)
{
	return playerX;
}

// プレイヤーのY座標を返す.
float Player::ReY(void)
{
	return playerY;
}

// プレイヤーのHPを返す.
int Player::ReHP(void)
{
	return player_hp;
}

//データ開放
void Player::Player_Finalize()
{
	DeleteGraph(player_image);
}