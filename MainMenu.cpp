// 必要なヘッダーファイルをインクルード
#include<DxLib.h>
#include"MainMenu.h"
#include"Map.h"

MainMenu::MainMenu()
{
	map = new Map();

	LoadDivGraph("Data/Graph/TitleLogoChip.png", 9, 9, 1, 75, 120, logoGraphHandle);	// 元画像(X：675px, Y：120px)
	pressEnterGraphHandle = LoadGraph("Data/Graph/PressEnter.png");

	for (int i = 0; i < 4; i++)
	{
		wallGraphHandle[i] = LoadGraph("Data/Graph/TitleWall.png");
		wallPos[0] = VGet(0, 0, 1000);
	}

	playerModelHandle = MV1LoadModel("Data/Model/Rocket.mv1");
	MV1SetScale(playerModelHandle, VGet(0.5f, 0.5f, 0.5f));												// モデルのサイズを変更
	MV1SetRotationXYZ(playerModelHandle, VGet(90.0f * DX_PI_F / 180.0f, 0.0f, 0.0f));						// モデルをX方向に90°回転
	MV1SetMaterialEmiColor(playerModelHandle, 0, GetColorF(0.0f, 0.0f, 1.0f, 1.0f));	// プレイヤーモデルの機体の色
	MV1SetMaterialEmiColor(playerModelHandle, 1, GetColorF(0.1f, 0.0f, 0.0f, 1.0f));	// プレイヤーモデルのエンジンの色

	moveDirection = 0;

	logoPos[0] = VGet(-360, 100, 1000);
	logoPos[1] = VGet(-270, 100, 1100);
	logoPos[2] = VGet(-180, 100, 1200);
	logoPos[3] = VGet( -90, 100, 1300);
	logoPos[4] = VGet(   0, 100, 1400);
	logoPos[5] = VGet(  90, 100, 1500);
	logoPos[6] = VGet( 180, 100, 1600);
	logoPos[7] = VGet( 270, 100, 1700);
	logoPos[8] = VGet( 360, 100, 1800);

	pressEnterPos = VGet(0, -70, 0);

	for (int j = 0; j < 9; j++)
	{
		moveFlg[j] = true;
	}
	pressEnterFrontBack = true;
	buttonEntry = false;
}

MainMenu::~MainMenu()
{
	delete map;
	map = nullptr;

	for (int i = 0; i < 9; i++)
	{
		DeleteGraph(logoGraphHandle[i]);
	}
}

SCENE_TAG MainMenu::Update(float deltaTime)
{
	for (int i = 0; i < 9; i++)
	{
		if (moveFlg[i] == true)
		{
			logoPos[i].z -= logoSpeed * deltaTime;
		}

		if (logoPos[i].z <= 0.0f)
		{
			moveFlg[i] = false;
			logoPos[i].z = 0.0f;
		}
	}

	if (moveFlg[8] == false)
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
			return SCENE_TAG::PLAY;
		}
	}

	return SCENE_TAG::NONE;	// シーンの変更なし
}

void MainMenu::Draw()
{
	map->Draw();

	for (int i = 0; i < 9; i++)
	{
		DrawBillboard3D(logoPos[i], 0.5f, 0.5f, 75.0f, 0.0f, logoGraphHandle[i], TRUE);
	}

	if (buttonEntry == true)
	{
		DrawBillboard3D(pressEnterPos, 0.5f, 0.5f, 435.0f, 0.0f, pressEnterGraphHandle, TRUE);
	}
}