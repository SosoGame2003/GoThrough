#pragma once

class Map
{
public:
	Map();
	~Map();

	void Update(float deltaTime);

	void Draw();

private:
	// マップ四隅の線
	VECTOR UpperLeftFrontPos	= VGet(-300,  300, -500);	// 左上手前の座標
	VECTOR UpperLeftBackPos		= VGet(-300,  300, 5000);	// 左上奥の座標
	VECTOR BottomLeftFrontPos	= VGet(-300, -300, -500);	// 左下手前の座標
	VECTOR BottomLeftBackPos	= VGet(-300, -300, 5000);	// 左下奥の座標
	VECTOR UpperRightFrontPos	= VGet( 300,  300, -500);	// 右上手前の座標
	VECTOR UpperRightBackPos	= VGet( 300,  300, 5000);	// 右上奥の座標
	VECTOR BottomRightFrontPos	= VGet( 300, -300, -500);	// 右下手前の座標
	VECTOR BottomRightBackPos	= VGet( 300, -300, 5000);	// 右下奥の座標

	int FourCornersOfMapLineColor = GetColor(0, 255, 0);	// マップ四隅の線の色

	// プレイヤーのZ座標を示す線
	VECTOR PlayerPosZUpperLeftPos	= VGet(-300, 300, 0);	// 左上の座標
	VECTOR PlayerPosZBottomLeftPos	= VGet(-300,-300, 0);	// 左下の座標
	VECTOR PlayerPosZUpperRightPos	= VGet( 300, 300, 0);	// 右上の座標
	VECTOR PlayerPosZBottomRightPos = VGet( 300,-300, 0);	// 右下の座標

	int PlayerPosZLineColor = GetColor(255, 0, 0);	// プレイヤーのZ座標の線の色

	// フォグ関係
	float fogStartPos =    0.0f;	// フォグの開始位置
	float fogEndPos	  = 2000.0f;	// フォグの終了位置
};