#include "stdafx.h"
#include "IronBall.h"
#include "Player.h"

IronBall::IronBall()
{
	modelRender.Init("Assets/modelData/tekyu/tekyu8.tkm");

	ball_P[0] = { 0.0f,0.0f,0.0f };
}

IronBall::~IronBall()
{
	
}

void IronBall::Update()
{
	//if (player == NULL)
	//{
	//	//プレイヤークラスを探してくる
	//	player = FindGO<Player>("player");
	//}
	//else
	//{
	//	if ()
	//	{
	//		for (int i = 0; i < 5; i++)
	//		{

	//		}
	//	}
	//}

	modelRender.SetPosition(ball_P[0]);
	modelRender.Update();
}

void IronBall::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}