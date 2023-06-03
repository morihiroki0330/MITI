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
	
	SpriteRender Back;

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
	SpriteRender STimer;
	FontRender Tips;
	SpriteRender Stage[11];

	int timer;
	int over;
	int timelimit = 100;

	//鉄球
	SpriteRender Iron[6];

	Player* player;
	Game* game;
};

