#include "stdafx.h"
#include "Stage.h"

Stage::Stage()
{
	//コメントアウトする。
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	AllLight Light;
	m_modelRender.Init("Assets/modelData/test9.tkm",Light);
	m_modelRender.Update();
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
}

Stage::~Stage()
{

}

void Stage::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}