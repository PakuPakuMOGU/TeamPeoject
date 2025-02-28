#include "DxLib.h"
#include "enemy.h"


slime::slime(int x, int y) :m_x(x), m_y(y){
	m_image = LoadGraph("../assets/Enemy3.png"); // �摜�ǂݍ���
}

//�������J���̂������������Ȃ�
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
	DrawExtendGraph(m_x, m_y, m_x+60, m_y+60, m_image, TRUE);
}

//���W��ݒ�
void slime::SetPosition(int x, int y) {
	m_x = x;
	m_y = y;
}

//�I�����̃������J��
void slime::Enemy_Finalize() {
	DeleteGraph(m_image);
}
