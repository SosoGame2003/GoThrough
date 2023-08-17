// 必要なヘッダーファイルをインクルード
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
	MV1SetScale(modelHandle, VGet(0.5f, 0.5f, 0.5f));												// モデルのサイズを変更
	MV1SetRotationXYZ(modelHandle, VGet(90.0f * DX_PI_F / 180.0f, 0.0f, 0.0f));						// モデルをX方向に90°回転
	MV1SetMaterialEmiColor(modelHandle, 0, GetColorF(0.0f, 0.0f, 1.0f, 1.0f));	// プレイヤーモデルの機体の色
	MV1SetMaterialEmiColor(modelHandle, 1, GetColorF(0.1f, 0.0f, 0.0f, 1.0f));	// プレイヤーモデルのエンジンの色
}

Player::~Player()
{
	MV1DeleteModel(modelHandle);
}

void Player::Move(float deltaTime)
{
	bool input = false;	// 移動キーの入力確認
	float rate = 1.0f;	// 移動量の倍率係数

	if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_RIGHT))
	{
		if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_DOWN))
		{
			rate = 0.71f;	// 斜め移動時には移動量の倍率係数を0.71f(√2)にする
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

	if (input)	// 移動キーの入力が確認された時
	{
		// 上下または左右の同時入力時に入力をなかったことにする
		if (CheckHitKey(KEY_INPUT_UP) && CheckHitKey(KEY_INPUT_DOWN)
			|| CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_RIGHT))
		{
			input = false;
		}
	}
	else	// 移動キーの入力が確認されなかった時
	{
		moveX = 0.0f;
		moveY = 0.0f;
	}

	// 座標更新
	pos.x += moveX;
	pos.y += moveY;
}

void Player::MovableRange()
{
	if (pos.x <= -300.0f)
	{
		pos.x = -300.0f;
	}
	if (pos.x >= 300.0f)
	{
		pos.x = 300.0f;
	}
	if (pos.y <= -300.0f)
	{
		pos.y = -300.0f;
	}
	if (pos.y >= 300.0f)
	{
		pos.y = 300.0f;
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
	printfDx("\n\nx:%f\n", pos.x);
	printfDx("y:%f\n", pos.y);
	printfDx("z:%f\n", pos.z);
	printfDx("\nspeed:%f\n", speed);
	printfDx("moveX:%f\n", moveX);
	printfDx("moveY:%f\n", moveY);

	//MV1DrawModel(modelHandle);
	DrawSphere3D(pos, 30.0f, 16, GetColor(0, 0, 255), GetColor(0, 0, 255), FALSE);
}