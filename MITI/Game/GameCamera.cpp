#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"

GameCamera::GameCamera()
{
	player = FindGO<Player>("player");

	Target_P = { 0.0f,0.0f,0.0f };
	g_camera3D->SetTarget(Target_P);

	Camera_P = Target_P;
	Camera_P.x += 1.0f;
	Camera_P.y += 1750.0f;
	g_camera3D->SetPosition(Camera_P);
}

GameCamera::~GameCamera()
{
	
}

void GameCamera::Update()
{
	g_camera3D->SetPosition(Camera_P);
}