#include "stdafx.h"
#include "Gameover.h"
#include "Title.h"
#include "Game.h"

Gameover::Gameover()
{
	//ゲームクリアの画像を読み込む
	GAMEOVER.Init("Assets/sprite/RoM_gameover.DDS", 1920.0f, 1080.0f);

}

Gameover::~Gameover()
{

}

//更新処理
void Gameover::Update()
{
	game = FindGO<Game>("game");
	//Aボタンが押されたら
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		game->CreateFlag = true;
		DeleteGO(this);
	}
}

//描画処理
void Gameover::Render(RenderContext& rc)
{
	GAMEOVER.Draw(rc);
}
