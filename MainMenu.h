#pragma once

#include"Scene.h"

class MainMenu : public Scene
{
public:
	MainMenu();
	~MainMenu();

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
	int logoGraphHandle[9];	// �^�C�g�����S�̉摜�n���h��
};