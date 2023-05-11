#pragma once
#include "sound/SoundSource.h"
enum Play_Bgm
{
	B_TITLE,
	B_STAGE,
	B_STAGECLEAR,
	B_GAMECLEAR,
	B_GAMEOVER,
	S_WEIGHTBOARD
};

struct BGM�ESE_LIST
{
	//�^�C�g��
	SoundSource* TITLE_BGM;

	//�X�e�[�W
	SoundSource* STAGE_BGM;

	//�X�e�[�W�N���A
	SoundSource* STAGECLEAR_BGM;

	//�Q�[���N���A
	SoundSource* GAMECLEAR_BGM;
	
	//�Q�[���I�[�o�[
	SoundSource* GAMEOVER_BGM;

	//������
	SoundSource* WEIGHTBOARD_SE;
};

class Bgm : public IGameObject
{
public:
	Bgm();
	~Bgm();
	void Update();
	void PlayBGM(int BGM_NUMBER);
	void PauseBGM(int BNG_NUMBER);
	void PlaySE(int BGM_NUMBER);

	BGM�ESE_LIST BGM�ESE;
};

