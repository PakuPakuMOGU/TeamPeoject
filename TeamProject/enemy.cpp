#include "DxLib.h"
#include "enemy.h"

static int m_image;//�摜
static int m_y;//���W

//������
void Enemy_Initialize() {
	m_image = LoadGraph("../aseets/�Q�l�X���C��.png");
	m_y = 0;
}

//�����̌v�Z
void Enemy_Update() {
	m_y++;
}

//�`��
void Enemy_Draw() {
	DrawGraph(0, m_y, m_image, TRUE);
}

//�I��
void Enemy_Finalize() {
	DeletGraph(m_image);
}