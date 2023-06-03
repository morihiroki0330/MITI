#pragma once
#include "sound/SoundSource.h"
class Fade;
class Story;
class Game;
class Title;
class GameClear:public IGameObject
{
public:
	GameClear();
	~GameClear();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender GAMECLEAR;
	SpriteRender PRESSA;

	SoundSource* BGM;
	Fade* fade;
	Story* story;
	Title* title;
	bool BgmSet = true;
	bool Delete = false;
};

