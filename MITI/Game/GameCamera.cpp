#include "stdafx.h"
#include "GameCamera.h"
bool GameCamera::Start()
{
	Camera_Position = Target_Position;
	Camera_Position.x += 1.0f;
	Camera_Position.y += 1750.0f;
	g_camera3D->SetTarget(Target_Position);
	g_camera3D->SetPosition(Camera_Position);
	return true;
}
void GameCamera::Update()
{
	g_camera3D->SetPosition(Camera_Position);
}