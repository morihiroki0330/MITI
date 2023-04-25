#pragma once
class Player;
class UI : public IGameObject
{
public:
	UI();
	~UI();
	void Update();
	void Render(RenderContext& rc);

	//�{�^��
	SpriteRender A[2];
	SpriteRender B[2];

	//�\���L�[
	SpriteRender Up;
	SpriteRender Down;
	SpriteRender Right;
	SpriteRender Left;
	SpriteRender Non;

	//�S��
	SpriteRender Iron[2];

	Player* player;
};

