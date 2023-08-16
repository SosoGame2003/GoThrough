// 必要なヘッダーファイルをインクルード
#include<DxLib.h>
#include"Result.h"

Result::Result()
{

}

Result::~Result()
{
}

SCENE_TAG Result::Update(float deltaTime)
{
	if (CheckHitKey(KEY_INPUT_END))
	{
		return SCENE_TAG::MENU;
	}

	return SCENE_TAG::NONE;	// シーンの変更なし
}

void Result::Draw()
{

}