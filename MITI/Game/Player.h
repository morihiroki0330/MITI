#pragma once
#include "NumberStorage.h"
class Box;
class Stage;
class Game;
class IronBall;
enum PlayerDirection
{
	PLAYERDIRECTION_UP,
	PLAYERDIRECTION_DOWN,
	PLAYERDIRECTION_RIGHT,
	PLAYERDIRECTION_LEFT
};
enum DirectionController
{
	MOVE_UP,
	MOVE_DOWN,
	MOVE_RIGHT,
	MOVE_LEFT
};
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
	void IronBallPutFlagSet(bool Flag) { M_IronBallPutFlag = Flag; }
	void IronBallGetFlagSet(bool Flag) { M_IronBallGetFlag = Flag; }
	void IronBallPutAnimationFlagSet(bool Flag) { M_IronBallPutAnimationFlag = Flag; }
	void IronBallGetAnimationFlagSet(bool Flag) { M_IronBallGetAnimationFlag = Flag; }

	void Sound();
	void WalkSound();
	void IceWalkSound();

	void PlayerSlipFlagSet(bool Flag) { M_PlayerSlipFlag = Flag; }
	void PlayerOnIceFloor();

	void PlayerCollisionBlock();
	void PlayerCollisionFlagSet(bool Flag) { M_PlayerCollisionFlag = Flag; }

	int GetIronBallCount() { return M_IronBallCount; }
	bool GetIronBallPutFlag() { return M_IronBallPutFlag; }
	bool GetIronBallGetFlag() { return M_IronBallGetFlag; }

	int GetPlayerMap() { return M_PlayerMap; }
	bool GetPlayerSlipFlag() { return M_PlayerSlipFlag; }
	bool GetPlayerCollisionFlag() { return M_PlayerCollisionFlag; }

	float GetPlayerMoveSpeedX() { return M_PlayerMoveSpeed.x; }
	float GetPlayerMoveSpeedY() { return M_PlayerMoveSpeed.y; }
	float GetPlayerMoveSpeedZ() { return M_PlayerMoveSpeed.z; }

	float GetPlayerPositionX() { return M_PlayerPosition.x; }
	float GetPlayerPositionY() { return M_PlayerPosition.y; }
	float GetPlayerPositionZ() { return M_PlayerPosition.z; }

	int GetDirectionController(Vector3 Pos);
private:
	ModelRender M_PlayerModel;
	Quaternion M_PlayerRotation;
	AllLight M_PlayerLight;
	CharacterController M_PlayerController;
	Vector3 M_PlayerPosition;
	Vector3 M_PlayerMoveSpeed;
	Vector3 M_ControllerStickLeft;
	Vector3 M_PlayerSetPosition[10][10];
	AnimationClip M_PlayerAnimationClips[ANIMATIONClLIP_NUM];

	int M_PlayerState = 0;
	int M_Frame = 0;
	int M_IronBallCount = 0;
	int M_PlayerMap = 0;
	int M_PlayerMoveMap = 0;
	int M_EnterDirection = 0;

	bool M_IronBallGetFlag = false;
	bool M_IronBallPutFlag = false;

	bool M_IronBallGetAnimationFlag = false;
	bool M_IronBallPutAnimationFlag = false;

	bool M_PlayerSlipFlag = false;
	bool M_PlayerCollisionFlag = false;

	bool M_FallSet = false;
	bool M_BgmSet = false;

	bool M_MoveFlag = false;
	
	Box* M_Box = nullptr;
	Stage* M_Stage = nullptr;
	Game* M_Game = nullptr;
	IronBall* M_IronBall = nullptr;
	SoundSource* M_WalkSe = nullptr;
	SoundSource* M_IceWalkSe = nullptr;

	TextureHeight S_TextureHeight;
	TextureWide S_TextureWide;
	Color S_Color;
	FadeInformation S_FadeInformation;
	GridPosition S_GridPosition;
	SoundSetting S_SoundSetting;
	PlayerInformation S_PlayerInformation;
	BlockInformation S_BlockInformation;
	WorldInformation S_WorldInformation;
	IronBallInformation S_IronBallInformation;
};

