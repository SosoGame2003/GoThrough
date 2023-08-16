// 必要なヘッダーファイルをインクルード
#include<DxLib.h>
#include"Wall.h"

Wall::Wall()
{
	tutorialGraphHandle[0] = LoadGraph("Data/Graph/Tutorial01.png");
	tutorialGraphHandle[1] = LoadGraph("Data/Graph/Tutorial02.png");

	levelGraphHandle[0]	   = LoadGraph("Data/Graph/LevelOne.png");
	levelGraphHandle[1]	   = LoadGraph("Data/Graph/LevelTwo.png");
	levelGraphHandle[2]	   = LoadGraph("Data/Graph/LevelThree.png");

	wallGraphHandle[0]	   = LoadGraph("Data/Graph/Wall01.png");
	wallGraphHandle[1]	   = LoadGraph("Data/Graph/Wall02.png");
	wallGraphHandle[2]	   = LoadGraph("Data/Graph/Wall03.png");
	wallGraphHandle[3]	   = LoadGraph("Data/Graph/Wall04.png");
	wallGraphHandle[4]	   = LoadGraph("Data/Graph/Wall05.png");
	wallGraphHandle[5]	   = LoadGraph("Data/Graph/Wall06.png");

	tutorialWallPos[0]	   = VGet(0.0f, 0.0f, 1500.0f);
	tutorialWallPos[1]	   = VGet(0.0f, 0.0f, 1500.0f);
	tutoralWallAliveFlg[0] = true;
	tutoralWallAliveFlg[1] = false;

	for (int i = 0; i < 3; i++)
	{
		levelWallPos[i]		 = VGet(0.0f, 0.0f, 2000.0f);
		levelWallAliveFlg[i] = false;
		levelChange[i] = false;
	}

	for (int j = 0; j < 18; j++)
	{
		wallPos[j]		= VGet(0.0f, 0.0f, 2000.0f);
		wallAliveFlg[j] = false;
		randAngle[j]	= GetRand(3);
	}

	angle[0] =   0.0f;
	angle[1] =  90.0f * DX_PI_F / 180.0f;
	angle[2] = 180.0f * DX_PI_F / 180.0f;
	angle[3] = 270.0f * DX_PI_F / 180.0f;

	wallNum[0] = 0;
	for (int k = 0; k < 8; k++)
	{
		wallNum[1 + k] = GetRand(1) + 1;
	}
	for (int l = 0; l < 9; l++)
	{
		wallNum[9 + l] = GetRand(2) + 3;
	}
}

Wall::~Wall()
{
	for (int i = 0; i < 2; i++)
	{
		DeleteGraph(tutorialGraphHandle[i]);
	}
	for (int j = 0; j < 3; j++)
	{
		DeleteGraph(levelGraphHandle[j]);
	}
	for (int k = 0; k < 6; k++)
	{
		DeleteGraph(wallGraphHandle[k]);
	}
}

void Wall::WallCollision()
{

}

void Wall::TutorialMove(float deltaTime)
{
	// チュートリアル一枚目
	if (tutoralWallAliveFlg[0] == true)
	{
		tutorialWallPos[0].z -= levelOneSpeed * deltaTime;
	}

	if (tutorialWallPos[0].z <= 0)
	{
		tutoralWallAliveFlg[0] = false;
		DeleteGraph(tutorialGraphHandle[0]);
		tutoralWallAliveFlg[1] = true;
	}

	// チュートリアル二枚目
	if (tutoralWallAliveFlg[1] == true)
	{
		tutorialWallPos[1].z -= levelOneSpeed * deltaTime;
	}
	
	if (tutorialWallPos[1].z <= 0)
	{
		tutoralWallAliveFlg[1] = false;
		DeleteGraph(tutorialGraphHandle[1]);
		levelChange[0] = true;
		levelWallAliveFlg[0] = true;
	}
}

void Wall::LevelOneMove(float deltaTime)
{
	if (levelWallAliveFlg[0] == true)
	{
		levelWallPos[0].z -= levelOneSpeed * deltaTime;
	}
	if (levelWallPos[0].z <= 0)
	{
		levelWallAliveFlg[0] = false;
		wallAliveFlg[0] = true;
	}

	if (wallAliveFlg[0] == true)
	{
		wallPos[0].z -= levelOneSpeed * deltaTime;
	}
	if (wallPos[0].z <= 0)
	{
		wallAliveFlg[0] = false;
		wallAliveFlg[1] = true;
	}
	
	if (wallAliveFlg[1] == true)
	{
		wallPos[1].z -= levelOneSpeed * deltaTime;
	}
	if (wallPos[1].z <= 0)
	{
		wallAliveFlg[1] = false;
		wallAliveFlg[2] = true;
	}

	if (wallAliveFlg[2] == true)
	{
		wallPos[2].z -= levelOneSpeed * deltaTime;
	}
	if (wallPos[2].z <= 0)
	{
		wallAliveFlg[2] = false;
		wallAliveFlg[3] = true;
	}

	if (wallAliveFlg[3] == true)
	{
		wallPos[3].z -= levelOneSpeed * deltaTime;
	}
	if (wallPos[3].z <= 0)
	{
		wallAliveFlg[3] = false;
		wallAliveFlg[4] = true;
	}

	if (wallAliveFlg[4] == true)
	{
		wallPos[4].z -= levelOneSpeed * deltaTime;
	}
	if (wallPos[4].z <= 0)
	{
		wallAliveFlg[4] = false;
		wallAliveFlg[5] = true;
	}

	if (wallAliveFlg[5] == true)
	{
		wallPos[5].z -= levelOneSpeed * deltaTime;
	}
	if (wallPos[5].z <= 0)
	{
		wallAliveFlg[5] = false;
		levelChange[0] = false;
		levelWallAliveFlg[0] = false;
		levelChange[1] = true;
		levelWallAliveFlg[1] = true;
	}
}

void Wall::LevelTwoMove(float deltaTime)
{
	if (levelWallAliveFlg[1] == true)
	{
		levelWallPos[1].z -= levelTwoSpeed * deltaTime;
	}
	if (levelWallPos[1].z <= 0)
	{
		levelWallAliveFlg[1] = false;
		DeleteGraph(levelGraphHandle[1]);
		wallAliveFlg[6] = true;
	}

	if (wallAliveFlg[6] == true)
	{
		wallPos[6].z -= levelTwoSpeed * deltaTime;
	}
	if (wallPos[6].z <= 0)
	{
		wallAliveFlg[6] = false;
		wallAliveFlg[7] = true;
	}

	if (wallAliveFlg[7] == true)
	{
		wallPos[7].z -= levelTwoSpeed * deltaTime;
	}
	if (wallPos[7].z <= 0)
	{
		wallAliveFlg[7] = false;
		wallAliveFlg[8] = true;
	}

	if (wallAliveFlg[8] == true)
	{
		wallPos[8].z -= levelTwoSpeed * deltaTime;
	}
	if (wallPos[8].z <= 0)
	{
		wallAliveFlg[8] = false;
		wallAliveFlg[9] = true;
	}

	if (wallAliveFlg[9] == true)
	{
		wallPos[9].z -= levelTwoSpeed * deltaTime;
	}
	if (wallPos[9].z <= 0)
	{
		wallAliveFlg[9] = false;
		wallAliveFlg[10] = true;
	}

	if (wallAliveFlg[10] == true)
	{
		wallPos[10].z -= levelTwoSpeed * deltaTime;
	}
	if (wallPos[10].z <= 0)
	{
		wallAliveFlg[10] = false;
		wallAliveFlg[11] = true;
	}

	if (wallAliveFlg[11] == true)
	{
		wallPos[11].z -= levelTwoSpeed * deltaTime;
	}
	if (wallPos[11].z <= 0)
	{
		wallAliveFlg[11] = false;

		levelChange[1] = false;
		levelWallAliveFlg[1] = false;
		levelChange[2] = true;
		levelWallAliveFlg[2] = true;
	}
}

void Wall::LevelThreeMove(float deltaTime)
{
	if (levelWallAliveFlg[2] == true)
	{
		levelWallPos[2].z -= levelThreeSpeed * deltaTime;
	}
	if (levelWallPos[2].z <= 0)
	{
		levelWallAliveFlg[2] = false;
		DeleteGraph(levelGraphHandle[2]);
		wallAliveFlg[12] = true;
	}

	if (wallAliveFlg[12] == true)
	{
		wallPos[12].z -= levelThreeSpeed * deltaTime;
	}
	if (wallPos[12].z <= 0)
	{
		wallAliveFlg[12] = false;
		wallAliveFlg[13] = true;
	}

	if (wallAliveFlg[13] == true)
	{
		wallPos[13].z -= levelThreeSpeed * deltaTime;
	}
	if (wallPos[13].z <= 0)
	{
		wallAliveFlg[13] = false;
		wallAliveFlg[14] = true;
	}

	if (wallAliveFlg[14] == true)
	{
		wallPos[14].z -= levelThreeSpeed * deltaTime;
	}
	if (wallPos[14].z <= 0)
	{
		wallAliveFlg[14] = false;
		wallAliveFlg[15] = true;
	}

	if (wallAliveFlg[15] == true)
	{
		wallPos[15].z -= levelThreeSpeed * deltaTime;
	}
	if (wallPos[15].z <= 0)
	{
		wallAliveFlg[15] = false;
		wallAliveFlg[16] = true;
	}

	if (wallAliveFlg[16] == true)
	{
		wallPos[16].z -= levelThreeSpeed * deltaTime;
	}
	if (wallPos[16].z <= 0)
	{
		wallAliveFlg[16] = false;
		wallAliveFlg[17] = true;
	}

	if (wallAliveFlg[17] == true)
	{
		wallPos[17].z -= levelThreeSpeed * deltaTime;
	}
	if (wallPos[17].z <= 0)
	{
		wallAliveFlg[17] = false;
		levelChange[2] = false;
		levelWallAliveFlg[2] = false;

		
	}
}

void Wall::Update(float deltaTime)
{
	TutorialMove(deltaTime);
	if (levelChange[0] == true)
	{
		LevelOneMove(deltaTime);
	}
	if (levelChange[1] == true)
	{
		LevelTwoMove(deltaTime);
	}
	if (levelChange[2] == true)
	{
		LevelThreeMove(deltaTime);
	}
}

void Wall::Draw()
{
	for (int i = 0; i < 2; i++)
	{
		if (tutoralWallAliveFlg[i] == true)
		{
			DrawBillboard3D(tutorialWallPos[i], 0.5f, 0.5f, 600.0f, 0.0f, tutorialGraphHandle[i], TRUE);
		}
	}

	for (int j = 0; j < 3; j++)
	{
		if (levelWallAliveFlg[j] == true)
		{
			DrawBillboard3D(levelWallPos[j], 0.5f, 0.5f, 600.0f, 0.0f, levelGraphHandle[j], TRUE);
		}
	}

	for (int k = 0; k < 18; k++)
	{
		if (wallAliveFlg[k] == true)
		{
			DrawBillboard3D(wallPos[k], 0.5f, 0.5f, 600.0f, angle[randAngle[k]], wallGraphHandle[wallNum[k]], TRUE);
		}
	}
}