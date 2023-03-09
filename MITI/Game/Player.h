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

	//�ړ�����
	void Move();
	//��]����
	void Rotation();

	//�L�����N�^�[�R���g���[���[
	CharacterController characterController;

	//�L�����N�^�[�̈ړ����x
	Vector3 moveSpeed;

	//�N�H�[�^�j�I��
	Quaternion rotation;

	//�v���C���[�̏�Ԃ�ۑ�����ϐ�
	int playerState = 0;

	//�X�e�B�b�N�̓��͗ʂ�ۑ�����ϐ�
	Vector3 StickL;
};

