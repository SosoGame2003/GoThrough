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
	class Map* map;

	VECTOR logoPos[9];		// �^�C�g�����S�̍��W
	int logoGraphHandle[9];	// �^�C�g�����S�̉摜�n���h��
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
	int moveDirection;					// �ړ�����(0�F��A�P�F�E�A�Q�F���A�R�F��)
	const float playerSpeed = 750.0f;

	bool buttonEntry;
};