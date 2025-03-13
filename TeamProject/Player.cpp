#include "DxLib.h"
#include "System.h"
#include "Player.h"

Player::Player(float x, float y, float size_x, float size_y, int hp) :playerX(x), playerY(y), sizeX(size_x), sizeY(size_y), player_hp(hp)
{
	player_image = -1;
}

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

void Player::AddDelHP(int hp)
{
	player_hp += hp;
}

void Player::AddDelMAXHP(int hp)
{
	player_maxhp += hp;
}

void Player::AddDelATK(int atk)
{
	player_atk += atk;
}

void Player::AddDelDEF(int def)
{
	player_def += def;
}

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

void Player::Player_Draw() {
	if (left)    DrawTurnGraph(playerX, playerY, player_image, TRUE);
	else         DrawGraph(	   playerX, playerY, player_image, TRUE);

	DrawFormatString(10, 10, GetColor(255, 255, 255), "X : %0.2f", playerX);
	DrawFormatString(10, 30, GetColor(255, 255, 255), "Y : %0.2f", playerY);
}

float Player::ReX(void)
{
	return playerX;
}
float Player::ReY(void)
{
	return playerY;
}
int Player::ReHP(void)
{
	return player_hp;
}

//データ開放
void Player::Player_Finalize()
{
	DeleteGraph(player_image);
}