// 必要なヘッダーファイルをインクルード
#include<DxLib.h>
#include"Map.h"

Map::Map()
{
}

Map::~Map()
{
}

void Map::Update(float deltaTime)
{
}

void Map::Draw()
{
	// マップの枠を示す線
	DrawLine3D(upperLeftFrontPos,    upperLeftBackPos,    mapBorderCornerLineColor);	// マップ左上の線
	DrawLine3D(bottomLeftFrontPos,   bottomLeftBackPos,   mapBorderCornerLineColor);	// マップ左下の線
	DrawLine3D(upperRightFrontPos,   upperRightBackPos,   mapBorderCornerLineColor);	// マップ右上の線
	DrawLine3D(bottomRightFrontPos,  bottomRightBackPos,  mapBorderCornerLineColor);	// マップ右下の線

	DrawLine3D(centerLeftFrontPos,   centerLeftBackPos,   mapBorderCenterLineColor);	// マップ左中心の線
	DrawLine3D(centerRightFrontPos,  centerRightBackPos,  mapBorderCenterLineColor);	// マップ右中心の線
	DrawLine3D(centerUpperFrontPos,  centerUpperBackPos,  mapBorderCenterLineColor);	// マップ上中心の線
	DrawLine3D(centerBottomFrontPos, centerBottomBackPos, mapBorderCenterLineColor);	// マップ下中心の線

	// プレイヤーの座標を示す線
	DrawLine3D(playerPosUpperLeftPos,   playerPosBottomLeftPos,  playerPosLineColor);	// 左の線
	DrawLine3D(playerPosBottomLeftPos,  playerPosBottomRightPos, playerPosLineColor);	// 下の線
	DrawLine3D(playerPosBottomRightPos, playerPosUpperRightPos,  playerPosLineColor);	// 右の線
	DrawLine3D(playerPosUpperRightPos,  playerPosUpperLeftPos,   playerPosLineColor);	// 上の線

	DrawLine3D(VGet(180, 300, 0), VGet(180, -300, 0), playerPosLineColor);
	DrawLine3D(VGet(60, 300, 0), VGet(60, -300, 0), playerPosLineColor);
	DrawLine3D(VGet(-60, 300, 0), VGet(-60, -300, 0), playerPosLineColor);
	DrawLine3D(VGet(-180, 300, 0), VGet(-180, -300, 0), playerPosLineColor);

	DrawLine3D(VGet(300, 180, 0), VGet(-300, 180, 0), playerPosLineColor);
	DrawLine3D(VGet(300, 60, 0), VGet(-300, 60, 0), playerPosLineColor);
	DrawLine3D(VGet(300, -60, 0), VGet(-300, -60, 0), playerPosLineColor);
	DrawLine3D(VGet(300, -180, 0), VGet(-300, -180, 0), playerPosLineColor);
}