#pragma once
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

	void InitTexture();
	void InitSound();

	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender GameclearTexture;
	SpriteRender AbuttonTexture;

	SoundSource* BGM = nullptr;
	Fade* fade = nullptr;
	Story* story = nullptr;
	Title* title = nullptr;

	bool BgmSet = true;
	bool ClassDelete = false;
	bool PressAbutton = false;
};

