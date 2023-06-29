#pragma once
#include "Number_Storage.h"
class Game;
class Fade;
class Title;
//タイトル。
class Story : public IGameObject
{
public:
	Story();
	~Story();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void BackChange();
	void TextReset()
	{
		delete Word;
		Word = new FontRender;
	}
	void TextCreate()
	{
		Word->SetPosition(Vector3(-852.0f, 450.0f, NON));
		Word->SetScale(1.5f);
	}
	void StorySwitch();
	void playSE();
	void TextUpdate();
private:

	SpriteRender Triangle;
	SpriteRender Background;
	SpriteRender Black;
	SpriteRender White;
	
	FontRender* Word = nullptr;
	
	float alpha=1.0f;
	float Y;
	float HIGH = 0.05f;
	float mul = 1.0f;

	int ud = 1;
	int out = 0;
	int storyNum = 0;
	int BackNumber = 0;
	
	bool Endtext = false;
	bool ismul = false;
	bool Fukusen=false;

	char textout;
	char No;

	SoundSource* BGM = nullptr;
	Fade* fade = nullptr;
	Title* title = nullptr;
	Game* game = nullptr;

	
	

	//背景の初期番号
	

	

	
	
};
