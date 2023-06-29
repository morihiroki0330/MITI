#pragma once
#include "physics/PhysicsGhostObject.h"
enum 
{
	UP,
	DOWN,
	RIGHT,
	LEFT
};
class Player;
class Game;
class Box : public IGameObject
{
public:
	bool Start();
	void KabeBoxSet();
	void BlockBox_SetPosition(int Y,int X,Vector3 Position) { BlockBox[Y][X].SetPosition(Position); }
	void KaidanBox_SetPosition(Vector3 Position) { KaidanBox.SetPosition(Position); }
	void KabeBox_SetPosition(int Direction , Vector3 Position) { KabeBox[Direction].SetPosition(Position); }

	PhysicsGhostObject BlockBox[10][10];
	PhysicsGhostObject KaidanBox;
	PhysicsGhostObject KabeBox[4];

	Vector3 Kabe_Position[4];
	Vector3 Kabe_Size[4];
	Vector3 Box_Position[10][10];
	
	Quaternion Kabe_Rotation[4];

	Player* player = nullptr;
	Game* game = nullptr;;
};

