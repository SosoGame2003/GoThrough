// �K�v�ȃw�b�_�[�t�@�C�����C���N���[�h
#include<DxLib.h>
#include"Map.h"

Map::Map()
{
	SetFogEnable(TRUE);
	SetFogColor(0, 0, 0);
	SetFogStartEnd(fogStartPos, fogEndPos);
}

Map::~Map()
{
}

void Map::Update(float deltaTime)
{
}

void Map::Draw()
{
	// �}�b�v�l���̐�
	DrawLine3D(UpperLeftFrontPos,   UpperLeftBackPos,   FourCornersOfMapLineColor);	// �}�b�v����̐�
	DrawLine3D(BottomLeftFrontPos,  BottomLeftBackPos,  FourCornersOfMapLineColor);	// �}�b�v�����̐�
	DrawLine3D(UpperRightFrontPos,  UpperRightBackPos,  FourCornersOfMapLineColor);	// �}�b�v�E��̐�
	DrawLine3D(BottomRightFrontPos, BottomRightBackPos, FourCornersOfMapLineColor);	// �}�b�v�E���̐�

	// �v���C���[��Z���W��������
	DrawLine3D(PlayerPosZUpperLeftPos,   PlayerPosZBottomLeftPos,  PlayerPosZLineColor);	// ���̐�
	DrawLine3D(PlayerPosZBottomLeftPos,  PlayerPosZBottomRightPos, PlayerPosZLineColor);	// ���̐�
	DrawLine3D(PlayerPosZBottomRightPos, PlayerPosZUpperRightPos,  PlayerPosZLineColor);	// �E�̐�
	DrawLine3D(PlayerPosZUpperRightPos,  PlayerPosZUpperLeftPos,   PlayerPosZLineColor);	// ��̐�
}