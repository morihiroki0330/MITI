#pragma once
//#include "Level3DRender/LevelRender.h"

class Player;
class Hole;
class IronBall;
class Gameover;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();
	void Render(RenderContext& rc);

private:
	ModelRender m_modelRender;
	IronBall* m_ironBall;		//鉄球
	Hole* hole;					//穴
	Player* m_player;			//プレイヤー
	Gameover* m_gameover;		//ゲームオーバー
	Vector3 m_pos;
};

