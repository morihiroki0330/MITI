#pragma once
class Box;
class Stage;
class Game;
class IronBall;

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
	~Player();

	bool Start();

	void InitAnimation();

	void InitModel();

	void InitSound();

	void Update();

	void Render(RenderContext& rc);

	void Move();

	void Rotation();

	void Ball();

	void ManageState();

	void Animation();

	void PlayerMapSet();

	void LevelSet();

	void GameOver();

	void DirectionSet();

	void BoxHit();

	void Sound();

	void WalkSound();

	void IceWalkSound();

	void SlipFlagSet(bool Flag) { SlipFlag = Flag; }
	void HitFlagSet(bool Flag) { HitFlag = Flag; }

	int GetIronBallCount() { return ironBall; }

	ModelRender PlayerModel;
	Quaternion PlayerRotation;
	AllLight PlayerLight;
	CharacterController PlayerController;
	Vector3 PlayerPosition;
	Vector3 MoveSpeed;
	Vector3 StickL;
	Vector3 PlayerSetPosition[10][10];
	enum EnAnimationClip {		
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
	AnimationClip AnimationClips[enAnimationClip_Num];	

	int PlayerState = 0;
	int Frame = 0;
	int ironBall = 0;
	int PlayerMap = 0;
	int EnterDirection = 0;

	bool IronGet = false;
	bool IronPut = false;

	bool IronGetAnim = false;
	bool IronPutAnim = false;

	bool SlipFlag = false;
	bool HitFlag = false;

	bool FallSet = false;
	bool BgmSet = false;
	
	Box* box = nullptr;
	Stage* stage = nullptr;
	Game* game = nullptr;
	IronBall* ironball = nullptr;
	SoundSource* WalkSe = nullptr;
	SoundSource* IceWalkSe = nullptr;
};

