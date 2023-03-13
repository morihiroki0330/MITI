#pragma once

class G_Tekyu : public IGameObject
{
public:
	G_Tekyu();
	~G_Tekyu();
	const Vector3& GetPosition() const
	{
		return Tpos;
	}
	//Bouto* bouto;
	//�X�V�����B
	void Update();
	//�`�揈���B
	void Render(RenderContext& rc);
	//�ړ������B

	//void Rotation();
	//�X�e�[�g�Ǘ��B
	void ManageState();
	//�A�j���[�V�����̍Đ��B
	void PlayAnimation();
	//���y�̍Đ�
	void PlayMusic();
	void AddMoveSpeed(const Vector3& addMoveSpeed)
	{
		moveSpeed += addMoveSpeed;
	}


	int ballState = 0;	//�v���C���[�̃X�e�[�g(���)��\���ϐ��B
private:

	void Move();
	//�����o�ϐ��B
	ModelRender modelRender;	//���f�������_�\�B
	Vector3 Tpos;			//���W�B
	FontRender tekyupos;


	//CharacterController characterController;  //�L�����N�^�[�R���g���[���[�B
	Vector3 moveSpeed;		//�ړ����x�B
	Quaternion rotation;  //�N�H�[�^�j�I���B
	Vector3 firstPosition;		//�ŏ��̍��W�B

	PhysicsSphereObject m_physicsSphereObject;

};
