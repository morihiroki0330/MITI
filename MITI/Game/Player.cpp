#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	modelRender.Init("Assets/modelData/unityChan.tkm");

	player_P.x = 0.0f;
	player_P.y = 0.0f;
	player_P.z = 0.0f;

	modelRender.SetPosition(player_P);
}

Player::~Player()
{

}

void Player::Update()
{
	player_P.z += 1.0f;

	modelRender.SetPosition(player_P);
	modelRender.Update();
}

void Player::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}