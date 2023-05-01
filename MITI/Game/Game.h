#pragma once
//#include "Level3DRender/LevelRender.h"

class Player;
class IronBall;
class Gameover;
class GameClear;
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
//class G_laser;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();
	void Render(RenderContext& rc);

private:
	ModelRender m_modelRender;
	FontRender m_fontRender;
	FontRender a_fontRender;
	FontRender s_fontRender;
	IronBall* m_ironBall;			//鉄球
	G_Tekyu* m_G_tekyu;				//大鉄球
	Player* m_player;				//プレイヤー
	Gameover* m_gameover;			//ゲームオーバー
	GameClear* m_gameclear;			//ゲームクリア
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
	//G_laser* m_G_laser;

	//時間制限
	int timer;
	int timelimit = 90;

	AllLight stagewallLight;

	PhysicsStaticObject m_physicsStaticObject;
};

