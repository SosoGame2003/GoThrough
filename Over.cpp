// 必要なヘッダーファイルをインクルード
#include<DxLib.h>
#include"Over.h"
#include"Map.h"

Over::Over()
{
	map = new Map();

	overGraphHandle = LoadGraph("Data/Graph/GameOver.png");
	overPos = VGet(0, 70, 500);
	moveFlg = true;

	pressEnterGraphHandle = LoadGraph("Data/Graph/PressEnter.png");
	pressEnterPos = VGet(0, -70, 0);
	pressEnterFrontBack = true;
	buttonEntry = false;
}

Over::~Over()
{
	delete map;
	map = nullptr;
}

SCENE_TAG Over::Update(float deltaTime)
{
	if (overPos.z <= 0.0f)
	{
		moveFlg = false;
		overPos.z = 0.0f;
	}

	if (moveFlg == true)
	{
		overPos.z -= overSpeed * deltaTime;
	}
	else
	{
		buttonEntry = true;
	}



	if (buttonEntry == true)
	{
		if (pressEnterFrontBack == true)
		{
			pressEnterPos.z -= pressEnterSpeed * deltaTime;
			if (pressEnterPos.z < -20)
			{
				pressEnterFrontBack = false;
			}
		}
		else
		{
			pressEnterPos.z += pressEnterSpeed * deltaTime;
			if (pressEnterPos.z > 20)
			{
				pressEnterFrontBack = true;
			}
		}

		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			return SCENE_TAG::MENU;
		}
	}

	return SCENE_TAG::NONE;
}

void Over::Draw()
{
	map->Draw();

	DrawBillboard3D(overPos, 0.5f, 0.5f, 492.0f, 0.0f, overGraphHandle, TRUE);

	if (buttonEntry == true)
	{
		DrawBillboard3D(pressEnterPos, 0.5f, 0.5f, 435.0f, 0.0f, pressEnterGraphHandle, TRUE);
	}
}