#pragma once

class G_Tekyu : public IGameObject
{
public:
	G_Tekyu();
	~G_Tekyu();
	void Update();
	void Render(RenderContext& rc);
	void ManageState();
	void PlayAnimation();
	void PlayMusic();
	void AddMoveSpeed(const Vector3& addMoveSpeed)
	{
		moveSpeed += addMoveSpeed;
	}
	const Vector3& GetPosition() const
	{
		return Tpos;
	}
	

	Vector3 Tpos;
	int ballState = 0;	//プレイヤーのステート(状態)を表す変数。
private:

	void Move();
	//メンバ変数。
	ModelRender modelRender;	//モデルレンダ―。
	FontRender tekyupos;


	//CharacterController characterController;  //キャラクターコントローラー。
	Vector3 moveSpeed;		//移動速度。
	Quaternion rotation;  //クォータニオン。
	Vector3 firstPosition;		//最初の座標。

	PhysicsSphereObject m_physicsSphereObject;

	AllLight tekyuLight;
};
