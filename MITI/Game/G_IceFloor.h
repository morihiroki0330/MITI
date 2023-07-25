#pragma once
#include "NumberStorage.h"
class Player;
class Stage;
class G_IceFloor:public IGameObject
{
public:
	G_IceFloor();
	bool Start();

	void InitModel();
	void InitPhysicsStaticObject();

	void IceFloorOnPlayer();
	void IceFloorOnTrue(int Y, int X);
	void IceFloorSetPosition(int Y, int X, Vector3 Position);

	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender M_IceFloorModel[10][10];
	Vector3 M_IceFloorPosition[10][10];
	PhysicsStaticObjectPos M_IceFloorPhysicsStaticObject[10][10];
	AllLight M_IceFloorLight;
	bool M_IceFloorOn[10][10];

	Player* M_Player = nullptr;
	Stage* M_Stage = nullptr;

	TextureHeight S_TextureHeight;
	TextureWide S_TextureWide;
	Color S_Color;
	FadeInformation S_FadeInformation;
	GridPosition S_GridPosition;
	SoundSetting S_SoundSetting;
	PlayerInformation S_PlayerInformation;
	BlockInformation S_BlockInformation;
	WorldInformation S_WorldInformation;
	IronBallInformation S_IronBallInformation;
};

