#pragma once

/// <summary>
/// �v���C���[
/// </summary>
class Player
{
public:
	Player();
	~Player();

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="deltaTime">�f���^�^�C��</param>
	void Update(float deltaTime);

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

private:
	/// <summary>
	/// �ړ�����
	/// </summary>
	/// <param name="deltaTime">�f���^�^�C��</param>
	void Move(float deltaTime);

	/// <summary>
	/// �ړ��\�Ȕ͈�
	/// </summary>
	void MovableRange();

	VECTOR pos;				// �v���C���[�̍��W
	int modelHandle;		// ���f���n���h��
	float moveX;			// X�����̈ړ���
	float moveY;			// Y�����̈ړ���
	float speed = 500.0f;	// �ړ����x

	// �v���C���[�̈ʒu��������
	const VECTOR playerPosUpperLeftPos = VGet(-300, 300, 0);	// �}�b�v�̘g�̍���̍��W
	const VECTOR playerPosBottomLeftPos = VGet(-300, -300, 0);	// �}�b�v�̘g�̍����̍��W
	const VECTOR playerPosUpperRightPos = VGet(300, 300, 0);	// �}�b�v�̘g�̉E��̍��W
	const VECTOR playerPosBottomRightPos = VGet(300, -300, 0);	// �}�b�v�̘g�̉E���̍��W

	int playerPosLineColor = GetColor(255, 0, 0);	// �v���C���[�̍��W�������̐��̐F
};