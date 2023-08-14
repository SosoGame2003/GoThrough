// 必要なヘッダーファイルをインクルード
#include<DxLib.h>
#include"MainMenu.h"

MainMenu::MainMenu()
{
	LoadDivGraph("Data/Graph/TitleLogo.png", 9, 9, 1, 75, 120, logoGraphHandle);	// 元画像(X：675px, Y：120px)
}

MainMenu::~MainMenu()
{
	for (int i = 0; i < 9; i++)
	{
		DeleteGraph(logoGraphHandle[i]);
	}
}

SCENE_TAG MainMenu::Update(float deltaTime)
{
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		return SCENE_TAG::PLAY;
	}

	return SCENE_TAG::NONE;	// シーンの変更なし
}

void MainMenu::Draw()
{
	DrawGraph(100, 300, logoGraphHandle[0], TRUE);
	DrawGraph(190, 300, logoGraphHandle[1], TRUE);
	DrawGraph(285, 300, logoGraphHandle[2], TRUE);
	DrawGraph(375, 300, logoGraphHandle[3], TRUE);
	DrawGraph(465, 300, logoGraphHandle[4], TRUE);
	DrawGraph(555, 300, logoGraphHandle[5], TRUE);
	DrawGraph(645, 300, logoGraphHandle[6], TRUE);
	DrawGraph(735, 300, logoGraphHandle[7], TRUE);
	DrawGraph(825, 300, logoGraphHandle[8], TRUE);
}