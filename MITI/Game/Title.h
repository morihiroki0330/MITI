#pragma once
#include "sound/SoundSource.h"
class Game;
//�^�C�g���B
class Title : public IGameObject
{
public:
	Title();
	~Title();
	void Update();
	void Render(RenderContext& rc);
	Game* game;
	SpriteRender TITLE;
	SoundSource* BGM;
};
