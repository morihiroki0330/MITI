#pragma once
#include "sound/SoundSource.h"
class Story;
class Bgm;
class Fade;
class Game;
//タイトル。
class Title : public IGameObject
{
public:
	Title();
	~Title();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void Fade1();
	void Flash();
	Story* story;
	SpriteRender Title_s;
	SpriteRender Title_f;
	SpriteRender Title_b;
	SoundSource* BGM;
	Fade* fade;
	Game* game;
	bool BgmSet = true;
	bool Delete = false;
	float alpha=1.0f;
	float alpha_s=1.0f;
	int flashing = 0;
	//点滅カウント
	int flashCount = 0;

	//Aボタンが押されたらtrue
	bool Press_A = false;

	int frame=0;

	int wait = 0;
};
