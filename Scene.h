#pragma once

/// <summary>
/// �V�[���̃^�O
/// </summary>
enum class SCENE_TAG
{
	MENU,	// ���j���[
	PLAY,	// �v���C
	RESULT,	// ���U���g
	END,	// �Q�[���I��
	NONE,	// �߂�l
};

/// <summary>
/// �V�[��
/// </summary>
class Scene
{
public:
	Scene(){ /*�����Ȃ�*/ }
	virtual ~Scene() { /*�����Ȃ�*/ }

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="deltaTime">�f���^�^�C��</param>
	/// <returns>NONE</returns>
	virtual SCENE_TAG Update(float deltaTime) = 0;

	/// <summary>
	/// �`�揈��
	/// </summary>
	virtual void Draw() = 0;
};