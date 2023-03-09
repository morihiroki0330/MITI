#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	modelRender.Init("Assets/modelData/unityChan.tkm");

	player_P.x = 0.0f;
	player_P.y = 0.0f;
	player_P.z = 0.0f;

	modelRender.SetPosition(player_P);

	characterController.Init(25.0f, 75.0f, player_P);
}

Player::~Player()
{

}

void Player::Update()
{
	//スティックの入力量の取得
	StickL.x = g_pad[0]->GetLStickXF();
	StickL.y = g_pad[0]->GetLStickYF();

	//移動処理
	Move();

	//回転処理
	Rotation();

	modelRender.SetPosition(player_P);
	modelRender.SetRotation(rotation);
	modelRender.Update();
}

void Player::Move()
{
	//移動速度の初期化
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	//プレイヤーの移動
	moveSpeed.x += StickL.x * 5.0f;
	moveSpeed.z += StickL.y * 5.0f;

	//キャラクターコントローラーを使って座標の移動
	player_P = characterController.Execute(moveSpeed, 1.0f);
}

void Player::Rotation()
{
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
		//キャラクターの方向変更
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
	}

}

void Player::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}