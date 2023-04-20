#include "stdafx.h"
#include "Stage.h"

Stage::Stage()
{
	//コメントアウトする。
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
<<<<<<< HEAD
	AllLight Light;
	m_modelRender.Init("Assets/modelData/test9.tkm",Light);
=======

	m_modelRender.Init("Assets/modelData/stage.tkm",stageLight);
>>>>>>> 83cd96e40d24a972325bca99c8dc0ccef7eb3aec
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