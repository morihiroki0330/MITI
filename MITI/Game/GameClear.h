#pragma once

//�Q�[���N���A
class GameClear:public IGameObject
{
public:
	GameClear();
	~GameClear();
	//�X�V����
	void Update();
	//�`�揈��
	void Render(RenderContext& rc);

	//�����o�ϐ�	
	SpriteRender GAMEOVER;   //�X�v���C�g�����_�[
};

