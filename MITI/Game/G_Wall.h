#pragma once
#include "NumberStorage.h"
	class G_Wall :public IGameObject
	{
	public:
		G_Wall();
		void InitModel();
		void InitPhysicsStaticObject();
		void Update();
		void Render(RenderContext& rc);
	private:
		ModelRender M_WallModel;
		Vector3 M_WallPosition = { 0.0f,82.0f,0.0f };
		PhysicsStaticObjectPos M_WallPhysicsStaticObject;
		AllLight M_WallLight;

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

