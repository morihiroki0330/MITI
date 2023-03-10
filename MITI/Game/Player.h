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
	//�S������
	void Ball();
	//�A�j���[�V��������
	void Animation();
	//�X�e�[�^�X�\������
	void Status();

	//�S���̏�����
	int ironBall = 0;

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

	//�t�H���g�����_�[
	FontRender fontRender;
};

