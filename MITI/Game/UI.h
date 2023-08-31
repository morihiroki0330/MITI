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

	void Timer();
	void IronBallButton();

	void Update();
	void Render(RenderContext& rc);
private:
	enum ControllerInformation
	{
		DIRECTION_UP,
		DIRECTION_DOWN,
		DIRECTION_RIGHT,
		DIRECTION_LEFT,
		DIRECTION_NON,
		CONTROLLER_TYPE
	};
	enum IronBallInformation
	{
		NUMBER_NON,
		NUMBER_ONE,
		NUMBER_TWO,
		NUMBER_THREE,
		NUMBER_FOUR,
		NUMBER_FIVE,
		IRONBALL_TYPE
	};
	enum StageInformation
	{
		STAGEORDER_ONE,
		STAGEORDER_TWO,
		STAGEORDER_THREE,
		STAGEORDER_FOUR,
		STAGEORDER_FIVE,
		STAGEORDER_SIX,
		STAGEORDER_SEVEN,
		STAGEORDER_EIGHT,
		STAGEORDER_NINE,
		STAGEORDER_TEN,
		STAGE_TYPE
	};

	SpriteRender M_CanvasTexture;
	SpriteRender M_AbuttonTexture;
	SpriteRender M_BbuttonTexture;
	SpriteRender M_ControllerTexture[CONTROLLER_TYPE];
	SpriteRender M_IronBallTexture[IRONBALL_TYPE];
	SpriteRender M_StageCountTexture[STAGE_TYPE];
	SpriteRender M_TimerFrameTexture;
	
	FontRender M_TimerFont;

	Vector4 M_AbuttonOnCollar  = { 1.0f , 1.0f , 1.0f , 1.0f };
	Vector4 M_AbuttonOffCollar = { 1.0f , 1.0f , 1.0f , 0.7f };
	Vector4 M_BbuttonOnCollar  = { 1.0f , 1.0f , 1.0f , 1.0f };
	Vector4 M_BbuttonOffCollar = { 1.0f , 1.0f , 1.0f , 0.7f };

	Vector3 M_BbuttonPosition    = { 830.0f  , -400.0f , 0.0f };
	Vector3 M_AbuttonPosition    = { 680.0f  , -400.0f , 0.0f };
	Vector3 M_ControllerPosition = { -750.0f , -400.0f , 0.0f };
	Vector3 M_IronBallPosition   = { 750.0f  , -50.0f  , 0.0f };
	Vector3 M_TimerPosition      = { 830.0f  , 305.0f  , 0.0f };
	
	wchar_t M_Clock[256];
	int M_Timer = 0;
	int M_TimerOver = 0;
	int M_TimerLimit = 100;
	
	Player* P_Player = nullptr;
	Game* P_Game = nullptr;
	IronBall* P_IronBall = nullptr;

	TextureHeight S_TextureHeight;
	TextureWide S_TextureWide;
	SoundSetting S_SoundSetting;
};

