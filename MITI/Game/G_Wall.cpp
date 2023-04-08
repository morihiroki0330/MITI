#include "stdafx.h"
#include "G_Wall.h"
#include "G_WeightBoard.h"

G_Wall::G_Wall()
{

}

G_Wall::~G_Wall()
{

}

void G_Wall::Update()
{
	if (g_weightBoard == NULL)
	{
		g_weightBoard = FindGO<G_WeightBoard>("g_weightBoard");
	}

	if (g_weightBoard->putFlag == true)
	{
		DeleteGO(this);
	}
}

void G_Wall::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}