// 必要なヘッダーファイルをインクルード
#include<DxLib.h>
#include"Play.h"
#include"Map.h"
#include"Player.h"

Play::Play()
{
	map = new Map();
	player = new Player();
}

Play::~Play()
{
	delete map;
	map = nullptr;

	delete player;
	player = nullptr;
}

SCENE_TAG Play::Update(float deltaTime)
{
	map->Update(deltaTime);
	player->Update(deltaTime);

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
	player->Draw();
}