#include "stdafx.h"
#include "UI.h"
#include "Player.h"
#include "Game.h"
#include "IronBall.h"
#include "Number_Storage.h"
bool UI::Start() 
{
	player = FindGO<Player>("player");
	game = FindGO<Game>("game");
	ironball = FindGO<IronBall>("ironball");
	InitTexture();
	InitPosition();
	InitUpdate();
	return true;
}
void UI::InitTexture()
{
	CanvasTexture.Init("Assets/UI/UI_canvas.DDS", ScreenWide, ScreenHeight);

	AbuttonTexture.Init("Assets/UI/A.DDS", ButtonWide, ButtonHeight);
	BbuttonTexture.Init("Assets/UI/B.DDS", ButtonWide, ButtonHeight);

	ControllerNonTexture.Init("Assets/UI/Controller-Non.DDS", ControllerWide, ControllerHeight);
	ControllerUpTexture.Init("Assets/UI/Controller-Up.DDS", ControllerWide, ControllerHeight);
	ControllerDownTexture.Init("Assets/UI/Controller-Down.DDS", ControllerWide, ControllerHeight);
	ControllerLeftTexture.Init("Assets/UI/Controller-Left.DDS", ControllerWide, ControllerHeight);
	ControllerRightTexture.Init("Assets/UI/Controller-Right.DDS", ControllerWide, ControllerHeight);

	IronBallCountTexture[0].Init("Assets/UI/Iron-Non.DDS", IronBallWide, IronBallHeight);
	IronBallCountTexture[1].Init("Assets/UI/Iron-One.DDS", IronBallWide, IronBallHeight);
	IronBallCountTexture[2].Init("Assets/UI/Iron-Two.DDS", IronBallWide, IronBallHeight);
	IronBallCountTexture[3].Init("Assets/UI/Iron-Three.DDS", IronBallWide, IronBallHeight);
	IronBallCountTexture[4].Init("Assets/UI/Iron-Four.DDS", IronBallWide, IronBallHeight);
	IronBallCountTexture[5].Init("Assets/UI/Iron-Five.DDS", IronBallWide, IronBallHeight);

	StageCountTexture[0].Init("Assets/UI/Level1.DDS", ScreenWide, ScreenHeight);
	StageCountTexture[1].Init("Assets/UI/Level2.DDS", ScreenWide, ScreenHeight);
	StageCountTexture[2].Init("Assets/UI/Level3.DDS", ScreenWide, ScreenHeight);
	StageCountTexture[3].Init("Assets/UI/Level4.DDS", ScreenWide, ScreenHeight);
	StageCountTexture[4].Init("Assets/UI/Level5.DDS", ScreenWide, ScreenHeight);
	StageCountTexture[5].Init("Assets/UI/Level6.DDS", ScreenWide, ScreenHeight);
	StageCountTexture[6].Init("Assets/UI/Level7.DDS", ScreenWide, ScreenHeight);
	StageCountTexture[7].Init("Assets/UI/Level8.DDS", ScreenWide, ScreenHeight);
	StageCountTexture[8].Init("Assets/UI/Level9.DDS", ScreenWide, ScreenHeight);
	StageCountTexture[9].Init("Assets/UI/Level10.DDS", ScreenWide, ScreenHeight);

	TimerFrameTexture.Init("Assets/UI/Timer.DDS", ScreenWide, ScreenHeight);
}
void UI::InitPosition()
{
	AbuttonTexture.SetPosition(AbuttonPosition);
	BbuttonTexture.SetPosition(BbuttonPosition);

	ControllerNonTexture.SetPosition(ControllerPosition);
	ControllerUpTexture.SetPosition(ControllerPosition);
	ControllerDownTexture.SetPosition(ControllerPosition);
	ControllerLeftTexture.SetPosition(ControllerPosition);
	ControllerRightTexture.SetPosition(ControllerPosition);

	IronBallCountTexture[0].SetPosition(IronBallCountPosition);
	IronBallCountTexture[1].SetPosition(IronBallCountPosition);
	IronBallCountTexture[2].SetPosition(IronBallCountPosition);
	IronBallCountTexture[3].SetPosition(IronBallCountPosition);
	IronBallCountTexture[4].SetPosition(IronBallCountPosition);
	IronBallCountTexture[5].SetPosition(IronBallCountPosition);
}
void UI::InitUpdate()
{
	CanvasTexture.Update();

	AbuttonTexture.Update();
	BbuttonTexture.Update();

	ControllerNonTexture.Update();
	ControllerUpTexture.Update();
	ControllerDownTexture.Update();
	ControllerLeftTexture.Update();
	ControllerRightTexture.Update();

	IronBallCountTexture[0].Update();
	IronBallCountTexture[1].Update();
	IronBallCountTexture[2].Update();
	IronBallCountTexture[3].Update();
	IronBallCountTexture[4].Update();
	IronBallCountTexture[5].Update();

	StageCountTexture[1].Update();
	StageCountTexture[2].Update();
	StageCountTexture[3].Update();
	StageCountTexture[4].Update();
	StageCountTexture[5].Update();
	StageCountTexture[6].Update();
	StageCountTexture[7].Update();
	StageCountTexture[8].Update();
	StageCountTexture[9].Update();
	StageCountTexture[10].Update();

	TimerFrameTexture.Update();
}
void UI::Time()
{
	Timer++;
	TimerOver = TimerLimit - Timer / 60;
	if (TimerOver <= 0){ game->SetGameOver(true); }

	swprintf_s(Clock, 256, L"%d", TimerOver);
	TimerFont.SetText(Clock);
	TimerFont.SetPosition(TimerPosition);
	TimerFont.SetScale(1.0f);
}
void UI::Button()
{
	if (player->GetIronBallCount() < ironball->GetIronBallMax() && player->GetIronBallCount() >= ironball->GetIronBallMin()) 
	{ 
		AbuttonTexture.SetMulColor(AbuttonCollar_TRUE); 
	}

	if (player->GetIronBallCount() >= ironball->GetIronBallMax()) 
	{ 
		AbuttonTexture.SetMulColor(AbuttonCollar_FALSE); 
	}

	if (player->GetIronBallCount() <= ironball->GetIronBallMax() && player->GetIronBallCount() >= ironball->GetIronBallMin()) 
	{
		BbuttonTexture.SetMulColor(BbuttonCollar_TRUE); 
	}

	if (player->GetIronBallCount() <= ironball->GetIronBallMin())
	{
		BbuttonTexture.SetMulColor(BbuttonCollar_FALSE); 
	}
}
void UI::Update()
{
	Time();
	Button();

	AbuttonTexture.Update();
	BbuttonTexture.Update();

	IronBallCountTexture[player->ironBall].Update();

	if (player->MoveSpeed.x < NON){ControllerUpTexture.Update();}
	else {
	if (player->MoveSpeed.x > NON){ControllerDownTexture.Update();}
	else {
	if (player->MoveSpeed.z > NON){ControllerRightTexture.Update();}
	else {
	if (player->MoveSpeed.z < NON){ControllerLeftTexture.Update();}
	else {ControllerNonTexture.Update();}
	}
	}
	}
}
void UI::Render(RenderContext& rc)
{
	CanvasTexture.Draw(rc);

	AbuttonTexture.Draw(rc);
	BbuttonTexture.Draw(rc);

	IronBallCountTexture[player->GetIronBallCount()].Draw(rc);
	StageCountTexture[game->GetLevel()].Draw(rc);

	if (player->MoveSpeed.x < NON) {ControllerUpTexture.Draw(rc);}
	else {
	if (player->MoveSpeed.x > NON) {ControllerDownTexture.Draw(rc);}
	else {
	if (player->MoveSpeed.z > NON) {ControllerRightTexture.Draw(rc);}
	else {
	if (player->MoveSpeed.z < NON) {ControllerLeftTexture.Draw(rc);}
	else {ControllerNonTexture.Draw(rc);}
	}
	}
	}

	TimerFrameTexture.Draw(rc);
	TimerFont.Draw(rc);
}