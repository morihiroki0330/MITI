#include "stdafx.h"
#include "G_Wall.h"
#include "G_WeightBoard.h"

G_Wall::G_Wall()
{
	m_modelRender.Init("Assets/modelData/miniWall.tkm", wallLight);

	//position = { 95,0,510 };

	//m_modelRender.SetPosition(position);
	m_modelRender.Update();
	m_physicsStaticObjectpos.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
}

G_Wall::~G_Wall()
{

}

void G_Wall::Update()
{
	if (g_weightBoard == NULL)
	{
		g_weightBoard = FindGO<G_WeightBoard>("g_WeightBoard");
	}
	else
	{
		if (g_weightBoard->putFlag == true)
		{
			position = { 95,-1000,510 };
		}
		else
		{
			position = { 95,0,510 };
		}
	}

	m_modelRender.SetPosition(position);
	m_physicsStaticObjectpos.SetPosition(position);
	m_modelRender.Update();
}

void G_Wall::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}