// 必要なヘッダーファイルをインクルード
#include<DxLib.h>
#include"Play.h"
#include"Map.h"

Play::Play()
{
	map = new Map();

	g = LoadGraph("Data/Graph/DummyPlay.png");
}

Play::~Play()
{
	delete map;
	map = nullptr;
}

SCENE_TAG Play::Update(float deltaTime)
{
	map->Update(deltaTime);

	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		return SCENE_TAG::RESULT;
	}

	if (CheckHitKey(KEY_INPUT_END))
	{
		return SCENE_TAG::MENU;
	}

	return SCENE_TAG::NONE;	// シーンの変更なし
}

void Play::Draw()
{
	map->Draw();
}