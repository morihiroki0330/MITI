#pragma once

class Game;
class Fade;
class Title;
//�^�C�g���B
class Story : public IGameObject
{
public:
	Story();
	~Story();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	//�e�L�X�g�X�V�֐��B
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

	//�X�g�[���[�̐i�s�x(�ʍU�����Ƃ�+1)
	int storyNum = 0;

	//�w�i�̏����ԍ�
	int BackNumber = 0;

	float HIGH = 0.05f;	//�����e�L�X�g����

	//�I������H
	bool Endtext = false;

	bool ismul = false;
	float mul = 1.0f;	//�{���ϐ�

	//�w�i�ύX�֐�
	void BackChange();

	//�e�L�X�g���Z�b�g�֐�
	void TextReset()
	{
		delete Word;
		Word = new FontRender;
	}

	//�e�L�X�g�z�u�֐�
	void TextCreate()
	{
		Word->SetPosition(Vector3(-852.0f, 450.0f, 0.0f));
		Word->SetScale(1.5f);
	}

	//�X�g�[���[�X�C�b�`�֐�
	void StorySwitch();

	//���ʉ��Đ��֐�
	void playSE();
};
