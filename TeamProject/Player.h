#ifndef PLAYER_H //インクルード2重防止

#define PLAYER_H

class Player {
public:
	Player(float x, float y, float size_x, float size_y, int hp); //初期化.

	int InitPlayer();	//画像の読み込み.
	void Player_Draw(); //描画.

	void SetPosition(float x, float y); // ポジション設定.
	void RunPosition(float x, float y);
	void PlayerGameIn();				// 移動範囲設定.
	void Player_Attack();				// 攻撃判定.
	void Player_Finalize();				// データ開放.

	void AddDelHP(int hp);
	void AddDelMAXHP(int hp);
	void AddDelATK(int atk);
	void AddDelDEF(int def);

	float ReX(void);
	float ReY(void);
	int ReHP();

	bool left = false;

private:
	int player_image;
	float playerX = 0.0f, playerY = 0.0f;
	float sizeX = 0.0f;   // プレイヤーの当たり判定サイズX.
	float sizeY = 0.0f;   // プレイヤーの当たり判定サイズY.
	float speed_x = 0.0f;
	float speed_y = 0.0f;

	// プレイヤーのステータス.
	int player_hp = 10;
	int player_maxhp = 10;
	int player_atk = 5;
	int player_def = 5;
	int cost = 0;
	int maxcost = 15;
};

#endif