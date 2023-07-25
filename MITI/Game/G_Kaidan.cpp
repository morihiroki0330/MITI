#include "stdafx.h"
#include "G_Kaidan.h"
#include "Box.h"
#include "NumberStorage.h"
G_Kaidan::G_Kaidan()
{
	InitModel();
}
bool G_Kaidan::Start()
{
	P_Box = FindGO<Box>("box");
	return true;
}

void G_Kaidan::InitModel()
{
	M_KaidanModel.Init("Assets/modelData/kaidan3.tkm", M_KaidanLight);
	M_KaidanModel.SetPosition({ S_GridPosition.M_GridExemptPositionX, S_GridPosition.M_GridExemptPositionY, S_GridPosition.M_GridExemptPositionZ });
	M_KaidanModel.SetRotation(M_KaidanRotation);
	M_KaidanModel.SetScale(M_KaidanScale);
	M_KaidanModel.Update();
}

void G_Kaidan::Map_SetPosition(Vector3 Position)
{
	M_KaidanPosition.x = Position.x;
	M_KaidanPosition.y = 20.0f;
	M_KaidanPosition.z = Position.z;
}

void G_Kaidan::Update()
{
	M_KaidanModel.SetRotation(M_KaidanRotation);
	M_KaidanModel.SetPosition(M_KaidanPosition);
	P_Box->KaidanBoxSetPosition(M_KaidanPosition);
	M_KaidanModel.Update();
}
void G_Kaidan::Render(RenderContext& rc)
{
	M_KaidanModel.Draw(rc);
}