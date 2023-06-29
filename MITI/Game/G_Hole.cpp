#include "stdafx.h"
#include "G_Hole.h"
bool G_Hole::Start()
{
	Hole.Init("Assets/modelData/hole.tkm", Light);
	Hole_PSO.CreateFromModel(Hole.GetModel(), Hole.GetModel().GetWorldMatrix());
	Hole_PSO.SetPosition(Hole_Position);
	Hole.SetPosition(Hole_Position);
	return true;
}

void G_Hole::Update()
{
	Hole.Update();
}

void G_Hole::Render(RenderContext& rc)
{
	Hole.Draw(rc);
}