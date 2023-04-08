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
	IronBall* m_ironBall;			//���Ă�S��
	Hole* hole;						//��
	G_Tekyu* m_G_tekyu;				//��S��
	Player* m_player;				//�v���C���[
	Gameover* m_gameover;			//�Q�[���I�[�o�[
	GameClear* m_gameclear;			//�Q�[���N���A
	Stage* m_stage;					//�X�e�[�W
	Vector3 m_pos;					//���W
	GameCamera* m_gamecamera;		//�J����
	G_BreakFloar* m_G_breakfloar;   //���󂷂鏰
	G_WeightBoard* m_G_WeightBoard;



	PhysicsStaticObject m_physicsStaticObject;
};

