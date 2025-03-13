#ifndef ENEMY_H //インクルード2重防止

#define ENEMY_H

class slime {
public:
	
	slime(float x, float y, float minX, float maxX, float move);//初期化

	int InitSlime();	//画像の読み込み
	void Enemy_Update();//移動
	void Enemy_Draw();//描画

	void SetPosition(float x, float y, float minX, float maxX, float move);//ポジション設定
	void Enemy_Attack();//攻撃判定
	void Enemy_Finalize();//データ開放

	//動かしたくないもの
private:
	int m_image;
	float m_y, m_x,m_minX,m_maxX,m_move;
};

class goes {
public:
	goes(int x, int y, float minX, float maxX, float minY, float maxY, float moveX, float moveY);//初期化

	int InitGoes();	//画像の読み込み
	void Goes_Update();//移動
	void Goes_Draw();//描画

	void GoesSetPosition(int x, int y, float minX, float maxX, float minY, float maxY, float moveX, float moveY);//ポジション設定
	void Goes_Finalize();//データ開放

	//動かしたくないもの
private:
	int g_image;
	float g_y, g_x, g_minX, g_maxX, g_minY, g_maxY,g_moveX,g_moveY;
};

class fly {
public:

	fly(float x, float y, float minY, float maxY, float move);//初期化

	int InitFly();	//画像の読み込み
	void Fly_Update();//移動
	void Fly_Draw();//描画

	void SetPosition(float x, float y, float minY, float maxY, float move);//ポジション設定
	void Fly_Attack();//攻撃判定
	void Fly_Finalize();//データ開放

	//動かしたくないもの
private:
	int f_image;
	float f_y, f_x, f_minY, f_maxY, f_move;
};
#endif

