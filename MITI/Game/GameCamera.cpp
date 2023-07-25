#include "stdafx.h"
#include "GameCamera.h"
bool GameCamera::Start()
{
	M_CameraPosition = M_TargetPosition;
	M_CameraPosition.x += 1.0f;
	M_CameraPosition.y += 1750.0f;
	g_camera3D->SetTarget(M_TargetPosition);
	g_camera3D->SetPosition(M_CameraPosition);
	return true;
}
void GameCamera::Update()
{
	g_camera3D->SetPosition(M_CameraPosition);
}