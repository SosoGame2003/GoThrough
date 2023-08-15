#pragma once

/// <summary>
/// プレイヤー
/// </summary>
class Player
{
public:
	Player();
	~Player();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="deltaTime">デルタタイム</param>
	void Update(float deltaTime);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

private:
	/// <summary>
	/// 移動処理
	/// </summary>
	/// <param name="deltaTime">デルタタイム</param>
	void Move(float deltaTime);

	/// <summary>
	/// 移動可能な範囲
	/// </summary>
	void MovableRange();

	VECTOR pos;			// プレイヤーの座標
	int modelHandle;	// モデルハンドル
	float moveX;		// X方向の移動量
	float moveY;		// Y方向の移動量
	float speed = 250.0f;	// 移動速度
};