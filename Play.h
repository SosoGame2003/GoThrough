#pragma once

#include"Scene.h"

class Play : public Scene
{
public:
	Play();
	~Play();

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="deltaTime">�f���^�^�C��</param>
	/// <returns>NONE��Ԃ�</returns>
	SCENE_TAG Update(float deltaTime) override;

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw() override;

private:
	class Map* map;
	class Player* player;
};