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

	ModelRender modelRender;
	Vector3 player_P;

	//�ړ�����
	void Move();
	//��]����
	void Rotation();
	//�S������
	void Ball();
	//�X�e�[�g�Ǘ�
	void ManageState();
	//�A�j���[�V��������
	void Animation();
	//�X�e�[�^�X�\������
	void Status();

	//�S���̏�����
	int ironBall = 0;

	//�S���u��������̃t���O
	bool get_Iron = false, put_Iron = false;

	//UI�t���O
	bool get_Ui = false, put_Ui = false;

	//�S���u��������A�j���[�V�����̃t���O
	bool get_IronAnim = false, put_IronAnim = false;

	//�L�����N�^�[�R���g���[���[
	CharacterController characterController;

	//�L�����N�^�[�̈ړ����x
	Vector3 moveSpeed;

	//�L�����N�^�[�������Ă������ɉ��Z����ړ����x
	Vector3 SlipMoveSpeed;

	//�N�H�[�^�j�I��
	Quaternion rotation;

	//�v���C���[�̏�Ԃ�ۑ�����ϐ�
	int playerState = 0;

	//�X�e�B�b�N�̓��͗ʂ�ۑ�����ϐ�
	Vector3 StickL;

	//�t�H���g�����_�[
	FontRender fontRender;

	Box* box;

	Stage* stage;

	Game* game;

	enum EnAnimationClip {		//�A�j���[�V�����B
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Run,
		enAnimationClip_Throw,
		enAnimationClip_Push,
		enAnimationClip_Fall,
		enAnimationClip_Put,
		enAnimationClip_Num,
	};
	AnimationClip m_animationClips[enAnimationClip_Num];		//�A�j���[�V�����N���b�v�B

	bool slipflag = false;

	bool hitflag = false;

	Vector3 savePos;

	Vector3 SetPosition[10][10];

	int player_map;

	FontRender as;

	FontRender asb;

	int EnterDirection;

	int level = 2;

	bool clearflag = false;

	bool Set;

	AllLight playerLight;
};

