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
	int ballState = 0;	//�v���C���[�̃X�e�[�g(���)��\���ϐ��B
private:

	void Move();
	//�����o�ϐ��B
	ModelRender modelRender;	//���f�������_�\�B
	FontRender tekyupos;


	//CharacterController characterController;  //�L�����N�^�[�R���g���[���[�B
	Vector3 moveSpeed;		//�ړ����x�B
	Quaternion rotation;  //�N�H�[�^�j�I���B
	Vector3 firstPosition;		//�ŏ��̍��W�B

	PhysicsSphereObject m_physicsSphereObject;

	AllLight tekyuLight;
};
