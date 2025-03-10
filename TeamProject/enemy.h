#ifndef ENEMY_H //インクルード2重防止

#define ENEMY_H

class slime {
public:
	slime(int x,int y);//初期化

	void Enemy_Update();//移動
	void Enemy_Draw();//描画

	void SetPosition(int x, int y);//ポジション設定
	void Enemy_Attack();//攻撃判定
	void Enemy_Finalize();//データ開放

	//動かしたくないもの
private:
	int m_image;
	int m_y, m_x;
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

