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

	VECTOR pos;				// プレイヤーの座標
	int modelHandle;		// モデルハンドル
	float moveX;			// X方向の移動量
	float moveY;			// Y方向の移動量
	float speed = 500.0f;	// 移動速度

	// プレイヤーの位置を示す線
	const VECTOR playerPosUpperLeftPos = VGet(-300, 300, 0);	// マップの枠の左上の座標
	const VECTOR playerPosBottomLeftPos = VGet(-300, -300, 0);	// マップの枠の左下の座標
	const VECTOR playerPosUpperRightPos = VGet(300, 300, 0);	// マップの枠の右上の座標
	const VECTOR playerPosBottomRightPos = VGet(300, -300, 0);	// マップの枠の右下の座標

	int playerPosLineColor = GetColor(255, 0, 0);	// プレイヤーの座標を示すの線の色
};