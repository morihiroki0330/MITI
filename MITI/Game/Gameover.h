#pragma once

//�Q�[���I�[�o�[
class Gameover :public IGameObject
{
public:
	Gameover();
	~Gameover();
	//�X�V����
	void Update();
	//�`�揈��
	void Render(RenderContext& rc);

	//�����o�ϐ�	
	SpriteRender GAMEOVER;   //�X�v���C�g�����_�[
};