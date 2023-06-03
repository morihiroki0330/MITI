#pragma once

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

	//テキスト更新関数。
	void TextUpdate();
	Game* game;
	SpriteRender BACKGROUND;
	SpriteRender BLACK;
	SpriteRender WHITE;
	float alpha=1.0f;
	FontRender* Word = nullptr;
	SpriteRender Triangle;
	char No;
	float Y;
	int ud=1;
	int out=0;
	bool Fukusen=false;
	char textout;
	SoundSource* BGM;
	Fade* fade;
	Title* title;

	//ストーリーの進行度(面攻略ごとに+1)
	int storyNum = 0;

	//背景の初期番号
	int BackNumber = 0;

	float HIGH = 0.05f;	//高速テキスト流し

	//終わった？
	bool Endtext = false;

	bool ismul = false;
	float mul = 1.0f;	//倍速変数

	//背景変更関数
	void BackChange();

	//テキストリセット関数
	void TextReset()
	{
		delete Word;
		Word = new FontRender;
	}

	//テキスト配置関数
	void TextCreate()
	{
		Word->SetPosition(Vector3(-852.0f, 450.0f, 0.0f));
		Word->SetScale(1.5f);
	}

	//ストーリースイッチ関数
	void StorySwitch();

	//効果音再生関数
	void playSE();
};
