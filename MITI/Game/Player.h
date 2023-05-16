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
	enum EnAnimationClip {		//アニメーション。
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
	AnimationClip AnimationClips[enAnimationClip_Num];		//アニメーションクリップ。

	Vector3 StickL;

	//鉄球の所持数
	int ironBall = 0;

	//鉄球置き＆回収のフラグ
	bool get_Iron = false, put_Iron = false;

	//UIフラグ
	bool get_Ui = false, put_Ui = false;

	//鉄球置き＆回収アニメーションのフラグ
	bool get_IronAnim = false, put_IronAnim = false;

	//キャラクターが滑っていく時に加算する移動速度
	Vector3 SlipMoveSpeed;

	//プレイヤーの状態を保存する変数
	int playerState = 0;

	//スティックの入力量を保存する変数

	//フォントレンダー
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

