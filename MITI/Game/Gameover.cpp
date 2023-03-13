#include "stdafx.h"
#include "Gameover.h"
#include "Title.h"

Gameover::Gameover()
{
	//ゲームクリアの画像を読み込む
	GAMEOVER.Init("Assets/Sprite/RoM_gameover.dds", 1920.0f, 1080.0f);

}

Gameover::~Gameover()
{

}

//更新処理
void Gameover::Update()
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
void Gameover::Render(RenderContext& rc)
{
	GAMEOVER.Draw(rc);
}
