#pragma once
#include "NumberStorage.h"
#include "physics/PhysicsGhostObject.h"
enum StageBehind 
{
	STAGEBEHIND_UP = 0,
	STAGEBEHIND_DOWN = 1,
	STAGEBEHIND_RIGHT = 2,
	STAGEBEHIND_LEFT = 3
};
class Box : public IGameObject
{
public:
	Box();
	void InitKabeBox();
	void InitKaidanBox();
	void InitBlock();

	void BlockBoxSetPosition(int Y,int X,Vector3 Position) { M_BlockBox[Y][X].SetPosition(Position); }
	void KaidanBoxSetPosition(Vector3 Position) { M_KaidanBox.SetPosition(Position); }
	void KabeBoxSetPosition(int Direction , Vector3 Position) { M_KabeBox[Direction].SetPosition(Position); }

	bool BlockIsSelf(int Y, int X, const btCollisionObject& contactObject) { return M_BlockBox[Y][X].IsSelf(contactObject); }
	bool KaidanIsSelf(const btCollisionObject& contactObject) { return M_KaidanBox.IsSelf(contactObject); }
	bool KabeIsSelf(int Direction, const btCollisionObject& contactObject) { return M_KabeBox[Direction].IsSelf(contactObject); }
private:
	PhysicsGhostObject M_BlockBox[10][10];
	PhysicsGhostObject M_KaidanBox;
	PhysicsGhostObject M_KabeBox[4];

	Vector3 M_KabePosition[4];
	Quaternion M_KabeRotation[4];
	Vector3 M_KabeScale[4];

	GridPosition S_GridPosition;
};

