#pragma once

class Map
{
public:
	Map();
	~Map();

	void Update(float deltaTime);

	void Draw();

private:
	// �}�b�v�l���̐�
	VECTOR UpperLeftFrontPos	= VGet(-300,  300, -500);	// �����O�̍��W
	VECTOR UpperLeftBackPos		= VGet(-300,  300, 5000);	// ���㉜�̍��W
	VECTOR BottomLeftFrontPos	= VGet(-300, -300, -500);	// ������O�̍��W
	VECTOR BottomLeftBackPos	= VGet(-300, -300, 5000);	// �������̍��W
	VECTOR UpperRightFrontPos	= VGet( 300,  300, -500);	// �E���O�̍��W
	VECTOR UpperRightBackPos	= VGet( 300,  300, 5000);	// �E�㉜�̍��W
	VECTOR BottomRightFrontPos	= VGet( 300, -300, -500);	// �E����O�̍��W
	VECTOR BottomRightBackPos	= VGet( 300, -300, 5000);	// �E�����̍��W

	int FourCornersOfMapLineColor = GetColor(0, 255, 0);	// �}�b�v�l���̐��̐F

	// �v���C���[��Z���W��������
	VECTOR PlayerPosZUpperLeftPos	= VGet(-300, 300, 0);	// ����̍��W
	VECTOR PlayerPosZBottomLeftPos	= VGet(-300,-300, 0);	// �����̍��W
	VECTOR PlayerPosZUpperRightPos	= VGet( 300, 300, 0);	// �E��̍��W
	VECTOR PlayerPosZBottomRightPos = VGet( 300,-300, 0);	// �E���̍��W

	int PlayerPosZLineColor = GetColor(255, 0, 0);	// �v���C���[��Z���W�̐��̐F

	// �t�H�O�֌W
	float fogStartPos =    0.0f;	// �t�H�O�̊J�n�ʒu
	float fogEndPos	  = 2000.0f;	// �t�H�O�̏I���ʒu
};