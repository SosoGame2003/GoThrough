#pragma once

class Map
{
public:
	Map();
	~Map();

	void Update(float deltaTime);

	void Draw();

private:
	// �}�b�v�̘g��������
	const VECTOR upperLeftFrontPos	 = VGet(-300,  300, -500);	// �����O�̍��W
	const VECTOR upperLeftBackPos	 = VGet(-300,  300, 5000);	// ���㉜�̍��W
	const VECTOR bottomLeftFrontPos	 = VGet(-300, -300, -500);	// ������O�̍��W
	const VECTOR bottomLeftBackPos	 = VGet(-300, -300, 5000);	// �������̍��W
	const VECTOR upperRightFrontPos	 = VGet( 300,  300, -500);	// �E���O�̍��W
	const VECTOR upperRightBackPos	 = VGet( 300,  300, 5000);	// �E�㉜�̍��W
	const VECTOR bottomRightFrontPos = VGet( 300, -300, -500);	// �E����O�̍��W
	const VECTOR bottomRightBackPos	 = VGet( 300, -300, 5000);	// �E�����̍��W

	int mapBorderCornerLineColor = GetColor(0, 255, 0);	// �}�b�v�̎l���̘g���̐F

	const VECTOR centerLeftFrontPos   = VGet( -300,    0, -500);	// �����S��O�̍��W
	const VECTOR centerLeftBackPos    = VGet( -300,    0, 5000);	// �����S���̍��W
	const VECTOR centerRightFrontPos  = VGet(  300,    0, -500);	// �E���S��O�̍��W
	const VECTOR centerRightBackPos   = VGet(  300,    0, 5000);	// �E���S���̍��W
	const VECTOR centerUpperFrontPos  = VGet(	 0,  300, -500);	// �㒆�S��O�̍��W
	const VECTOR centerUpperBackPos   = VGet(	 0,  300, 5000);	// �㒆�S���̍��W
	const VECTOR centerBottomFrontPos = VGet(	 0, -300, -500);	// �����S��O�̍��W
	const VECTOR centerBottomBackPos  = VGet(	 0, -300, 5000);	// �����S���̍��W

	int mapBorderCenterLineColor = GetColor(50, 50, 50);	// �}�b�v�̒��S�̘g���̐F

	// �v���C���[�̈ʒu������
	const VECTOR playerPosUpperLeftPos	 = VGet(-300, 300, 0);	// �}�b�v�̘g�̍���̍��W
	const VECTOR playerPosBottomLeftPos	 = VGet(-300,-300, 0);	// �}�b�v�̘g�̍����̍��W
	const VECTOR playerPosUpperRightPos	 = VGet( 300, 300, 0);	// �}�b�v�̘g�̉E��̍��W
	const VECTOR playerPosBottomRightPos = VGet( 300,-300, 0);	// �}�b�v�̘g�̉E���̍��W

	int playerPosLineColor = GetColor(255, 0, 0);	// �v���C���[�̍��W�������̐��̐F
};