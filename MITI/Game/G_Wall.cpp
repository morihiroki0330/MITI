#include "stdafx.h"
#include "G_Wall.h"
G_Wall::G_Wall()
{
	InitModel();
	InitPhysicsStaticObject();
	
}

void G_Wall::InitModel()
{
	WallModel.Init("Assets/modelData/hekiga.tkm", WallLight);
}
void G_Wall::InitPhysicsStaticObject()
{
	WallPhysicsStaticObject.CreateFromModel(WallModel.GetModel(), WallModel.GetModel().GetWorldMatrix());
}

void G_Wall::Update()
{
	WallModel.SetPosition(WallPosition);
	WallPhysicsStaticObject.SetPosition(WallPosition);
	WallModel.Update();
}
void G_Wall::Render(RenderContext& rc)
{
	WallModel.Draw(rc);
}