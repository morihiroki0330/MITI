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

	//�{�^��
	SpriteRender A[2];
	SpriteRender B[2];

	//�\���L�[
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

	//�S��
	SpriteRender Iron[6];

	Player* player;
	Game* game;
};

