#include "stdafx.h"
#include "G_Hole.h"

G_Hole::G_Hole()
{
	
	Hole.Init("Assets/test/hole.tkm", Hole_L);
	m_physicsStaticObjectpos.CreateFromModel(Hole.GetModel(), Hole.GetModel().GetWorldMatrix());
	m_physicsStaticObjectpos.SetPosition({ 0.0f,-120.0f,0.0f });
	Hole.SetPosition({ 0.0f,-120.0f,0.0f });
}

G_Hole::~G_Hole()
{

}

void G_Hole::Update()
{
	Hole.Update();
}

void G_Hole::Render(RenderContext& rc)
{
	Hole.Draw(rc);
}