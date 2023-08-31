#pragma once
#include "NumberStorage.h"
class Box;
class Stage;
class Game;
class IronBall;
enum PlayerDirection
{
	PLAYERDIRECTION_UP = 0,
	PLAYERDIRECTION_DOWN = 1,
	PLAYERDIRECTION_RIGHT = 2,
	PLAYERDIRECTION_LEFT = 3
};
enum DirectionController
{
	MOVE_UP = 0,
	MOVE_DOWN = 1,
	MOVE_RIGHT = 2,
	MOVE_LEFT = 3
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
	void InitIronBallCount(int Count) { M_IronBallCount = Count; }
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

	void IronBallCountPlus() { M_IronBallCount++; }
	void IronBallCountMinus() { M_IronBallCount--; }
	void IronBallPutFlagSet(bool Flag) { M_IronBallPutFlagDecision = Flag; }
	void IronBallGetFlagSet(bool Flag) { M_IronBallGetFlagDecision = Flag; }
	void IronBallPutAnimationFlagSet(bool Flag) { M_IronBallPutAnimationFlagDecision = Flag; }
	void IronBallGetAnimationFlagSet(bool Flag) { M_IronBallGetAnimationFlagDecision = Flag; }

	void Sound();
	void WalkSound();
	void IceWalkSound();

	void PlayerSlipFlagSet(bool Flag) { M_PlayerSlipFlagDecision = Flag; }
	void PlayerOnIceFloor();

	void PlayerCollisionBlock();
	void PlayerCollisionFlagSet(bool Flag) { M_PlayerCollisionFlagDecision = Flag; }

	int GetIronBallCount() { return M_IronBallCount; }
	bool GetIronBallPutFlag() { return M_IronBallPutFlagDecision; }
	bool GetIronBallGetFlag() { return M_IronBallGetFlagDecision; }

	int GetPlayerMap() { return M_PlayerMap; }
	bool GetPlayerSlipFlag() { return M_PlayerSlipFlagDecision; }
	bool GetPlayerCollisionFlag() { return M_PlayerCollisionFlagDecision; }

	float GetPlayerMoveSpeedX() { return M_PlayerMoveSpeed.x; }
	float GetPlayerMoveSpeedY() { return M_PlayerMoveSpeed.y; }
	float GetPlayerMoveSpeedZ() { return M_PlayerMoveSpeed.z; }

	float GetPlayerPositionX() { return M_PlayerPosition.x; }
	float GetPlayerPositionY() { return M_PlayerPosition.y; }
	float GetPlayerPositionZ() { return M_PlayerPosition.z; }

	int GetDirectionController(Vector3 Pos);
private:
	enum EnAnimationClip
	{
		ANIMATIONClLIP_IDLE,
		ANIMATIONClLIP_WALK,
		ANIMATIONClLIP_FALL,
		ANIMATIONClLIP_PUT,
		ANIMATIONClLIP_SLIP,
		ANIMATIONClLIP_NUM
	};
	enum AnimationNumber
	{
		PLAYERANIMATION_IDLE,
		PLAYERANIMATION_WALK,
		PLAYERANIMATION_FALL,
		PLAYERANIMATION_PUT,
		PLAYERANIMATION_SLIP
	};

	ModelRender M_PlayerModel;

	Quaternion M_PlayerRotation;

	AllLight M_PlayerLight;

	CharacterController M_PlayerController;

	Vector3 M_PlayerPosition;
	Vector3 M_PlayerMoveSpeed;
	Vector3 M_ControllerStickLeft;
	Vector3 M_PlayerSetPosition[M_Ymas][M_Xmas];

	AnimationClip M_PlayerAnimationClips[ANIMATIONClLIP_NUM];

	int M_PlayerState = 0;
	int M_Frame = 0;
	int M_IronBallCount = 0;
	int M_PlayerMap = 0;
	int M_PlayerMoveMap = 99;
	int M_EnterDirection = 0;

	bool M_IronBallGetFlagDecision = false;
	bool M_IronBallPutFlagDecision = false;

	bool M_IronBallGetAnimationFlagDecision = false;
	bool M_IronBallPutAnimationFlagDecision = false;

	bool M_PlayerSlipFlagDecision = false;
	bool M_PlayerCollisionFlagDecision = false;

	bool M_FallSet = false;
	bool M_BgmSet = false;

	bool M_MoveFlagDecision = false;
	
	Box* P_Box = nullptr;
	Stage* P_Stage = nullptr;
	Game* P_Game = nullptr;
	IronBall* P_IronBall = nullptr;
	SoundSource* P_WalkSe = nullptr;
	SoundSource* P_IceWalkSe = nullptr;

	SoundSetting S_SoundSetting;
	PlayerInformation S_PlayerInformation;
	BlockInformation S_BlockInformation;
	WorldInformation S_WorldInformation;
};

