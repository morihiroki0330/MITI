#pragma once
//#include "Level3DRender/LevelRender.h"

class Player;
class Hole;
class IronBall;
class Gameover;
class GameClear;
class G_Tekyu;
class Stage;
class GameCamera;
class G_BreakFloar;
class G_WeightBoard;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();
	void Render(RenderContext& rc);

private:
	ModelRender m_modelRender;
	IronBall* m_ironBall;			//持てる鉄球
	Hole* hole;						//穴
	G_Tekyu* m_G_tekyu;				//大鉄球
	Player* m_player;				//プレイヤー
	Gameover* m_gameover;			//ゲームオーバー
	GameClear* m_gameclear;			//ゲームクリア
	Stage* m_stage;					//ステージ
	Vector3 m_pos;					//座標
	GameCamera* m_gamecamera;		//カメラ
	G_BreakFloar* m_G_breakfloar;   //崩壊する床
	G_WeightBoard* m_G_WeightBoard;



	PhysicsStaticObject m_physicsStaticObject;
};

