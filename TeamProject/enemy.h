#ifndef ENEMY_H //インクルード2重防止

#define ENEMY_H

class slime {
public:
	slime(int x,int y);//初期化

	void Enemy_Update();//移動
	void Enemy_Draw();//描画

	void SetPosition(int x, int y);//ポジション設定
	void Enemy_Finalize();//データ開放

	//動かしたくないもの
private:
	int m_image;
	int m_y, m_x;
};

#endif

