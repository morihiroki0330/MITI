#pragma once
class Story;
class Fade;
class Title : public IGameObject
{
public:
	Title();
	~Title();
	bool Start();

	void InitTexture();
	void InitSound();

	void Update();
	void ScreenChange();
	void Render(RenderContext& rc);
private:
	SpriteRender TitleTexture;
	SpriteRender AbuttonTexture;

	SoundSource* BGM = nullptr;
	Story* story = nullptr;
	Fade* fade = nullptr;

	bool BgmSet = true;
	bool ClassDelete = false;
	bool PressAbutton = false;
};