// 必要なヘッダーファイルをインクルード
#include<DxLib.h>
#include"Clear.h"
#include"Map.h"

Clear::Clear()
{
	map = new Map();

	clearGraphHandle = LoadGraph("Data/Graph/GameClear.png");
	clearPos = VGet(0, 70, 500);
	moveFlg = true;

	pressEnterGraphHandle = LoadGraph("Data/Graph/PressEnter.png");
	pressEnterPos = VGet(0, -70, 0);
	pressEnterFrontBack = true;
	buttonEntry = false;
}

Clear::~Clear()
{
	delete map;
	map = nullptr;
}

SCENE_TAG Clear::Update(float deltaTime)
{
	if (clearPos.z <= 0.0f)
	{
		moveFlg = false;
		clearPos.z = 0.0f;
	}

	if (moveFlg == true)
	{
		clearPos.z -= clearSpeed * deltaTime;
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

void Clear::Draw()
{
	map->Draw();

	DrawBillboard3D(clearPos, 0.5f, 0.5f, 492.0f, 0.0f, clearGraphHandle, TRUE);

	if (buttonEntry == true)
	{
		DrawBillboard3D(pressEnterPos, 0.5f, 0.5f, 435.0f, 0.0f, pressEnterGraphHandle, TRUE);
	}
}