#pragma once
#include "sound/SoundSource.h"
class Game;
class Bgm;
class Story;
class Fade;
class StageClear : public IGameObject
{
public:
	~StageClear();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender Stageclear_S;  
	SpriteRender Abutton_S;  

	SoundSource* BGM = nullptr;
	Game* game = nullptr;;
	Bgm* bgm = nullptr;;
	Fade* fade = nullptr;;

	bool BgmSet = true;
	bool Delete = false;
	bool Press_Abutton = false;
};

