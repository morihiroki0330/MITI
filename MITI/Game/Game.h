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
class G_Wall;
class G_IceFloor;

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
	G_Wall* m_G_Wall;
	G_IceFloor* m_G_IceFloor;

	//���Ԃ𑪂�֐�
	int timer;
	int timelimit = 60;

	PhysicsStaticObject m_physicsStaticObject;
};

