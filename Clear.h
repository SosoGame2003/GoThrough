#pragma once

#include"Scene.h"

class Clear : public Scene
{
public:
	Clear();
	~Clear();

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

	VECTOR clearPos;
	int clearGraphHandle;
	const float clearSpeed = 500.0f;
	bool moveFlg;

	VECTOR pressEnterPos;
	int pressEnterGraphHandle;
	const float pressEnterSpeed = 50.0f;
	bool pressEnterFrontBack;

	bool buttonEntry;
};