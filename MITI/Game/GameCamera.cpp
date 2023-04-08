#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"

GameCamera::GameCamera()
{
	player = FindGO<Player>("player");

	//’Ž‹“_
	Target_P = player->player_P;
	g_camera3D->SetTarget(Target_P);

	//Ž‹“_
	Camera_P = Target_P;
	/*Camera_P.x += 800.0f;
	Camera_P.y += 200.0f;*/
	Camera_P.x += 10.0f;
	Camera_P.y += 1800.0f;
	g_camera3D->SetPosition(Camera_P);
}

GameCamera::~GameCamera()
{
	
}

void GameCamera::Update()
{
	/*if (g_pad[0]->IsPress(enButtonUp))
	{
		Camera_P.x -= 10.0f;
	}
	
	if (g_pad[0]->IsPress(enButtonDown))
	{
		Camera_P.x += 10.0f;
	}*/
	g_camera3D->SetPosition(Camera_P);
}