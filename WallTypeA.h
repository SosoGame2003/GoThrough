#pragma once

#include"Wall.h"

class WallTypeA : public Wall
{
public:
	WallTypeA();
	~WallTypeA();

	WALL_TAG Update(float deltaTime) override;

	void Draw() override;

private:
	int graphHandle;
	VECTOR pos;
	float speed;

	int nextWallNum;
};