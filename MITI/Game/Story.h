#pragma once
#include "NumberStorage.h"
class Game;
class Fade;
class Title;
enum Chapter
{
	Chapter0,
	Chapter1,
	Chapter2,
	Chapter3,
	Chapter4,
	Chapter5,
	Chapter6,
	Chapter7,
	Chapter8,
	Chapter9,
	Chapter10
};
class Story : public IGameObject
{
public:
	Story();
	~Story();
	bool Start();

	void InitTexture();

	void TriangleMove();
	
	void TextSpeed();

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
		Word->SetPosition(Vector3(-852.0f, 450.0f, 0.0f));
		Word->SetScale(1.5f);
	}
	void StorySwitch();
	void PlaySe();

	void TextOkuri();
	void TextUpdate();

	void BackGroundFadeOut();

	void TextPostProcessing();
	void EndPostProcessing();
private:

	SpriteRender TriangleTexture;
	SpriteRender BackgroundTexture;
	SpriteRender BlackOutTexture;
	SpriteRender WhiteOutTexture;
	
	float BackgroundAlpha=1.0f;
	float TriangleY = 0;
	float TextIntervals = 0.05f;
	float TextSpeedMagnification = 1.0f;

	int BackGroundNumber = 0;
	int TriangleUpAndDown = 1;
	int TextNumber = 0;
	int StoryNumber = 0;
	
	bool EndText = false;

	FontRender* Word = nullptr;
	SoundSource* BGM = nullptr;
	Fade* fade = nullptr;
	Title* title = nullptr;
	Game* game = nullptr;

	TextureHeight S_TextureHeight;
	TextureWide S_TextureWide;
	Color S_Color;
	FadeInformation S_FadeInformation;
	GridPosition S_GridPosition;
	SoundSetting S_SoundSetting;
	PlayerInformation S_PlayerInformation;
	BlockInformation S_BlockInformation;
	WorldInformation S_WorldInformation;
	IronBallInformation S_IronBallInformation;
};
