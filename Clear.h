#pragma once

#include"Scene.h"

class Clear : public Scene
{
public:
	Clear();
	~Clear();

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

};