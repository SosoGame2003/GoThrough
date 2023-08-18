#pragma once

#include"Scene.h"

class Over : public Scene
{
public:
	Over();
	~Over();

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

	VECTOR overPos;
	int overGraphHandle;
	const float overSpeed = 500.0f;
	bool moveFlg;

	VECTOR pressEnterPos;
	int pressEnterGraphHandle;
	const float pressEnterSpeed = 50.0f;
	bool pressEnterFrontBack;

	bool buttonEntry;
};