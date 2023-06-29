#pragma once
class Player;
class Game;
class IronBall;
class UI : public IGameObject
{
public:
	UI();
	void InitTexture();
	void InitPosition();
	void InitUpdate();

	void Time();

	void Button();

	void Update();

	void Render(RenderContext& rc);
private:
	SpriteRender CanvasTexture;

	SpriteRender AbuttonTexture;
	Vector3 AbuttonPosition = { 680.0f , -400.0f , 0.0f };
	Vector4 AbuttonCollar_TRUE = { 1.0f , 1.0f , 1.0f , 1.0f };
	Vector4 AbuttonCollar_FALSE = { 1.0f , 1.0f , 1.0f , 0.7f };

	SpriteRender BbuttonTexture;
	Vector3 BbuttonPosition = { 830.0f , -400.0f , 0.0f };
	Vector4 BbuttonCollar_TRUE = { 1.0f , 1.0f , 1.0f , 1.0f };
	Vector4 BbuttonCollar_FALSE = { 1.0f , 1.0f , 1.0f , 0.7f };

	SpriteRender ControllerUpTexture;
	SpriteRender ControllerDownTexture;
	SpriteRender ControllerRightTexture;
	SpriteRender ControllerLeftTexture;
	SpriteRender ControllerNonTexture;
	Vector3 ControllerPosition = { -750.0f , -400.0f , 0.0f };

	SpriteRender IronBallCountTexture[6];
	Vector3 IronBallCountPosition = { 750.0f , -50.0f , 0.0f };
	
	SpriteRender StageCountTexture[11];

	FontRender TimerFont;
	Vector3 TimerPosition = { 830.0f , 305.0f , 0.0f };
	SpriteRender TimerFrameTexture;
	wchar_t Clock[256];
	int Timer = 0;
	int TimerOver = 0;;
	int TimerLimit = 100;

	Player* player = nullptr;
	Game* game = nullptr;
	IronBall* ironball = nullptr;
};

