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
	class Map* map;

	VECTOR logoPos[9];		// タイトルロゴの座標
	int logoGraphHandle[9];	// タイトルロゴの画像ハンドル
	const float logoSpeed = 1000.0f;
	bool moveFlg[9];

	VECTOR pressEnterPos;
	int pressEnterGraphHandle;
	const float pressEnterSpeed = 50.0f;
	bool pressEnterFrontBack;

	VECTOR wallPos[4];
	int wallGraphHandle[4];
	const float wallSpeed = 750.0f;

	VECTOR playerPos;
	int playerModelHandle;
	int moveDirection;					// 移動方向(0：上、１：右、２：下、３：左)
	const float playerSpeed = 750.0f;

	bool buttonEntry;
};