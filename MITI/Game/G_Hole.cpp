#include "stdafx.h"
#include "G_Hole.h"
G_Hole::G_Hole()
{
	InitModel();
	InitPhysicsStaticObject();
}

void G_Hole::InitModel()
{
	HoleModel.Init("Assets/modelData/hole.tkm", HoleLight);
}
void G_Hole::InitPhysicsStaticObject()
{
	HolePhysicsStaticObject.CreateFromModel(HoleModel.GetModel(), HoleModel.GetModel().GetWorldMatrix());
}

void G_Hole::Update()
{
	HoleModel.SetPosition(HolePosition);
	HolePhysicsStaticObject.SetPosition(HolePosition);
	HoleModel.Update();
}
void G_Hole::Render(RenderContext& rc)
{
	HoleModel.Draw(rc);
}