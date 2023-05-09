#pragma once
#include "physics/PhysicsGhostObject.h"
class Box : public IGameObject
{
public:
	Box();
	PhysicsGhostObject box[10][10];
	PhysicsGhostObject box_kaidan;
	PhysicsGhostObject box_soto[4];
	Vector3 Box_P[10][10];
};

