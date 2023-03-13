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
	IronBall* m_ironBall;		//�S��
	Hole* hole;					//��
	Player* m_player;			//�v���C���[
	Gameover* m_gameover;		//�Q�[���I�[�o�[
	Vector3 m_pos;
};

