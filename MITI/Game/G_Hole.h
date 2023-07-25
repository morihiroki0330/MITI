#pragma once
#include "NumberStorage.h"
class G_Hole : public IGameObject
{
public:
	G_Hole();
	void InitModel();
	void InitPhysicsStaticObject();
	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender M_HoleModel;
	Vector3 M_HolePosition = { 0.0f ,-300.0f,0.0f };
	PhysicsStaticObjectPos M_HolePhysicsStaticObject;
	AllLight M_HoleLight;

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


