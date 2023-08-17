// �K�v�ȃw�b�_�[�t�@�C�����C���N���[�h
#include"SceneManager.h"
#include"MainMenu.h"
#include"Play.h"
#include"Clear.h"
#include"Over.h"

SceneManager::SceneManager()
	: currentScene(nullptr)
	, deltaTime(0.0f)
	, currentTime(0)
	, time(0)
	, fpsCheckTime(0)
	, fps(0)
	, fpsCounter(0)
{
	// �t���[�����[�g�֘A
	deltaTime	 = 0.000001f;					// �ŏ��̌o�ߎ��Ԃ͉���0.000001f�b�ɂ��Ă���
	time		 = GetNowHiPerformanceCount();	// �V�X�e�����Ԃ��擾���Ă���
	fpsCheckTime = GetNowHiPerformanceCount();

	// �J�����֘A
	SetCameraNearFar(cameraNear, cameraFar);
	SetCameraPositionAndTarget_UpVecY(VGet(cameraPosX, cameraPosY, cameraPosZ), VGet(cameraGazingPosX, cameraGazingPosY, cameraGazingPosZ));
}

SceneManager::~SceneManager()
{
	DeleteScene();
}

void SceneManager::GameLoop()
{
	while (!ProcessMessage())
	{
#ifdef _DEBUG
		if (CheckHitKey(KEY_INPUT_ESCAPE))	// �G�X�P�[�v�L�[��������
		{
			break;	// ���[�v�𔲂���
		}
#endif // _DEBUG
		auto tag = currentScene->Update(deltaTime);

		ClearDrawScreen();	// ��ʂɕ`����Ă������̂���������
		clsDx();			// �ȈՉ�ʏo�͗������N���A

#ifdef _DEBUG
		printfDx("deltaTime:%f\n", deltaTime);
		printfDx("FPS:%d\n", fps);
#endif // _DEBUG
		currentScene->Draw();

		ScreenFlip();	// ��ʂ̗��y�[�W�̓��e��\�y�[�W�ɔ��f����

		SaveDeltaTime();

		if (tag == SCENE_TAG::NONE)	// �V�[���̃^�O��NONE�̂Ƃ���
		{
			continue;	// ���[�v�𔲂��Ȃ�
		}

		DeleteScene();

		if (tag == SCENE_TAG::END)	// �V�[���̃^�O��END�̂Ƃ���
		{
			break;		// ���[�v�𔲂���
		}

		SetNowScene(tag);
	}
}

void SceneManager::SetNowScene(const SCENE_TAG& tag)
{
	switch (tag)
	{
	case SCENE_TAG::MENU:
		currentScene = new MainMenu();
		break;

	case SCENE_TAG::PLAY:
		currentScene = new Play();
		break;

	case SCENE_TAG::CLEAR:
		currentScene = new Clear();
		break;

	case SCENE_TAG::OVER:
		currentScene = new Over();
		break;

	case SCENE_TAG::NONE:
		break;

	default:
		break;
	}
}

void SceneManager::DeleteScene()
{
	if (currentScene != nullptr)
	{
		delete currentScene;
		currentScene = nullptr;
	}
}

void SceneManager::SaveDeltaTime()
{
	currentTime = GetNowHiPerformanceCount();		// ���݂̃V�X�e�����Ԃ��擾
	deltaTime = (currentTime - time) / 1000000.0f;	// �O��擾�������Ԃ���̌o�ߎ��Ԃ�b�ɕϊ����ăZ�b�g
	time = currentTime;								// ����擾�������Ԃ�ۑ�

	// FPS�֌W�̏���
	fpsCounter++;
	if (currentTime - fpsCheckTime > 1000000)
	{
		fps = fpsCounter;
		fpsCounter = 0;
		fpsCheckTime = currentTime;
	}
}