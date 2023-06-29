#include "stdafx.h"
#include "G_Kaidan.h"
#include "Box.h"
#include "Number_Storage.h"
G_Kaidan::G_Kaidan()
{
	InitModel();
}
bool G_Kaidan::Start()
{
	box = FindGO<Box>("box");
	return true;
}

void G_Kaidan::InitModel()
{
	KaidanModel.Init("Assets/modelData/kaidan3.tkm", KaidanLight);
	KaidanModel.SetPosition({ Grid_ExemptPosition_X, Grid_ExemptPosition_Y, Grid_ExemptPosition_Z });
	KaidanModel.SetRotation(KaidanRotation);
	KaidanModel.SetScale(KaidanScale);
	KaidanModel.Update();
}

void G_Kaidan::Map_SetPosition(Vector3 Position)
{
	KaidanPosition.x = Position.x;
	KaidanPosition.y = 20.0f;
	KaidanPosition.z = Position.z;
}

void G_Kaidan::Update()
{
	KaidanModel.SetRotation(KaidanRotation);
	KaidanModel.SetPosition(KaidanPosition);
	box->KaidanBox_SetPosition(KaidanPosition);
	KaidanModel.Update();
}
void G_Kaidan::Render(RenderContext& rc)
{
	KaidanModel.Draw(rc);
}