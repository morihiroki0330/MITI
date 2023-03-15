#include "stdafx.h"
#include "G_BreakFloar.h"

G_BreakFloar::G_BreakFloar()
{
	//コメントアウトする。
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	m_modelRender.Init("Assets/modelData/breakfloar/breakfloar2.tkm");
	m_modelRender.Update();
	m_physicsStaticObjectpos.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
}

G_BreakFloar::~G_BreakFloar()
{

}

void G_BreakFloar::Update()
{
	m_modelRender.SetPosition(position);
	m_physicsStaticObjectpos.SetPosition(position);
}

void G_BreakFloar::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}