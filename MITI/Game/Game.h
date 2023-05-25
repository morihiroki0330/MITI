#pragma once
//#include "Level3DRender/LevelRender.h"
#include "sound/SoundSource.h"
class Player;
class IronBall;
class Gameover;
class GameClear;
class StageClear;
class G_Tekyu;
class Stage;
class GameCamera;
class G_BreakFloar;
class G_WeightBoard;
class G_Wall;
class G_IceFloor;
class G_Kaidan;
class UI;
class Box;
class Bgm;
class Fabe;
//class G_laser;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Create();
	void Delete();
	void Countdown();
	void Render(RenderContext& rc);

	int Level = 0;
	int Level_Max = 9;

	int Count = 0;

	bool ClearFlag = false;
	bool GameOverFlag = false;
	bool CreateFlag = false;
	
	bool BgmSet = true;
	bool DeleteSet = false;

	SoundSource* BGM;

private:
	ModelRender m_modelRender;
	IronBall* m_ironBall;			//鉄球
	G_Tekyu* m_G_tekyu;				//大鉄球
	Player* m_player;				//プレイヤー
	Gameover* m_gameover;			//ゲームオーバー
	GameClear* m_gameclear;			//ゲームクリア
	StageClear* m_stageclear;
	Stage* m_stage;					//ステージ
	Vector3 m_pos;					//座標
	GameCamera* m_gamecamera;		//カメラ
	G_BreakFloar* m_G_breakfloar;   //崩れる床
	G_WeightBoard* m_G_WeightBoard;
	G_Wall* m_G_Wall;
	G_IceFloor* m_G_IceFloor;
	G_Kaidan* m_G_Kaidan;
	UI* Ui;
	Box* box;
	Bgm* bgm;
	Fabe* fabe;
	//G_laser* m_G_laser;
};

