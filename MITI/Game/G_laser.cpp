#include "stdafx.h"
#include "G_laser.h"

G_laser::G_laser()
{
	m_modelRender.Init("Assets/modelData/lasercolision.tkm", laserLight);
	

	position = { -680,-5,-300 };

	m_modelRender.Update();
	m_physicsStaticObjectpos.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
}

G_laser::~G_laser()
{

}

void G_laser::Update()
{
	

	m_modelRender.SetPosition(position);
	m_physicsStaticObjectpos.SetPosition(position);
	m_modelRender.Update();
}

void G_laser::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}