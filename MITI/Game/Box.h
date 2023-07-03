#pragma once
#include "physics/PhysicsGhostObject.h"
enum StageBehind 
{
	StageBehindUp,
	StageBehindDown,
	StageBehindRight,
	StageBehindLeft
};
class Player;
class Game;
class Box : public IGameObject
{
public:
	Box();
	bool Start();
	void InitKabeBox();
	void InitKaidanBox();
	void InitBlock();

	void BlockBoxSetPosition(int Y,int X,Vector3 Position) { BlockBox[Y][X].SetPosition(Position); }
	void KaidanBoxSetPosition(Vector3 Position) { KaidanBox.SetPosition(Position); }
	void KabeBoxSetPosition(int Direction , Vector3 Position) { KabeBox[Direction].SetPosition(Position); }

	bool BlockIsSelf(int Y, int X, const btCollisionObject& contactObject) { return BlockBox[Y][X].IsSelf(contactObject); }
	bool KaidanIsSelf(const btCollisionObject& contactObject) { return KaidanBox.IsSelf(contactObject); }
	bool KabeIsSelf(int Direction, const btCollisionObject& contactObject) { return KabeBox[Direction].IsSelf(contactObject); }
private:
	PhysicsGhostObject BlockBox[10][10];
	PhysicsGhostObject KaidanBox;
	PhysicsGhostObject KabeBox[4];

	Vector3 KabePosition[4];
	Quaternion KabeRotation[4];
	Vector3 KabeScale[4];

	Player* player = nullptr;
	Game* game = nullptr;
};

