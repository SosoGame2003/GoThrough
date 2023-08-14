#pragma once

// �K�v�ȃw�b�_�[�t�@�C�����C���N���[�h
#include<DxLib.h>
#include"Scene.h"

/// <summary>
/// �V�[���}�l�[�W���[
/// </summary>
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	/// <summary>
	/// �Q�[�����[�v
	/// </summary>
	void GameLoop();

	/// <summary>
	/// �V�[���̌Ăяo��
	/// </summary>
	/// <param name="tag">�V�[���̃^�O</param>
	void SetNowScene(const SCENE_TAG& tag);

private:
	/// <summary>
	/// �V�[���̍폜
	/// </summary>
	void DeleteScene();

	/// <summary>
	/// �f���^�^�C���̕ۑ�
	/// </summary>
	void SaveDeltaTime();

	Scene* currentScene;	// ���݂̃V�[��

	// �t���[�����[�g�֘A
	float deltaTime;
	int fps;
	int fpsCounter;
	LONGLONG currentTime;
	LONGLONG time;
	LONGLONG fpsCheckTime;

	// �J�����֘A
	const float cameraNear		 =	   1.0f;	// ��O�N���b�v����
	const float cameraFar		 =  5000.0f;	// ���N���b�v����
	const float cameraPosX		 =	   0.0f;	// �J������X���W
	const float cameraPosY		 =	   0.0f;	// �J������Y���W
	const float cameraPosZ		 =	-750.0f;	// �J������Z���W
	const float cameraGazingPosX =	   0.0f;	// �J������X���W�����_
	const float cameraGazingPosY =	   0.0f;	// �J������Y���W�����_
	const float cameraGazingPosZ =	2000.0f;	// �J������Z���W�����_
};