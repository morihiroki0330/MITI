#pragma once
class Player;
class UI : public IGameObject
{
public:
	UI();
	~UI();
	void Update();
	void Render(RenderContext& rc);

	//ボタン
	SpriteRender A[2];
	SpriteRender B[2];

	//十字キー
	SpriteRender Up;
	SpriteRender Down;
	SpriteRender Right;
	SpriteRender Left;
	SpriteRender Non;

	//鉄球
	SpriteRender Iron[2];

	Player* player;
};

