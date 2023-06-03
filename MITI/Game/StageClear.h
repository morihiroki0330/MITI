#pragma once
class Game;
class Bgm;
class Story;
class Fade;
class StageClear : public IGameObject
{
public:
	StageClear();
	~StageClear();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender STAGECLEAR;  
	SpriteRender PRESSA;  

	Game* game;
	Bgm* bgm;
	Fade* fade;

	SoundSource* BGM;

	bool BgmSet = true;
	bool Delete = false;
};

