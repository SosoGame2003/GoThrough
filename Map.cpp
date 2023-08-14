// 必要なヘッダーファイルをインクルード
#include<DxLib.h>
#include"Map.h"

Map::Map()
{
	SetFogEnable(TRUE);
	SetFogColor(0, 0, 0);
	SetFogStartEnd(fogStartPos, fogEndPos);
}

Map::~Map()
{
}

void Map::Update(float deltaTime)
{
}

void Map::Draw()
{
	// マップ四隅の線
	DrawLine3D(UpperLeftFrontPos,   UpperLeftBackPos,   FourCornersOfMapLineColor);	// マップ左上の線
	DrawLine3D(BottomLeftFrontPos,  BottomLeftBackPos,  FourCornersOfMapLineColor);	// マップ左下の線
	DrawLine3D(UpperRightFrontPos,  UpperRightBackPos,  FourCornersOfMapLineColor);	// マップ右上の線
	DrawLine3D(BottomRightFrontPos, BottomRightBackPos, FourCornersOfMapLineColor);	// マップ右下の線

	// プレイヤーのZ座標を示す線
	DrawLine3D(PlayerPosZUpperLeftPos,   PlayerPosZBottomLeftPos,  PlayerPosZLineColor);	// 左の線
	DrawLine3D(PlayerPosZBottomLeftPos,  PlayerPosZBottomRightPos, PlayerPosZLineColor);	// 下の線
	DrawLine3D(PlayerPosZBottomRightPos, PlayerPosZUpperRightPos,  PlayerPosZLineColor);	// 右の線
	DrawLine3D(PlayerPosZUpperRightPos,  PlayerPosZUpperLeftPos,   PlayerPosZLineColor);	// 上の線
}