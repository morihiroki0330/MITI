#pragma once
#include "sound/SoundSource.h"
class Bgm : public IGameObject
{
public:
	Bgm();
	~Bgm();
	void Update();

	SoundSource* BGM;
	SoundSource* SE;
};

