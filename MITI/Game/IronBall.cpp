#include "stdafx.h"
#include "IronBall.h"

IronBall::IronBall()
{

}

IronBall::~IronBall()
{

}

void IronBall::Update()
{

}

void IronBall::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}