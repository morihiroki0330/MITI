#include "stdafx.h"
#include "UI.h"
#include "Player.h"
#include "Game.h"
#include "IronBall.h"
#include "NumberStorage.h"
UI::UI() 
{
	P_Player = FindGO<Player>("player");
	P_Game = FindGO<Game>("game");
	P_IronBall = FindGO<IronBall>("ironball");
	InitTexture();
	InitPosition();
	InitUpdate();
}
void UI::InitTexture()
{
	M_CanvasTexture.Init("Assets/UI/UI_canvas.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	
	M_AbuttonTexture.Init("Assets/UI/A.DDS", S_TextureWide.M_ButtonWide, S_TextureHeight.M_ButtonHeight);
	M_BbuttonTexture.Init("Assets/UI/B.DDS", S_TextureWide.M_ButtonWide, S_TextureHeight.M_ButtonHeight);

	M_ControllerNonTexture.Init("Assets/UI/Controller-Non.DDS", S_TextureWide.M_ControllerWide, S_TextureHeight.M_ControllerHeight);
	M_ControllerUpTexture.Init("Assets/UI/Controller-Up.DDS", S_TextureWide.M_ControllerWide, S_TextureHeight.M_ControllerHeight);
	M_ControllerDownTexture.Init("Assets/UI/Controller-Down.DDS", S_TextureWide.M_ControllerWide, S_TextureHeight.M_ControllerHeight);
	M_ControllerLeftTexture.Init("Assets/UI/Controller-Left.DDS", S_TextureWide.M_ControllerWide, S_TextureHeight.M_ControllerHeight);
	M_ControllerRightTexture.Init("Assets/UI/Controller-Right.DDS", S_TextureWide.M_ControllerWide, S_TextureHeight.M_ControllerHeight);

	M_IronBallCountTexture[0].Init("Assets/UI/Iron-Non.DDS", S_TextureWide.M_IronBallWide, S_TextureHeight.M_IronBallHeight);
	M_IronBallCountTexture[1].Init("Assets/UI/Iron-One.DDS", S_TextureWide.M_IronBallWide, S_TextureHeight.M_IronBallHeight);
	M_IronBallCountTexture[2].Init("Assets/UI/Iron-Two.DDS", S_TextureWide.M_IronBallWide, S_TextureHeight.M_IronBallHeight);
	M_IronBallCountTexture[3].Init("Assets/UI/Iron-Three.DDS", S_TextureWide.M_IronBallWide, S_TextureHeight.M_IronBallHeight);
	M_IronBallCountTexture[4].Init("Assets/UI/Iron-Four.DDS", S_TextureWide.M_IronBallWide, S_TextureHeight.M_IronBallHeight);
	M_IronBallCountTexture[5].Init("Assets/UI/Iron-Five.DDS", S_TextureWide.M_IronBallWide, S_TextureHeight.M_IronBallHeight);

	M_StageCountTexture[0].Init("Assets/UI/Level1.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_StageCountTexture[1].Init("Assets/UI/Level2.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_StageCountTexture[2].Init("Assets/UI/Level3.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_StageCountTexture[3].Init("Assets/UI/Level4.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_StageCountTexture[4].Init("Assets/UI/Level5.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_StageCountTexture[5].Init("Assets/UI/Level6.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_StageCountTexture[6].Init("Assets/UI/Level7.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_StageCountTexture[7].Init("Assets/UI/Level8.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_StageCountTexture[8].Init("Assets/UI/Level9.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_StageCountTexture[9].Init("Assets/UI/Level10.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);

	M_TimerFrameTexture.Init("Assets/UI/Timer.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
}
void UI::InitPosition()
{
	M_AbuttonTexture.SetPosition(M_AbuttonPosition);
	M_BbuttonTexture.SetPosition(M_BbuttonPosition);

	M_ControllerNonTexture.SetPosition(M_ControllerPosition);
	M_ControllerUpTexture.SetPosition(M_ControllerPosition);
	M_ControllerDownTexture.SetPosition(M_ControllerPosition);
	M_ControllerLeftTexture.SetPosition(M_ControllerPosition);
	M_ControllerRightTexture.SetPosition(M_ControllerPosition);

	M_IronBallCountTexture[0].SetPosition(M_IronBallCountPosition);
	M_IronBallCountTexture[1].SetPosition(M_IronBallCountPosition);
	M_IronBallCountTexture[2].SetPosition(M_IronBallCountPosition);
	M_IronBallCountTexture[3].SetPosition(M_IronBallCountPosition);
	M_IronBallCountTexture[4].SetPosition(M_IronBallCountPosition);
	M_IronBallCountTexture[5].SetPosition(M_IronBallCountPosition);
}
void UI::InitUpdate()
{
	M_CanvasTexture.Update();

	M_AbuttonTexture.Update();
	M_BbuttonTexture.Update();

	M_ControllerNonTexture.Update();
	M_ControllerUpTexture.Update();
	M_ControllerDownTexture.Update();
	M_ControllerLeftTexture.Update();
	M_ControllerRightTexture.Update();

	M_IronBallCountTexture[0].Update();
	M_IronBallCountTexture[1].Update();
	M_IronBallCountTexture[2].Update();
	M_IronBallCountTexture[3].Update();
	M_IronBallCountTexture[4].Update();
	M_IronBallCountTexture[5].Update();

	M_StageCountTexture[1].Update();
	M_StageCountTexture[2].Update();
	M_StageCountTexture[3].Update();
	M_StageCountTexture[4].Update();
	M_StageCountTexture[5].Update();
	M_StageCountTexture[6].Update();
	M_StageCountTexture[7].Update();
	M_StageCountTexture[8].Update();
	M_StageCountTexture[9].Update();
	M_StageCountTexture[10].Update();

	M_TimerFrameTexture.Update();
}
void UI::Time()
{
	M_Timer++;
	M_TimerOver = M_TimerLimit - M_Timer / 60;
	if (M_TimerOver <= 0){ P_Game->GameOverFlagSet(true); }

	swprintf_s(M_Clock, 256, L"%d", M_TimerOver);
	M_TimerFont.SetText(M_Clock);
	M_TimerFont.SetPosition(M_TimerPosition);
	M_TimerFont.SetScale(1.0f);
}
void UI::Button()
{
	if (P_Player->GetIronBallCount() < P_IronBall->GetIronBallMax() && P_Player->GetIronBallCount() >= P_IronBall->GetIronBallMin())
	{ 
		M_AbuttonTexture.SetMulColor(M_AbuttonCollar_TRUE);
	}

	if (P_Player->GetIronBallCount() >= P_IronBall->GetIronBallMax())
	{ 
		M_AbuttonTexture.SetMulColor(M_AbuttonCollar_FALSE);
	}

	if (P_Player->GetIronBallCount() <= P_IronBall->GetIronBallMax() && P_Player->GetIronBallCount() >= P_IronBall->GetIronBallMin())
	{
		M_BbuttonTexture.SetMulColor(M_BbuttonCollar_TRUE);
	}

	if (P_Player->GetIronBallCount() <= P_IronBall->GetIronBallMin())
	{
		M_BbuttonTexture.SetMulColor(M_BbuttonCollar_FALSE);
	}
}
void UI::Update()
{
	Time();
	Button();

	M_AbuttonTexture.Update();
	M_BbuttonTexture.Update();

	M_IronBallCountTexture[P_Player->GetIronBallCount()].Update();

	if (P_Player->GetPlayerMoveSpeedX() < 0.0f) { M_ControllerUpTexture.Update(); }
	else {
	if (P_Player->GetPlayerMoveSpeedX() > 0.0f) { M_ControllerDownTexture.Update(); }
	else {
	if (P_Player->GetPlayerMoveSpeedZ() > 0.0f) { M_ControllerRightTexture.Update(); }
	else {
	if (P_Player->GetPlayerMoveSpeedZ() < 0.0f){ M_ControllerLeftTexture.Update();}
	else { M_ControllerNonTexture.Update();}
	}
	}
	}
}
void UI::Render(RenderContext& rc)
{
	M_CanvasTexture.Draw(rc);

	M_AbuttonTexture.Draw(rc);
	M_BbuttonTexture.Draw(rc);

	M_IronBallCountTexture[P_Player->GetIronBallCount()].Draw(rc);
	M_StageCountTexture[P_Game->GetLevel()].Draw(rc);

	if (P_Player->GetPlayerMoveSpeedX() < 0.0f) { M_ControllerUpTexture.Draw(rc);}
	else {
	if (P_Player->GetPlayerMoveSpeedX() > 0.0f) { M_ControllerDownTexture.Draw(rc);}
	else {
	if (P_Player->GetPlayerMoveSpeedZ() > 0.0f) { M_ControllerRightTexture.Draw(rc);}
	else {
	if (P_Player->GetPlayerMoveSpeedZ() < 0.0f) { M_ControllerLeftTexture.Draw(rc);}
	else { M_ControllerNonTexture.Draw(rc);}
	}
	}
	}

	M_TimerFrameTexture.Draw(rc);
	M_TimerFont.Draw(rc);
}