#pragma once
class Game;
class Fade;
class GameOver :public IGameObject
{
public:
	GameOver();
	~GameOver();
	bool Start();

	void InitTexture();
	void InitSound();

	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender GameoverTexture;
	SpriteRender AbuttonTexture;

	Game* game = nullptr;
	Fade* fade = nullptr;
	SoundSource* BGM = nullptr;

	bool BgmSet = true;
	bool ClassDelete = false;
	bool PressAbutton = false;
};
