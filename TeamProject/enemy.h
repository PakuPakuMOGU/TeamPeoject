#ifndef ENEMY_H //�C���N���[�h2�d�h�~

#define ENEMY_H

class slime {
public:
	slime(int x,int y);

	void Enemy_Update();
	void Enemy_Draw();

	void SetPosition(int x, int y);
	void Enemy_Finalize();

private:
	int m_image;
	int m_y, m_x;
};



#endif

