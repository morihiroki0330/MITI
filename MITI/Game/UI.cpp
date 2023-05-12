#include "stdafx.h"
#include "UI.h"
#include "Player.h"
#include "Game.h"

UI::UI()
{
	Back.Init("Assets/UI/Back.DDS", 1920.0f, 1080.0f);
	//Aボタン
	{
		//不可能
		A[0].Init("Assets/UI/A-Non.DDS", 150.0f, 150.0f);
		A[0].SetPosition({ 550.0f,-400.0f,0.0f });
		A[0].Update();

		//可能
		A[1].Init("Assets/UI/A.DDS", 150.0f, 150.0f);
		A[1].SetPosition({ 550.0f,-400.0f,0.0f });
		A[1].Update();
	}

	//Bボタン
	{
		B[0].Init("Assets/UI/B-Non.DDS", 150.0f, 150.0f);
		B[0].SetPosition({ 680.0f,-400.0f,0.0f });
		B[0].Update();

		B[1].Init("Assets/UI/B.DDS", 150.0f, 150.0f);
		B[1].SetPosition({ 680.0f,-400.0f,0.0f });
		B[1].Update();
	}

	//コントローラー
	{
		//不可能
		Non.Init("Assets/UI/Controller-Non.DDS", 256.0f, 256.0f);
		Non.SetPosition({ -750.0f,-400.0f,0.0f });
		Non.Update();

		//上
		Up.Init("Assets/UI/Controller-Up.DDS", 256.0f, 256.0f);
		Up.SetPosition({ -750.0f,-400.0f,0.0f });
		Up.Update();

		//下
		Down.Init("Assets/UI/Controller-Down.DDS", 256.0f, 256.0f);
		Down.SetPosition({ -750.0f,-400.0f,0.0f });
		Down.Update();

		//左
		Left.Init("Assets/UI/Controller-Left.DDS", 256.0f, 256.0f);
		Left.SetPosition({ -750.0f,-400.0f,0.0f });
		Left.Update();

		//右
		Right.Init("Assets/UI/Controller-Right.DDS", 256.0f, 256.0f);
		Right.SetPosition({ -750.0f,-400.0f,0.0f });
		Right.Update();
	}

	//鉄球の所持数
	{
		Iron[0].Init("Assets/UI/Iron-Non.DDS", 128.0f, 512.0f);
		Iron[0].SetPosition({ 600.0f,-50.0f,0.0f });
		Iron[0].Update();

		Iron[1].Init("Assets/UI/Iron-One.DDS", 128.0f, 512.0f);
		Iron[1].SetPosition({ 600.0f,-50.0f,0.0f });
		Iron[1].Update();

		Iron[2].Init("Assets/UI/Iron-Two.DDS", 128.0f, 512.0f);
		Iron[2].SetPosition({ 600.0f,-50.0f,0.0f });
		Iron[2].Update();

		Iron[3].Init("Assets/UI/Iron-Three.DDS", 128.0f, 512.0f);
		Iron[3].SetPosition({ 600.0f,-50.0f,0.0f });
		Iron[3].Update();

		Iron[4].Init("Assets/UI/Iron-Four.DDS", 128.0f, 512.0f);
		Iron[4].SetPosition({ 600.0f,-50.0f,0.0f });
		Iron[4].Update();

		Iron[5].Init("Assets/UI/Iron-Five.DDS", 128.0f, 512.0f);
		Iron[5].SetPosition({ 600.0f,-50.0f,0.0f });
		Iron[5].Update();

	}

}

UI::~UI()
{

}

void UI::Update()
{
	if (player == NULL)
	{
		player = FindGO<Player>("player");
	}

	if (game == NULL)
	{
		game = FindGO<Game>("game");
	}

	if (player->get_Ui == true)
	{
		A[1].Update();
	}
	else {
	if (player->get_Ui == false)
	{
		A[0].Update();
	}
	}

	if (player->put_Ui == true)
	{
		B[1].Update();
	}else {
	if (player->put_Ui == false)
	{
		B[0].Update();
	}
	}

	if (player->MoveSpeed.x < 0.0f)
	{
		Up.Update();
	}else {
	if (player->MoveSpeed.x > 0.0f)
	{
		Down.Update();
	}else {
	if (player->MoveSpeed.z > 0.0f)
	{
		Right.Update();
	}else {
	if (player->MoveSpeed.z < 0.0f)
	{
		Left.Update();
	}else {
		Non.Update();
	}
	}
	}
	}

	Iron[player->ironBall].Update();

	timer++;
	
	over = timelimit - timer / 60;

	if (over <= 0)
	{
		game->GameOverFlag = true;
	}

	//時間制限処理
	wchar_t clock[256];
	swprintf_s(clock, 256, L"残り時間:%d",over);
	Timer.SetText(clock);
	Timer.SetPosition(Vector3(600.0f, 400.0f, 0.0f));
	Timer.SetScale(1.0f);

	wchar_t tips[256];
	swprintf_s(tips, 256, L"Tip:ゴールを目指せ");
	Tips.SetText(tips);
	Tips.SetPosition(Vector3(570.0f, 350.0f, 0.0f));
	Tips.SetScale({ 0.8f });

	wchar_t stage[256];
	swprintf_s(stage, 256, L"%d階層目", game->Level+1);
	Stage.SetText(stage);
	Stage.SetPosition(Vector3(650.0f, 450.0f, 0.0f));
	Stage.SetScale({ 1.0f });
}

void UI::Render(RenderContext& rc)
{
	//Back.Draw(rc);

	if (player->get_Ui == true)
	{
		A[1].Draw(rc);
	}else {
	if (player->get_Ui == false)
	{
		A[0].Draw(rc);
	}
	}

	if (player->put_Ui == true)
	{
		B[1].Draw(rc);
	}else {
	if (player->put_Ui == false)
	{
		B[0].Draw(rc);
	}
	}

	Iron[player->ironBall].Draw(rc);

	if (player->MoveSpeed.x < 0.0f)
	{
		Up.Draw(rc);
	}else {
	if (player->MoveSpeed.x > 0.0f)
	{
		Down.Draw(rc);
	}else {
	if (player->MoveSpeed.z > 0.0f)
	{
		Right.Draw(rc);
	}else {
	if (player->MoveSpeed.z < 0.0f)
	{
		Left.Draw(rc);;
	}else {
		Non.Draw(rc);
	}
	}
	}
	}

	Timer.Draw(rc);
	//Tips.Draw(rc);
	Stage.Draw(rc);
}