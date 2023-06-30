#pragma once
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

	void LevelUp() { Level += 1; }
	void ClearFlagSet(bool Flag) { ClearFlag = Flag; }
	void GameOverFlagSet(bool Flag) { GameOverFlag = Flag; }
	void CreateFlagSet(bool Flag) { CreateFlag = Flag; }
	void DeleteFlagSet(bool Flag) { DeleteFlag = Flag; }
	
	int GetLevel() { return Level; }
	bool GetClearFlag() { return ClearFlag; }
	bool GetGameOverFlag() { return GameOverFlag; }
	bool GetCreateFlag() { return CreateFlag; }
	bool GetDeleteFlag() { return DeleteFlag; }

private:
	
	int Level = 0;
	int Level_Max = 9;
	
	bool ClearFlag = false;
	bool GameOverFlag = false;
	bool CreateFlag = false;
	
	bool BgmSet = true;
	bool DeleteFlag = false;

	int Ending_state = 0;
	bool key1 = false;
	bool key2 = false;
	bool key3 = false;
	bool key4 = false;
	
	SoundSource* BGM = nullptr;
	IronBall* ironball = nullptr;
	Player* player = nullptr;
	Stage* stage = nullptr;
	UI* ui = nullptr;
	Box* box = nullptr;
	Fade* fade = nullptr;
	GameCamera* gamecamera = nullptr;
};

