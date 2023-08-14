#pragma once

#include"Scene.h"

class MainMenu : public Scene
{
public:
	MainMenu();
	~MainMenu();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="deltaTime">デルタタイム</param>
	/// <returns>NONEを返す</returns>
	SCENE_TAG Update(float deltaTime) override;

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw() override;

private:
	int logoGraphHandle[9];	// タイトルロゴの画像ハンドル
};