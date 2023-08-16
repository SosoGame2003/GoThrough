#pragma once

class Map
{
public:
	Map();
	~Map();

	void Update(float deltaTime);

	void Draw();

private:
	// マップの枠を示す線
	const VECTOR upperLeftFrontPos	 = VGet(-300,  300, -500);	// 左上手前の座標
	const VECTOR upperLeftBackPos	 = VGet(-300,  300, 5000);	// 左上奥の座標
	const VECTOR bottomLeftFrontPos	 = VGet(-300, -300, -500);	// 左下手前の座標
	const VECTOR bottomLeftBackPos	 = VGet(-300, -300, 5000);	// 左下奥の座標
	const VECTOR upperRightFrontPos	 = VGet( 300,  300, -500);	// 右上手前の座標
	const VECTOR upperRightBackPos	 = VGet( 300,  300, 5000);	// 右上奥の座標
	const VECTOR bottomRightFrontPos = VGet( 300, -300, -500);	// 右下手前の座標
	const VECTOR bottomRightBackPos	 = VGet( 300, -300, 5000);	// 右下奥の座標

	int mapBorderCornerLineColor = GetColor(0, 255, 0);	// マップの四隅の枠線の色

	const VECTOR centerLeftFrontPos   = VGet( -300,    0, -500);	// 左中心手前の座標
	const VECTOR centerLeftBackPos    = VGet( -300,    0, 5000);	// 左中心奥の座標
	const VECTOR centerRightFrontPos  = VGet(  300,    0, -500);	// 右中心手前の座標
	const VECTOR centerRightBackPos   = VGet(  300,    0, 5000);	// 右中心奥の座標
	const VECTOR centerUpperFrontPos  = VGet(	 0,  300, -500);	// 上中心手前の座標
	const VECTOR centerUpperBackPos   = VGet(	 0,  300, 5000);	// 上中心奥の座標
	const VECTOR centerBottomFrontPos = VGet(	 0, -300, -500);	// 下中心手前の座標
	const VECTOR centerBottomBackPos  = VGet(	 0, -300, 5000);	// 下中心奥の座標

	int mapBorderCenterLineColor = GetColor(50, 50, 50);	// マップの中心の枠線の色

	// プレイヤーの位置示す線
	const VECTOR playerPosUpperLeftPos	 = VGet(-300, 300, 0);	// マップの枠の左上の座標
	const VECTOR playerPosBottomLeftPos	 = VGet(-300,-300, 0);	// マップの枠の左下の座標
	const VECTOR playerPosUpperRightPos	 = VGet( 300, 300, 0);	// マップの枠の右上の座標
	const VECTOR playerPosBottomRightPos = VGet( 300,-300, 0);	// マップの枠の右下の座標

	int playerPosLineColor = GetColor(255, 0, 0);	// プレイヤーの座標を示すの線の色
};