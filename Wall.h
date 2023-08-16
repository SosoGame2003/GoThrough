#pragma once

/// <summary>
/// 壁の動作等
/// </summary>
class Wall
{
public:
	Wall();
	~Wall();

	void WallCollision();

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
	/// チュートリアルの移動処理
	/// </summary>
	/// <param name="deltaTime">デルタタイム</param>
	void TutorialMove(float deltaTime);

	/// <summary>
	/// レベル１ステージの移動処理
	/// </summary>
	/// <param name="deltaTime">デルタタイム</param>
	void LevelOneMove(float deltaTime);

	/// <summary>
	/// レベル２ステージの移動処理
	/// </summary>
	/// <param name="deltaTime">デルタタイム</param>
	void LevelTwoMove(float deltaTime);

	/// <summary>
	/// レベル３ステージの移動処理
	/// </summary>
	/// <param name="deltaTime">デルタタイム</param>
	void LevelThreeMove(float deltaTime);

	VECTOR tutorialWallPos[2];	// チュートリアル用の壁の座標
	int tutorialGraphHandle[2];	// チュートリアル用の壁の画像
	bool tutoralWallAliveFlg[2];

	VECTOR levelWallPos[3];
	int levelGraphHandle[3];
	bool levelWallAliveFlg[3];
	bool levelChange[3];

	VECTOR wallPos[18];
	int wallGraphHandle[6];	// 壁の画像ハンドル
	int wallNum[18];
	int randAngle[18];
	float angle[4];
	bool wallAliveFlg[18];	// 生きているか？

	const float levelOneSpeed = 600.0f;
	const float levelTwoSpeed = 900.0f;
	const float levelThreeSpeed = 1200.0f;
};