#pragma once

/// <summary>
/// �ǂ̓��쓙
/// </summary>
class Wall
{
public:
	Wall();
	~Wall();

	void PlayerMove(float deltaTime);
	void PlayerMovable();

	void WallCollision();

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="deltaTime">�f���^�^�C��</param>
	void Update(float deltaTime);

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

	bool gameClear;
	bool gameOver;

private:
	/// <summary>
	/// �`���[�g���A���̈ړ�����
	/// </summary>
	/// <param name="deltaTime">�f���^�^�C��</param>
	void TutorialMove(float deltaTime);

	/// <summary>
	/// ���x���P�X�e�[�W�̈ړ�����
	/// </summary>
	/// <param name="deltaTime">�f���^�^�C��</param>
	void LevelOneMove(float deltaTime);

	/// <summary>
	/// ���x���Q�X�e�[�W�̈ړ�����
	/// </summary>
	/// <param name="deltaTime">�f���^�^�C��</param>
	void LevelTwoMove(float deltaTime);

	/// <summary>
	/// ���x���R�X�e�[�W�̈ړ�����
	/// </summary>
	/// <param name="deltaTime">�f���^�^�C��</param>
	void LevelThreeMove(float deltaTime);

	const float levelOneSpeed	=  600.0f;
	const float levelTwoSpeed	=  900.0f;
	const float levelThreeSpeed = 1200.0f;

	VECTOR tutorialWallPos[2];	// �`���[�g���A���p�̕ǂ̍��W
	int tutorialGraphHandle[2];	// �`���[�g���A���p�̕ǂ̉摜
	bool tutoralWallAliveFlg[2];

	VECTOR levelWallPos[3];
	int levelGraphHandle[3];
	bool levelWallAliveFlg[3];
	bool levelChange[3];

	VECTOR wallPos[18];
	int wallGraphHandle[6];	// �ǂ̉摜�n���h��
	int wallNum[18];
	int randAngle[18];
	float angle[4];
	bool wallAliveFlg[18];	// �����Ă��邩�H

	VECTOR playerPos = VGet(0.0f, 0.0f, 0.0f);
	float moveX;			// X�����̈ړ���
	float moveY;			// Y�����̈ړ���
	float speed = 500.0f;	// �ړ����x
	bool hitCheckFlg[18];
};