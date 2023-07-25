#pragma once
#include "NumberStorage.h"
class GameCamera : public IGameObject
{
public:
	bool Start();
	void Update();
private:
	Vector3 M_TargetPosition = { 0.0f,0.0f,0.0f };
	Vector3 M_CameraPosition = { 0.0f,0.0f,0.0f };
};

