#pragma once
#include "sound/SoundSource.h"
enum Play_Bgm
{
	B_TITLE,
	B_STAGE,
	B_STAGECLEAR,
	B_GAMECLEAR,
	B_GAMEOVER,
	S_WEIGHTBOARD,
	S_ICEFLOOR=33,
	S_IRONBALLPUT = 34,
	S_IRONBALLGET = 35,
	S_WALK = 36,
	S_FALL = 37,
	S_KAIDAN = 38,
	S_BOXGET = 40
};

class Bgm : public IGameObject
{
public:
	Bgm();
	~Bgm();
	void Update();

	SoundSource* BGM_SE;
};

