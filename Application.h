#pragma once

class Application
{
public:
	Application();
	~Application();

	/// <summary>
	/// �Q�[�����[�v
	/// </summary>
	void GameLoop();

private:
	class SceneManager* sceneMgr;

	const int ScreenSizeX	  = 1000;	// �E�B���h�E�̕�
	const int ScreenSizeY	  = 1000;	// �E�B���h�E�̍���
	const int ColorBitDepth	  =	  32;	// �J���[�r�b�g��
};