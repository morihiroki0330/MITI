#pragma once
class Box;
class Stage;
class Game;

enum Direction
{
	Up,
	Down,
	Right,
	Left
};

class Player : public IGameObject
{
public:
	Player();
	~Player();
	void Update();
	void Render(RenderContext& rc);
	void Move();
	void Rotation();
	void Ball();
	void ManageState();
	void Animation();
	void Status();
	
	ModelRender Character;
	Vector3 Character_P;
	Quaternion Character_R;
	AllLight Light;
	CharacterController CharacterController;
	Vector3 MoveSpeed;
	enum EnAnimationClip {		//�A�j���[�V�����B
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Run,
		enAnimationClip_Throw,
		enAnimationClip_Push,
		enAnimationClip_Fall,
		enAnimationClip_Put,
		enAnimationClip_Slip,
		enAnimationClip_Num,
	};
	AnimationClip AnimationClips[enAnimationClip_Num];		//�A�j���[�V�����N���b�v�B

	Vector3 StickL;

	//�S���̏�����
	int ironBall = 0;

	//�S���u��������̃t���O
	bool get_Iron = false, put_Iron = false;

	//UI�t���O
	bool get_Ui = false, put_Ui = false;

	//�S���u��������A�j���[�V�����̃t���O
	bool get_IronAnim = false, put_IronAnim = false;

	//�L�����N�^�[�������Ă������ɉ��Z����ړ����x
	Vector3 SlipMoveSpeed;

	//�v���C���[�̏�Ԃ�ۑ�����ϐ�
	int playerState = 0;

	//�X�e�B�b�N�̓��͗ʂ�ۑ�����ϐ�

	//�t�H���g�����_�[
	FontRender fontRender;

	Box* box;

	Stage* stage;

	Game* game;

	bool slipflag = false;

	bool hitflag = false;

	Vector3 savePos;

	Vector3 SetPosition[10][10];

	int player_map;

	FontRender as;

	FontRender asb;

	int EnterDirection;

	bool clearflag = false;

	bool Set;

	SoundSource* WALK;

	SoundSource* ICEWALK;
};

