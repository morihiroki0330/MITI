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
	S_ICEFLOOR,
	S_IRONBALLPUT,
	S_IRONBALLGET,
	S_WALK,
	S_FALL
};

class Bgm : public IGameObject
{
public:
	Bgm();
	~Bgm();
	void Update();

	SoundSource* BGM_SE;
};

