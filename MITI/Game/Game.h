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
	bool Start();

	void InitWorld();

	void ClassCreate();
	void ClassDelete();

	void Over();
	void Clear();

	void Update();

	void LevelUp() { M_Level += 1; }
	void ClearFlagSet(bool Flag) { M_ClearFlagDecision = Flag; }
	void GameOverFlagSet(bool Flag) { M_GameOverFlagDecision = Flag; }
	void GameClearFlagSet(bool Flag) { M_GameClearFlagDecision = Flag; }
	void CreateFlagSet(bool Flag) { M_CreateFlagDecision = Flag; }
	void DeleteFlagSet(bool Flag) { M_DeleteFlagDecision = Flag; }
	void Delete() { DeleteGO(this); }

	int GetLevel() { return M_Level; }
	bool GetClearFlag() { return M_ClearFlagDecision; }
	bool GetGameOverFlag() { return M_GameOverFlagDecision; }
	bool GetGameClearFlag() { return M_GameClearFlagDecision; }
	bool GetCreateFlag() { return M_CreateFlagDecision; }
	bool GetDeleteFlag() { return M_DeleteFlagDecision; }
	bool GetPauseFlag() { return M_PauseFlagDecision; }
private:
	int M_Level = 0;
	int M_LevelMax = 9;
	
	bool M_ClearFlagDecision = false;
	bool M_GameOverFlagDecision = false;
	bool M_GameClearFlagDecision = false;
	bool M_CreateFlagDecision = false;
	
	bool M_BgmSetDecision = true;
	bool M_DeleteFlagDecision = false;

	bool M_FlagDecision = false;

	bool M_PauseFlagDecision = false;

	SoundSource* P_Bgm = nullptr;
	IronBall* P_IronBall = nullptr;
	Player* P_Player = nullptr;
	Stage* P_Stage = nullptr;
	UI* P_Ui = nullptr;
	Box* P_Box = nullptr;
	Fade* P_Fade = nullptr;
	GameCamera* P_GameCamera = nullptr;

	SoundSetting S_SoundSetting;
};

