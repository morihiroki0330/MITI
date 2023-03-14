#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	modelRender.Init("Assets/modelData/unityChan.tkm");

	player_P.x = 0.0f;
	player_P.y = 0.0f;
	player_P.z = 0.0f;

	modelRender.SetPosition(player_P);

	//キャラクターコントローラーの初期化
	characterController.Init(25.0f, 75.0f, player_P);
}

Player::~Player()
{
	//

}

void Player::Update()
{
	//

	//スティックの入力量の取得
	StickL.x = g_pad[0]->GetLStickYF();
	StickL.y = g_pad[0]->GetLStickXF();

	//移動処理
	Move();
	//回転処理
	Rotation();
	//鉄球処理
	Ball();
	//アニメーション処理
	Animation();
	//ステータス表示処理
	Status();

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
	moveSpeed.x += StickL.x * -(0.8f * (6 - ironBall));
	moveSpeed.z += StickL.y * (0.8f * (6 - ironBall));

	/*if (characterController.IsOnGround())
	{
		moveSpeed.y = 0.0f;
	}
	else
	{
		moveSpeed.y = -2.5f;
	}*/

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

void Player::Ball()
{
	//鉄球クラスで鉄球の所持数を変えるためにフラグ変数を変更する
	if (g_pad[0]->IsTrigger(enButtonA) && ironBall < 5)
	{
		get_Iron = true;
	}

	if (g_pad[0]->IsTrigger(enButtonB) && ironBall > 0)
	{
		put_Iron = true;
	}
}

void Player::Animation()
{
	//プレイヤーステートの変更
	if (player_P.y < 0)
	{
		//落下
		playerState = 2;
	}
	else if (StickL.x == 0 && StickL.y == 0)
	{
		//立ち
		playerState = 0;
	}
	else
	{
		//歩き
		playerState = 1;
	}

	switch (playerState)
	{
	//立ちモーション
	case 0:
		break;
	//歩きモーション
	case 1:
		break;
	//落下モーション
	case 2:
		break;
	//
	default:
		break;
	}
}

void Player::Status()
{
	//持っている鉄球の数の表示
	wchar_t iron[256];
	swprintf_s(iron, 256, L"所持鉄球:%d", int(ironBall));
	//表示するテキストを設定。
	fontRender.SetText(iron);
	//フォントの位置を設定。
	fontRender.SetPosition(Vector3(-952.0f, 450.0f, 0.0f));
	//フォントの大きさを設定。
	fontRender.SetScale(1.0f);

	//座標を確認するためのプログラム

	////プレイヤーの座標の表示
	//wchar_t playerX[256];
	//swprintf_s(playerX, 256, L"x座標:%d", int(player_P.x));
	////表示するテキストを設定。
	//fontRender.SetText(playerX);
	////フォントの位置を設定。
	//fontRender.SetPosition(Vector3(-852.0f, 450.0f, 0.0f));
	////フォントの大きさを設定。
	//fontRender.SetScale(1.0f);

	//wchar_t playerZ[256];
	//swprintf_s(playerZ, 256, L"z座標:%d", int(player_P.z));
	////表示するテキストを設定。
	//fontRender.SetText(playerZ);
	////フォントの位置を設定。
	//fontRender.SetPosition(Vector3(-852.0f, 450.0f, 0.0f));
	////フォントの大きさを設定。
	//fontRender.SetScale(1.0f);
}

void Player::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
	fontRender.Draw(rc);
}