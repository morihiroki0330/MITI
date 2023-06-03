#include "stdafx.h"
#include "UI.h"
#include "Player.h"
#include "Game.h"

UI::UI()
{
	Back.Init("Assets/UI/UI_canvas.DDS", 1920.0f, 1080.0f);
	//Aボタン
	{
		//不可能
		A[0].Init("Assets/UI/A-Non.DDS", 150.0f, 150.0f);
		A[0].SetPosition({ 680.0f,-400.0f,0.0f });
		A[0].Update();

		//可能
		A[1].Init("Assets/UI/A.DDS", 150.0f, 150.0f);
		A[1].SetPosition({ 680.0f,-400.0f,0.0f });
		A[1].Update();
	}

	//Bボタン
	{
		B[0].Init("Assets/UI/B-Non.DDS", 150.0f, 150.0f);
		B[0].SetPosition({ 830.0f,-400.0f,0.0f });
		B[0].Update();

		B[1].Init("Assets/UI/B.DDS", 150.0f, 150.0f);
		B[1].SetPosition({ 830.0f,-400.0f,0.0f });
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
		Iron[0].Init("Assets/UI/Iron0.DDS", 128.0f, 512.0f);
		Iron[0].SetPosition({ 750.0f,-50.0f,0.0f });
		Iron[0].Update();

		Iron[1].Init("Assets/UI/Iron1.DDS", 128.0f, 512.0f);
		Iron[1].SetPosition({ 750.0f,-50.0f,0.0f });
		Iron[1].Update();

		Iron[2].Init("Assets/UI/Iron2.DDS", 128.0f, 512.0f);
		Iron[2].SetPosition({ 750.0f,-50.0f,0.0f });
		Iron[2].Update();

		Iron[3].Init("Assets/UI/Iron3.DDS", 128.0f, 512.0f);
		Iron[3].SetPosition({ 750.0f,-50.0f,0.0f });
		Iron[3].Update();

		Iron[4].Init("Assets/UI/Iron4.DDS", 128.0f, 512.0f);
		Iron[4].SetPosition({ 750.0f,-50.0f,0.0f });
		Iron[4].Update();

		Iron[5].Init("Assets/UI/Iron5.DDS", 128.0f, 512.0f);
		Iron[5].SetPosition({ 750.0f,-50.0f,0.0f });
		Iron[5].Update();

	}

	//ステージ
	{
		Stage[1].Init("Assets/UI/Level1.DDS", 1920.0f, 1080.0f);
		Stage[1].SetPosition({ 0.0f,0.0f,0.0f });
		Stage[1].Update();
		
		Stage[2].Init("Assets/UI/Level2.DDS", 1920.0f, 1080.0f);
		Stage[2].SetPosition({ 0.0f,0.0f,0.0f });
		Stage[2].Update();
		
		Stage[3].Init("Assets/UI/Level3.DDS", 1920.0f, 1080.0f);
		Stage[3].SetPosition({ 0.0f,0.0f,0.0f });
		Stage[3].Update();
		
		Stage[4].Init("Assets/UI/Level4.DDS", 1920.0f, 1080.0f);
		Stage[4].SetPosition({ 0.0f,0.0f,0.0f });
		Stage[4].Update();
		
		Stage[5].Init("Assets/UI/Level5.DDS", 1920.0f, 1080.0f);
		Stage[5].SetPosition({ 0.0f,0.0f,0.0f });
		Stage[5].Update();
		
		Stage[6].Init("Assets/UI/Level6.DDS", 1920.0f, 1080.0f);
		Stage[6].SetPosition({ 0.0f,0.0f,0.0f });
		Stage[6].Update();

		Stage[7].Init("Assets/UI/Level7.DDS", 1920.0f, 1080.0f);
		Stage[7].SetPosition({ 0.0f,0.0f,0.0f });
		Stage[7].Update();

		Stage[8].Init("Assets/UI/Level8.DDS", 1920.0f, 1080.0f);
		Stage[8].SetPosition({ 0.0f,0.0f,0.0f });
		Stage[8].Update();

		Stage[9].Init("Assets/UI/Level9.DDS", 1920.0f, 1080.0f);
		Stage[9].SetPosition({ 0.0f,0.0f,0.0f });
		Stage[9].Update();

		Stage[10].Init("Assets/UI/Level10.DDS", 1920.0f, 1080.0f);
		Stage[10].SetPosition({ 0.0f,0.0f,0.0f });
		Stage[10].Update();
	}
	STimer.Init("Assets/UI/Timer.DDS", 1920.0f, 1080.0f);
	STimer.SetPosition({ 0.0f,0.0f,0.0f });
	STimer.Update();
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
	swprintf_s(clock, 256, L"%d",over);
	Timer.SetText(clock);
	Timer.SetPosition(Vector3(830.0f, 305.0f, 0.0f));
	Timer.SetScale(1.0f);

	wchar_t tips[256];
	swprintf_s(tips, 256, L"Tip:ゴールを目指せ");
	Tips.SetText(tips);
	Tips.SetPosition(Vector3(570.0f, 350.0f, 0.0f));
	Tips.SetScale({ 0.8f });
}

void UI::Render(RenderContext& rc)
{
	Back.Draw(rc);

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

	STimer.Draw(rc);
	Timer.Draw(rc);
	//Tips.Draw(rc);
	Stage[game->Level + 1].Draw(rc);
}