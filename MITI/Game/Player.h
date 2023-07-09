#pragma once
class Box;
class Stage;
class Game;
class IronBall;
enum PlayerDirection
{
	PlayerDirectionUp,
	PlayerDirectionDown,
	PlayerDirectionRight,
	PlayerDirectionLeft
};
enum DirectionController
{
	Non,
	MoveUp,
	MoveDown,
	MoveRight,
	MoveLeft
};
enum EnAnimationClip 
{		
	enAnimationClip_Idle,
	enAnimationClip_Walk,
	enAnimationClip_Fall,
	enAnimationClip_Put,
	enAnimationClip_Slip,
	enAnimationClip_Num
};
enum AnimationNumber 
{
	PlayerAnimationIdle,
	PlayerAnimationWalk,
	PlayerAnimationFall,
	PlayerAnimationPut,
	PlayerAnimationSlip
};
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();

	void InitAnimation();
	void InitModel();
	void InitSound();
	void InitSetPosition();
	void InitIronBallCount(int Count) { IronBallCount = Count; }
	void LevelSet();

	void Update();
	void Render(RenderContext& rc);

	void PlayerToMove();
	void PlayerToRotation();
	void PlayerToIronBall();
	void PlayerDirectionSet();
	void PlayerMapSet();
	void PlayerGameOver();
	void PlayerGameClear();
	
	void PlayerAnimation();
	void PlayerManageState();

	void IronBallCountPlus() { IronBallCount++; }
	void IronBallCountMinus() { IronBallCount--; }
	void IronBallPutFlagSet(bool Flag) { IronBallPutFlag = Flag; }
	void IronBallGetFlagSet(bool Flag) { IronBallGetFlag = Flag; }
	void IronBallPutAnimationFlagSet(bool Flag) { IronBallPutAnimationFlag = Flag; }
	void IronBallGetAnimationFlagSet(bool Flag) { IronBallGetAnimationFlag = Flag; }

	void Sound();
	void WalkSound();
	void IceWalkSound();

	void PlayerSlipFlagSet(bool Flag) { PlayerSlipFlag = Flag; }
	void PlayerOnIceFloor();

	void PlayerCollisionBlock();
	void PlayerCollisionFlagSet(bool Flag) { PlayerCollisionFlag = Flag; }

	int GetIronBallCount() { return IronBallCount; }
	bool GetIronBallPutFlag() { return IronBallPutFlag; }
	bool GetIronBallGetFlag() { return IronBallGetFlag; }

	int GetPlayerMap() { return PlayerMap; }
	bool GetPlayerSlipFlag() { return PlayerSlipFlag; }
	bool GetPlayerCollisionFlag() { return PlayerCollisionFlag; }

	float GetPlayerMoveSpeedX() { return PlayerMoveSpeed.x; }
	float GetPlayerMoveSpeedY() { return PlayerMoveSpeed.y; }
	float GetPlayerMoveSpeedZ() { return PlayerMoveSpeed.z; }

	float GetPlayerPositionX() { return PlayerPosition.x; }
	float GetPlayerPositionY() { return PlayerPosition.y; }
	float GetPlayerPositionZ() { return PlayerPosition.z; }

	int GetDirectionController(Vector3 Pos);
private:
	ModelRender PlayerModel;
	Quaternion PlayerRotation;
	AllLight PlayerLight;
	CharacterController PlayerController;
	Vector3 PlayerPosition;
	Vector3 PlayerMoveSpeed;
	Vector3 ControllerStickLeft;
	Vector3 PlayerSetPosition[10][10];
	AnimationClip PlayerAnimationClips[enAnimationClip_Num];	

	int PlayerState = 0;
	int Frame = 0;
	int IronBallCount = 0;
	int PlayerMap = 0;
	int PlayerMoveMap = 0;
	int EnterDirection = 0;

	bool IronBallGetFlag = false;
	bool IronBallPutFlag = false;

	bool IronBallGetAnimationFlag = false;
	bool IronBallPutAnimationFlag = false;

	bool PlayerSlipFlag = false;
	bool PlayerCollisionFlag = false;

	bool FallSet = false;
	bool BgmSet = false;

	bool MoveFlag = false;
	
	Box* box = nullptr;
	Stage* stage = nullptr;
	Game* game = nullptr;
	IronBall* ironball = nullptr;
	SoundSource* WalkSe = nullptr;
	SoundSource* IceWalkSe = nullptr;


};

