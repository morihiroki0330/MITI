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

	void SetWorld();
	void SetClear(bool Flag) { ClearFlag = Flag; }
	void SetGameOver(bool Flag) { GameOverFlag = Flag; }
	void SetCreate(bool Flag) { CreateFlag = Flag; }
	void SetDelete(bool Flag) { DeleteSet = Flag; }

	void Update();

	void GameOver();

	void Clear();

	void ClassCreate();
	void ClassDelete();

	int GetLevel() { return Level; }
	void LevelUp() { Level += 1; }
	
	bool GetClear() { return ClearFlag; }
	bool GetGameOver() { return GameOverFlag; }
	bool GetCreate() { return CreateFlag; }
	bool GetDelete() { return DeleteSet; }

private:
	
	int Level = 0;
	int Level_Max = 9;
	
	bool ClearFlag = false;
	bool GameOverFlag = false;
	bool CreateFlag = false;
	
	bool BgmSet = true;
	bool DeleteSet = false;

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

