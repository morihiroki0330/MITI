#include "stdafx.h"
#include "G_Wall.h"
G_Wall::G_Wall()
{
	InitModel();
}
void G_Wall::InitModel()
{
	M_WallModel.Init("Assets/modelData/hekiga.tkm", M_WallLight);
	M_WallPhysicsStaticObject.CreateFromModel(M_WallModel.GetModel(), M_WallModel.GetModel().GetWorldMatrix());
}

void G_Wall::Update()
{
	M_WallModel.SetPosition(M_WallPosition);
	M_WallPhysicsStaticObject.SetPosition(M_WallPosition);
	M_WallModel.Update();
}
void G_Wall::Render(RenderContext& rc)
{
	M_WallModel.Draw(rc);
}