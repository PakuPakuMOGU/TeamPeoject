#ifndef ENEMY_H //インクルード2重防止

#define ENEMY_H

class slime {
public:
	
	slime(float x, float y, float minX, float maxX);//初期化

	void Enemy_Update();//移動
	void Enemy_Draw();//描画

	void SetPosition(float x, float y, float minX, float maxX);//ポジション設定
	void Enemy_Attack();//攻撃判定
	void Enemy_Finalize();//データ開放

	//動かしたくないもの
private:
	int m_image;
	float m_y, m_x,m_minX,m_maxX;
	float m_move = 0.01f;//一回に移動する距離
};

class goes {
public:
	goes(int x, int y);//初期化

	void Goes_Update();//移動
	void Goes_Draw();//描画

	void GoesSetPosition(int x, int y);//ポジション設定
	void Goes_Finalize();//データ開放

	//動かしたくないもの
private:
	int g_image;
	int m_y, m_x;
};


#endif

