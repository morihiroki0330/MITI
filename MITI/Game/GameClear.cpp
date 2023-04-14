#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"

GameClear::GameClear()
{
	//ゲームクリアの画像を読み込む
	GAMEOVER.Init("Assets/sprite/RoM_gameclear.DDS", 1820.0f, 880.0f);

}

GameClear::~GameClear()
{

}

//更新処理
void GameClear::Update()
{

	//Aボタンが押されたら
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//タイトルのオブジェクトを作る
		NewGO<Title>(0, "title");
		//自身を削除する
		DeleteGO(this);
	}
}

//描画処理
void GameClear::Render(RenderContext& rc)
{
	GAMEOVER.Draw(rc);
}