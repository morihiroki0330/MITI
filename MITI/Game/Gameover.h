#pragma once
class Game;
//ゲームオーバー
class Gameover :public IGameObject
{
public:
	Gameover();
	~Gameover();
	//更新処理
	void Update();
	//描画処理
	void Render(RenderContext& rc);

	//メンバ変数	
	SpriteRender GAMEOVER;   //スプライトレンダー

	Game* game;
};