#pragma once
#include "sound/SoundSource.h"
class Story;
class Bgm;
class Fade;
class Game;
//�^�C�g���B
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
	//�_�ŃJ�E���g
	int flashCount = 0;

	//A�{�^���������ꂽ��true
	bool Press_A = false;

	int frame=0;

	int wait = 0;
};
