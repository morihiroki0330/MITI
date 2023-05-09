#pragma once
class Player;
class Game;
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

	FontRender Timer;
	FontRender Tips;
	FontRender Stage;

	int timer;
	int over;
	int timelimit = 90;

	//鉄球
	SpriteRender Iron[6];

	Player* player;
	Game* game;
};

