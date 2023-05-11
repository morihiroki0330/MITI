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

struct BGM・SE_LIST
{
	//タイトル
	SoundSource* TITLE_BGM;

	//ステージ
	SoundSource* STAGE_BGM;

	//ステージクリア
	SoundSource* STAGECLEAR_BGM;

	//ゲームクリア
	SoundSource* GAMECLEAR_BGM;
	
	//ゲームオーバー
	SoundSource* GAMEOVER_BGM;

	//感圧板
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

	BGM・SE_LIST BGM・SE;
};

