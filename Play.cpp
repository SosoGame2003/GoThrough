// 必要なヘッダーファイルをインクルード
#include<DxLib.h>
#include"Play.h"
#include"Map.h"
#include"Player.h"
#include"Wall.h"

Play::Play()
{
	map = new Map();
	player = new Player();
	wall = new Wall();
}

Play::~Play()
{
	delete map;
	map = nullptr;

	delete player;
	player = nullptr;
	
	delete wall;
	wall = nullptr;
}

SCENE_TAG Play::Update(float deltaTime)
{
	map->Update(deltaTime);
	player->Update(deltaTime);
	wall->Update(deltaTime);

	if (wall->gameClear == true)
	{
		return SCENE_TAG::CLEAR;
	}
	if (wall->gameOver == true)
	{
		return SCENE_TAG::OVER;
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
	wall->Draw();
	player->Draw();
}