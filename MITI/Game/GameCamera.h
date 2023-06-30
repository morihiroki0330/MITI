#pragma once
#include "Number_Storage.h"
class GameCamera : public IGameObject
{
public:
	bool Start();
	void Update();

	Vector3 Target_Position = { NON,NON,NON };
	Vector3 Camera_Position = { NON,NON,NON };
};

