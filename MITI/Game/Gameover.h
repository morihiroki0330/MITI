#pragma once
#include "sound/SoundSource.h"
class Game;
class Fade;
class Gameover :public IGameObject
{
public:
	~Gameover();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender Gameover_S;   
	SpriteRender Abutton_S;   

	Game* game = nullptr;
	Fade* fade = nullptr;
	SoundSource* BGM = nullptr;;

	bool BgmSet = true;
	bool Delete = false;
	bool Press_Abutton = false;
};