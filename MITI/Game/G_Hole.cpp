#include "stdafx.h"
#include "G_Hole.h"

G_Hole::G_Hole()
{
	InitModel();
}

void G_Hole::InitModel()
{
	M_HoleModel.Init("Assets/modelData/hole.tkm", M_HoleLight);
}
void G_Hole::Update()
{
	M_HoleModel.SetPosition(M_HolePosition);
	M_HoleModel.Update();
}
void G_Hole::Render(RenderContext& rc)
{
	M_HoleModel.Draw(rc);
}