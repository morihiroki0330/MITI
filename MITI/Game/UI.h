#pragma once
#include "NumberStorage.h"
class Player;
class Game;
class IronBall;
class UI : public IGameObject
{
public:
	UI();
	void InitTexture();
	void InitPosition();
	void InitUpdate();

	void Time();

	void Button();

	void Update();

	void Render(RenderContext& rc);
private:
	SpriteRender M_CanvasTexture;

	SpriteRender M_AbuttonTexture;
	Vector3 M_AbuttonPosition = { 680.0f , -400.0f , 0.0f };
	Vector4 M_AbuttonCollar_TRUE = { 1.0f , 1.0f , 1.0f , 1.0f };
	Vector4 M_AbuttonCollar_FALSE = { 1.0f , 1.0f , 1.0f , 0.7f };

	SpriteRender M_BbuttonTexture;
	Vector3 M_BbuttonPosition = { 830.0f , -400.0f , 0.0f };
	Vector4 M_BbuttonCollar_TRUE = { 1.0f , 1.0f , 1.0f , 1.0f };
	Vector4 M_BbuttonCollar_FALSE = { 1.0f , 1.0f , 1.0f , 0.7f };

	SpriteRender M_ControllerUpTexture;
	SpriteRender M_ControllerDownTexture;
	SpriteRender M_ControllerRightTexture;
	SpriteRender M_ControllerLeftTexture;
	SpriteRender M_ControllerNonTexture;
	Vector3 M_ControllerPosition = { -750.0f , -400.0f , 0.0f };

	SpriteRender M_IronBallCountTexture[6];
	Vector3 M_IronBallCountPosition = { 750.0f , -50.0f , 0.0f };
	
	SpriteRender M_StageCountTexture[11];

	FontRender M_TimerFont;
	Vector3 M_TimerPosition = { 830.0f , 305.0f , 0.0f };
	SpriteRender M_TimerFrameTexture;
	wchar_t M_Clock[256];
	int M_Timer = 0;
	int M_TimerOver = 0;
	int M_TimerLimit = 100;

	Player* M_Player = nullptr;
	Game* M_Game = nullptr;
	IronBall* M_IronBall = nullptr;

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

