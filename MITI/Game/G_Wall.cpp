#include "stdafx.h"
#include "G_Wall.h"

G_Wall::G_Wall()
{
	Wall.Init("Assets/modelData/miniWall.tkm", Light);
	m_physicsStaticObjectpos.CreateFromModel(Wall.GetModel(), Wall.GetModel().GetWorldMatrix());
}

G_Wall::~G_Wall()
{

}

void G_Wall::Update()
{
	Wall.SetPosition(Wall_P);
	m_physicsStaticObjectpos.SetPosition(Wall_P);
	Wall.Update();
}

void G_Wall::Render(RenderContext& rc)
{
	Wall.Draw(rc);
}