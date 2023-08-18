// �K�v�ȃw�b�_�[�t�@�C�����C���N���[�h
#include<DxLib.h>
#include<math.h>
#include<cmath>
#include"Player.h"

Player::Player()
	: moveX(0.0f)
	, moveY(0.0f)
{
	pos = VGet(0.0f, 0.0f, 0.0f);

	modelHandle = MV1LoadModel("Data/Model/Rocket.mv1");
	MV1SetScale(modelHandle, VGet(0.5f, 0.5f, 0.5f));												// ���f���̃T�C�Y��ύX
	MV1SetRotationXYZ(modelHandle, VGet(90.0f * DX_PI_F / 180.0f, 0.0f, 0.0f));						// ���f����X������90����]
	MV1SetMaterialEmiColor(modelHandle, 0, GetColorF(0.0f, 1.0f, 0.0f, 1.0f));	// �v���C���[���f���̋@�̂̐F
	MV1SetMaterialEmiColor(modelHandle, 1, GetColorF(0.1f, 0.0f, 0.0f, 1.0f));	// �v���C���[���f���̃G���W���̐F
}

Player::~Player()
{
	MV1DeleteModel(modelHandle);
}

void Player::Move(float deltaTime)
{
	bool input = false;	// �ړ��L�[�̓��͊m�F
	float rate = 1.0f;	// �ړ��ʂ̔{���W��

	if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_RIGHT))
	{
		if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_DOWN))
		{
			rate = 0.71f;	// �΂߈ړ����ɂ͈ړ��ʂ̔{���W����0.71f(��2)�ɂ���
		}
	}

	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		moveX = -speed * rate * deltaTime;
		input = true;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		moveX = +speed * rate * deltaTime;
		input = true;
	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		moveY = +speed * rate * deltaTime;
		input = true;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		moveY = -speed * rate * deltaTime;
		input = true;
	}

	if (input)	// �ړ��L�[�̓��͂��m�F���ꂽ��
	{
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			MV1SetRotationXYZ(modelHandle, VGet(90.0f * DX_PI_F / 180.0f, 0.0f, 30.0f * DX_PI_F / 180.0f));
		}
		else if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			MV1SetRotationXYZ(modelHandle, VGet(90.0f * DX_PI_F / 180.0f, 0.0f, -30.0f * DX_PI_F / 180.0f));
		}


		// �㉺�܂��͍��E�̓������͎��ɓ��͂��Ȃ��������Ƃɂ���
		if (CheckHitKey(KEY_INPUT_UP) && CheckHitKey(KEY_INPUT_DOWN)
			|| CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_RIGHT))
		{
			input = false;
		}
	}
	else	// �ړ��L�[�̓��͂��m�F����Ȃ�������
	{
		MV1SetRotationXYZ(modelHandle, VGet(90.0f * DX_PI_F / 180.0f, 0.0f, 0.0f));

		moveX = 0.0f;
		moveY = 0.0f;
	}

	// ���W�X�V
	pos.x += moveX;
	pos.y += moveY;
}

void Player::MovableRange()
{
	if (pos.x <= -270.0f)
	{
		pos.x = -270.0f;
	}
	if (pos.x >= 270.0f)
	{
		pos.x = 270.0f;
	}
	if (pos.y <= -270.0f)
	{
		pos.y = -270.0f;
	}
	if (pos.y >= 270.0f)
	{
		pos.y = 270.0f;
	}
}

void Player::Update(float deltaTime)
{
	Move(deltaTime);
	MovableRange();

	MV1SetPosition(modelHandle, pos);
}

void Player::Draw()
{
	/*printfDx("\n\nx:%f\n", pos.x);
	printfDx("y:%f\n", pos.y);
	printfDx("z:%f\n", pos.z);
	printfDx("\nspeed:%f\n", speed);
	printfDx("moveX:%f\n", moveX);
	printfDx("moveY:%f\n", moveY);*/

	MV1DrawModel(modelHandle);
	//DrawSphere3D(pos, 30.0f, 16, GetColor(0, 0, 255), GetColor(0, 0, 255), FALSE);

	// �v���C���[�̍��W��������
	DrawLine3D(playerPosUpperLeftPos, playerPosBottomLeftPos, playerPosLineColor);	// ���̐�
	DrawLine3D(playerPosBottomLeftPos, playerPosBottomRightPos, playerPosLineColor);	// ���̐�
	DrawLine3D(playerPosBottomRightPos, playerPosUpperRightPos, playerPosLineColor);	// �E�̐�
	DrawLine3D(playerPosUpperRightPos, playerPosUpperLeftPos, playerPosLineColor);	// ��̐�

	DrawLine3D(VGet(180, 300, 0), VGet(180, -300, 0), playerPosLineColor);
	DrawLine3D(VGet(60, 300, 0), VGet(60, -300, 0), playerPosLineColor);
	DrawLine3D(VGet(-60, 300, 0), VGet(-60, -300, 0), playerPosLineColor);
	DrawLine3D(VGet(-180, 300, 0), VGet(-180, -300, 0), playerPosLineColor);

	DrawLine3D(VGet(300, 180, 0), VGet(-300, 180, 0), playerPosLineColor);
	DrawLine3D(VGet(300, 60, 0), VGet(-300, 60, 0), playerPosLineColor);
	DrawLine3D(VGet(300, -60, 0), VGet(-300, -60, 0), playerPosLineColor);
	DrawLine3D(VGet(300, -180, 0), VGet(-300, -180, 0), playerPosLineColor);
}