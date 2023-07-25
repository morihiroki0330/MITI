#pragma once
#include "NumberStorage.h"
class Box;
class G_Kaidan : public IGameObject
{
public:
	G_Kaidan();
	bool Start();

	void InitModel();

	void Map_SetPosition(Vector3 Position);

	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender M_KaidanModel;
	Vector3 M_KaidanPosition = { 0.0f,0.0f,0.0f };
	Vector3 M_KaidanScale = { 1.0f,1.0f,2.0f };
	Quaternion M_KaidanRotation;
	AllLight M_KaidanLight;

	Box* M_Box = nullptr;

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

