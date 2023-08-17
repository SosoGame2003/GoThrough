// 必要なヘッダーファイルをインクルード
#include<DxLib.h>
#include"Clear.h"

Clear::Clear()
{
}

Clear::~Clear()
{
}

SCENE_TAG Clear::Update(float deltaTime)
{
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		return SCENE_TAG::MENU;
	}

	return SCENE_TAG::NONE;
}

void Clear::Draw()
{
}