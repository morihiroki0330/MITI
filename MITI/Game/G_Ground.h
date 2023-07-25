#pragma once
#include "NumberStorage.h"
class G_Ground : public IGameObject
{
public:
	G_Ground();

	void InitModel();
	void InitPhysicsStaticObject();

	void GroundOnTrue(int Y, int X);
	void GroundSetPosition(int Y, int X, Vector3 Position);

	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender M_GroundModel[10][10];
	Vector3 M_GroundPosition[10][10];
	Vector3 M_GroundSparePosition[10][10];
	PhysicsStaticObjectPos M_GroundPhysicsStaticObject[10][10];
	AllLight M_GroundLight;
	bool M_GroundOn[10][10];

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

