#pragma once
#include "NumberStorage.h"
class Player;
class IronBall;
class Stage;
class GameCamera;
class UI;
class Box;
class Bgm;
class Fade;
class Game : public IGameObject
{
public:
	~Game();
	bool Start();

	void InitWorld();

	void ClassCreate();
	void ClassDelete();

	void Over();
	void Clear();

	void Update();

	void LevelUp() { M_Level += 1; }
	void ClearFlagSet(bool Flag) { M_ClearFlag = Flag; }
	void GameOverFlagSet(bool Flag) { M_GameOverFlag = Flag; }
	void GameClearFlagSet(bool Flag) { M_GameClearFlag = Flag; }
	void CreateFlagSet(bool Flag) { M_CreateFlag = Flag; }
	void DeleteFlagSet(bool Flag) { M_DeleteFlag = Flag; }
	void Delete() { DeleteGO(this); }

	
	int GetLevel() { return M_Level; }
	bool GetClearFlag() { return M_ClearFlag; }
	bool GetGameOverFlag() { return M_GameOverFlag; }
	bool GetGameClearFlag() { return M_GameClearFlag; }
	bool GetCreateFlag() { return M_CreateFlag; }
	bool GetDeleteFlag() { return M_DeleteFlag; }

private:
	int M_Level = 0;
	int M_Level_Max = 9;
	
	bool M_ClearFlag = false;
	bool M_GameOverFlag = false;
	bool M_GameClearFlag = false;
	bool M_CreateFlag = false;
	
	bool M_BgmSet = true;
	bool M_DeleteFlag = false;

	bool M_Flag = false;

	SoundSource* P_BGM = nullptr;
	IronBall* P_IronBall = nullptr;
	Player* P_Player = nullptr;
	Stage* P_Stage = nullptr;
	UI* P_Ui = nullptr;
	Box* P_Box = nullptr;
	Fade* P_Fade = nullptr;
	GameCamera* P_GameCamera = nullptr;

	TextureHeight S_TextureHeight;
	TextureWide S_TextureWide;
	Color S_Color;
	FadeInformation S_FadeInformation;
	GridPosition S_GridPosition;
	SoundSetting S_SoundSetting;
	PlayerInformation S_PlayerInformation;
	BlockInformation S_BlockInformation;
	WorldInformation S_WorldInformation;
	IronBallInformation S_IronBallInformation;
};

