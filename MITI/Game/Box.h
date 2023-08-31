#pragma once
#include "NumberStorage.h"
#include "physics/PhysicsGhostObject.h"
enum StageBehind 
{
	STAGEBEHIND_UP,
	STAGEBEHIND_DOWN,
	STAGEBEHIND_RIGHT,
	STAGEBEHIND_LEFT,
	STAGEBEHIND_TYPE
};
class Box : public IGameObject
{
public:
	Box();
	void InitKabeBox();
	void InitKaidanBox();
	void InitBlock();

	void BlockBoxSetPosition(int Y,int X,Vector3 Position) 
	{ 
		M_BlockBox[Y][X].SetPosition(Position);
	}
	void KaidanBoxSetPosition(Vector3 Position) 
	{
		M_KaidanBox.SetPosition(Position);
	}
	void KabeBoxSetPosition(int Direction , Vector3 Position) 
	{
		M_KabeBox[Direction].SetPosition(Position); 
	}

	bool BlockIsSelf(int Y, int X, const btCollisionObject& contactObject)
	{ 
		return M_BlockBox[Y][X].IsSelf(contactObject);
	}
	bool KaidanIsSelf(const btCollisionObject& contactObject)
	{
		return M_KaidanBox.IsSelf(contactObject); 
	}
	bool KabeIsSelf(int Direction, const btCollisionObject& contactObject) 
	{ 
		return M_KabeBox[Direction].IsSelf(contactObject);
	}
private:
	PhysicsGhostObject M_BlockBox[M_Ymas][M_Xmas];
	PhysicsGhostObject M_KaidanBox;
	PhysicsGhostObject M_KabeBox[STAGEBEHIND_TYPE];

	Vector3 M_KabePosition[STAGEBEHIND_TYPE];
	Vector3 M_KabeScale[STAGEBEHIND_TYPE];

	Quaternion M_KabeRotation[STAGEBEHIND_TYPE];

	GridPosition S_GridPosition;
	WorldInformation S_WorldInformation;
};

