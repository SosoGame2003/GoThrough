#pragma once

#include"Scene.h"

class Play : public Scene
{
public:
	Play();
	~Play();

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
	class Player* player;
};