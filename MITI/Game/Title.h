#pragma once
class Story;
class Fade;
class Game;
class Title : public IGameObject
{
public:
	~Title();
	bool Start();
	void Update();
	void ScreenChange();
	void Render(RenderContext& rc);
private:
	SpriteRender Title_S;
	SpriteRender Abutton_S;

	SoundSource* BGM = nullptr;
	Story* story = nullptr;
	Fade* fade = nullptr;
	Game* game = nullptr;

	bool BgmSet = true;
	bool ClassDelete = false;
	bool Press_Abutton = false;
};