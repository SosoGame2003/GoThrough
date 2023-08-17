// 必要なヘッダーファイルをインクルード
#include<DxLib.h>
#include"Over.h"

Over::Over()
{
}

Over::~Over()
{
}

SCENE_TAG Over::Update(float deltaTime)
{
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		return SCENE_TAG::MENU;
	}

	return SCENE_TAG::NONE;
}

void Over::Draw()
{
}