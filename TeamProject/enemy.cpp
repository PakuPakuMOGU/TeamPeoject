#include "DxLib.h"
#include "enemy.h"

/*static int m_image;//�摜
static int m_y;//y���W
static int m_x;//x���W

//������
void Enemy_Initialize() {
	m_image = LoadGraph("../aseets/Enemy1.png"); // �摜�ǂݍ���
	m_x = 0;//���W
	m_y = 0;
}

//�����̌v�Z
void Enemy_Update() {
	//m_y++;
	//m_x++;
}

//�`��
void Enemy_Draw() {
	DrawExtendGraph(m_x, m_y, 40, 40, m_image, TRUE);
	//DrawExtendGraph(m_x, m_y, m_x+40, m_y+40, m_image, TRUE);
}

//�I��
void Enemy_Finalize() {
	DeleteGraph(m_image);
}*/

slime::slime(int x, int y) :m_x(x), m_y(y){
	m_image = LoadGraph("../aseets/�Q�l�X���C��.png"); // �摜�ǂݍ���
}

/*slime::~slime() {
	DeleteGraph(m_image);
}*/

//�����̌v�Z
void slime::Enemy_Update() {
	m_y++;
	m_x++;
}

//�`��
void slime::Enemy_Draw() {
	DrawExtendGraph(m_x, m_y, m_x+40, m_y+40, m_image, TRUE);
}

//���W��ݒ�
void slime::SetPosition(int x, int y) {
	m_x = x;
	m_y = y;
}

void slime::Enemy_Finalize() {
	DeleteGraph(m_image);
}
