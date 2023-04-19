#include "stdafx.h"
#include "Stage.h"

Stage::Stage()
{
	//コメントアウトする。
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	m_modelRender.Init("Assets/modelData/stage.tkm",stageLight);
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