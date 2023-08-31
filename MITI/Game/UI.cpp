#include "stdafx.h"
#include "UI.h"
#include "Player.h"
#include "Game.h"
#include "IronBall.h"
UI::UI() 
{
	P_Player = FindGO<Player>("player");
	P_Game = FindGO<Game>("game");
	P_IronBall = FindGO<IronBall>("ironball");
	InitTexture();
}
void UI::InitTexture()
{
	M_CanvasTexture.Init("Assets/UI/UI_canvas.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	
	M_AbuttonTexture.Init("Assets/UI/A.DDS", S_TextureWide.M_ButtonWide, S_TextureHeight.M_ButtonHeight);
	M_BbuttonTexture.Init("Assets/UI/B.DDS", S_TextureWide.M_ButtonWide, S_TextureHeight.M_ButtonHeight);
	
	M_ControllerTexture[DIRECTION_UP].Init("Assets/UI/Controller-Up.DDS", S_TextureWide.M_ControllerWide, S_TextureHeight.M_ControllerHeight);
	M_ControllerTexture[DIRECTION_DOWN].Init("Assets/UI/Controller-Down.DDS", S_TextureWide.M_ControllerWide, S_TextureHeight.M_ControllerHeight);
	M_ControllerTexture[DIRECTION_RIGHT].Init("Assets/UI/Controller-Right.DDS", S_TextureWide.M_ControllerWide, S_TextureHeight.M_ControllerHeight);
	M_ControllerTexture[DIRECTION_LEFT].Init("Assets/UI/Controller-Left.DDS", S_TextureWide.M_ControllerWide, S_TextureHeight.M_ControllerHeight);
	M_ControllerTexture[DIRECTION_NON].Init("Assets/UI/Controller-Non.DDS", S_TextureWide.M_ControllerWide, S_TextureHeight.M_ControllerHeight);

	M_IronBallTexture[NUMBER_NON].Init("Assets/UI/Iron-Non.DDS", S_TextureWide.M_IronBallWide, S_TextureHeight.M_IronBallHeight);
	M_IronBallTexture[NUMBER_ONE].Init("Assets/UI/Iron-One.DDS", S_TextureWide.M_IronBallWide, S_TextureHeight.M_IronBallHeight);
	M_IronBallTexture[NUMBER_TWO].Init("Assets/UI/Iron-Two.DDS", S_TextureWide.M_IronBallWide, S_TextureHeight.M_IronBallHeight);
	M_IronBallTexture[NUMBER_THREE].Init("Assets/UI/Iron-Three.DDS", S_TextureWide.M_IronBallWide, S_TextureHeight.M_IronBallHeight);
	M_IronBallTexture[NUMBER_FOUR].Init("Assets/UI/Iron-Four.DDS", S_TextureWide.M_IronBallWide, S_TextureHeight.M_IronBallHeight);
	M_IronBallTexture[NUMBER_FIVE].Init("Assets/UI/Iron-Five.DDS", S_TextureWide.M_IronBallWide, S_TextureHeight.M_IronBallHeight);

	M_StageCountTexture[STAGEORDER_ONE].Init("Assets/UI/Level1.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_StageCountTexture[STAGEORDER_TWO].Init("Assets/UI/Level2.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_StageCountTexture[STAGEORDER_THREE].Init("Assets/UI/Level3.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_StageCountTexture[STAGEORDER_FOUR].Init("Assets/UI/Level4.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_StageCountTexture[STAGEORDER_FIVE].Init("Assets/UI/Level5.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_StageCountTexture[STAGEORDER_SIX].Init("Assets/UI/Level6.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_StageCountTexture[STAGEORDER_SEVEN].Init("Assets/UI/Level7.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_StageCountTexture[STAGEORDER_EIGHT].Init("Assets/UI/Level8.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_StageCountTexture[STAGEORDER_NINE].Init("Assets/UI/Level9.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_StageCountTexture[STAGEORDER_TEN].Init("Assets/UI/Level10.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);

	M_TimerFrameTexture.Init("Assets/UI/Timer.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
}

void UI::Timer()
{
	M_Timer++;
	M_TimerOver = M_TimerLimit - M_Timer / 60;
	if (M_TimerOver <= 1)
	{ 
		P_Game->GameOverFlagSet(true); 

	}

	swprintf_s(M_Clock, 256, L"%d", M_TimerOver);
	M_TimerFont.SetText(M_Clock);
	M_TimerFont.SetPosition(M_TimerPosition);
	M_TimerFont.SetScale(1.0f);
}
void UI::IronBallButton()
{
	if (P_Player->GetIronBallCount() < P_IronBall->GetIronBallMax() && P_Player->GetIronBallCount() >= P_IronBall->GetIronBallMin())
	{ 
		M_AbuttonTexture.SetMulColor(M_AbuttonOnCollar);
	}
	if (P_Player->GetIronBallCount() >= P_IronBall->GetIronBallMax())
	{ 
		M_AbuttonTexture.SetMulColor(M_AbuttonOffCollar);
	}
	if (P_Player->GetIronBallCount() <= P_IronBall->GetIronBallMax() && P_Player->GetIronBallCount() >= P_IronBall->GetIronBallMin())
	{
		M_BbuttonTexture.SetMulColor(M_BbuttonOnCollar);
	}
	if (P_Player->GetIronBallCount() <= P_IronBall->GetIronBallMin())
	{
		M_BbuttonTexture.SetMulColor(M_BbuttonOffCollar);
	}
}

void UI::Update()
{
	if (P_Game->GetPauseFlag())
	{
		return;
	}
	Timer();
	IronBallButton();

	M_AbuttonTexture.SetPosition(M_AbuttonPosition);
	M_AbuttonTexture.Update();

	M_BbuttonTexture.SetPosition(M_BbuttonPosition);
	M_BbuttonTexture.Update();

	M_CanvasTexture.Update();
	M_TimerFrameTexture.Update();
	for (int i = 0; i < 10; i++)
	{
		if (i < CONTROLLER_TYPE)
		{
			M_ControllerTexture[i].SetPosition(M_ControllerPosition);
			M_ControllerTexture[i].Update();
		}
		if (i < IRONBALL_TYPE)
		{
			M_IronBallTexture[i].SetPosition(M_IronBallPosition);
			M_IronBallTexture[i].Update();
		}
		if (i < STAGE_TYPE)
		{
			M_StageCountTexture[i].Update();
		}
	}
}
void UI::Render(RenderContext& rc)
{
	M_CanvasTexture.Draw(rc);
	M_AbuttonTexture.Draw(rc);
	M_BbuttonTexture.Draw(rc);
	M_IronBallTexture[P_Player->GetIronBallCount()].Draw(rc);
	M_StageCountTexture[P_Game->GetLevel()].Draw(rc);
	M_TimerFrameTexture.Draw(rc);
	M_TimerFont.Draw(rc);

	if (P_Player->GetPlayerMoveSpeedX() < 0.0f)
	{ 
		M_ControllerTexture[DIRECTION_UP].Draw(rc);
	}else {
		if (P_Player->GetPlayerMoveSpeedX() > 0.0f)
		{ 
			M_ControllerTexture[DIRECTION_DOWN].Draw(rc);
		}else {
			if (P_Player->GetPlayerMoveSpeedZ() > 0.0f)
			{ 
				M_ControllerTexture[DIRECTION_RIGHT].Draw(rc);
			}else {
				if (P_Player->GetPlayerMoveSpeedZ() < 0.0f) 
				{ 
					M_ControllerTexture[DIRECTION_LEFT].Draw(rc);
				}else {
					M_ControllerTexture[DIRECTION_DOWN].Draw(rc);}
			}
		}
	}
}