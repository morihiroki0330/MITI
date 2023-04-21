#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	void Update();
	void Render(RenderContext& rc);

	ModelRender modelRender;
	Vector3 player_P;

	//移動処理
	void Move();
	//回転処理
	void Rotation();
	//鉄球処理
	void Ball();
	//ステート管理
	void ManageState();
	//アニメーション処理
	void Animation();
	//ステータス表示処理
	void Status();

	//鉄球の所持数
	int ironBall = 0;

	//鉄球置き＆回収のフラグ
	bool get_Iron = false, put_Iron = false;

	//鉄球置き＆回収アニメーションのフラグ
	bool get_IronAnim = false, put_IronAnim = false;

	//キャラクターコントローラー
	CharacterController characterController;

	//キャラクターの移動速度
	Vector3 moveSpeed;

	//キャラクターが滑っていく時に加算する移動速度
	Vector3 SlipMoveSpeed;

	//クォータニオン
	Quaternion rotation;

	//プレイヤーの状態を保存する変数
	int playerState = 0;

	//スティックの入力量を保存する変数
	Vector3 StickL;

	//フォントレンダー
	FontRender fontRender;

	Vector3 savePos;

	enum EnAnimationClip {		//アニメーション。
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
	AnimationClip m_animationClips[enAnimationClip_Num];		//アニメーションクリップ。

	bool slipflag;
	AllLight playerLight;
	Vector3 savePos;
};

