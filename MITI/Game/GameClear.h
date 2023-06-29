#pragma once
#include "sound/SoundSource.h"
class Fade;
class Story;
class Game;
class Title;
class GameClear:public IGameObject
{
public:
	~GameClear();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender Gameclear_S;
	SpriteRender Abutton_S;

	SoundSource* BGM = nullptr;;
	Fade* fade = nullptr;;
	Story* story = nullptr;;
	Title* title = nullptr;;

	bool BgmSet = true;
	bool Delete = false;
	bool Press_Abutton = false;
};

