// �K�v�ȃw�b�_�[�t�@�C�����C���N���[�h
#include<DxLib.h>
#include"Result.h"

Result::Result()
{

}

Result::~Result()
{
}

SCENE_TAG Result::Update(float deltaTime)
{
	if (CheckHitKey(KEY_INPUT_END))
	{
		return SCENE_TAG::MENU;
	}

	return SCENE_TAG::NONE;	// �V�[���̕ύX�Ȃ�
}

void Result::Draw()
{

}