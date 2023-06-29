#include "stdafx.h"
#include "G_Wall.h"
bool G_Wall::Start()
{
	Wall.Init("Assets/modelData/hekiga.tkm", Light);
	Wall_PSO.CreateFromModel(Wall.GetModel(), Wall.GetModel().GetWorldMatrix());
	return true;
}

void G_Wall::Update()
{
	Wall.SetPosition(Wall_Position);
	Wall_PSO.SetPosition(Wall_Position);
	Wall.Update();
}

void G_Wall::Render(RenderContext& rc)
{
	Wall.Draw(rc);
}