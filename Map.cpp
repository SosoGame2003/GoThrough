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
	// �}�b�v�̘g��������
	DrawLine3D(upperLeftFrontPos,    upperLeftBackPos,    mapBorderCornerLineColor);	// �}�b�v����̐�
	DrawLine3D(bottomLeftFrontPos,   bottomLeftBackPos,   mapBorderCornerLineColor);	// �}�b�v�����̐�
	DrawLine3D(upperRightFrontPos,   upperRightBackPos,   mapBorderCornerLineColor);	// �}�b�v�E��̐�
	DrawLine3D(bottomRightFrontPos,  bottomRightBackPos,  mapBorderCornerLineColor);	// �}�b�v�E���̐�

	DrawLine3D(centerLeftFrontPos,   centerLeftBackPos,   mapBorderCenterLineColor);	// �}�b�v�����S�̐�
	DrawLine3D(centerRightFrontPos,  centerRightBackPos,  mapBorderCenterLineColor);	// �}�b�v�E���S�̐�
	DrawLine3D(centerUpperFrontPos,  centerUpperBackPos,  mapBorderCenterLineColor);	// �}�b�v�㒆�S�̐�
	DrawLine3D(centerBottomFrontPos, centerBottomBackPos, mapBorderCenterLineColor);	// �}�b�v�����S�̐�

	// �v���C���[�̍��W��������
	DrawLine3D(playerPosUpperLeftPos,   playerPosBottomLeftPos,  playerPosLineColor);	// ���̐�
	DrawLine3D(playerPosBottomLeftPos,  playerPosBottomRightPos, playerPosLineColor);	// ���̐�
	DrawLine3D(playerPosBottomRightPos, playerPosUpperRightPos,  playerPosLineColor);	// �E�̐�
	DrawLine3D(playerPosUpperRightPos,  playerPosUpperLeftPos,   playerPosLineColor);	// ��̐�
}