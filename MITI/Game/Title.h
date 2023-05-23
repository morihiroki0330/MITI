#pragma once
#include "sound/SoundSource.h"
class Game;
class Fabe;
//�^�C�g���B
class Title : public IGameObject
{
public:
	Title();
	~Title();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	Game* game;
	SoundSource* BGM;
	Fabe* fabe;
	SpriteRender Title_s;
	bool BgmSet = true;
	bool Delete = false;
};
