#pragma once
class Fade : public IGameObject
{
public:
	Fade();
	void Update() override;
	void Render(RenderContext& rc) override;
	void StartFadeIn(){State = enState_FadeIn;}
	void StartFadeOut(){State = enState_FadeOut;}
	const bool IsFade() const{return State != enState_Idle;}
	const float GetCurrentAlpha() const{return Alpha;}
	void ButtonFade(SpriteRender& Button , bool Press_Button);
private:
	enum EnState 
	{
		enState_FadeIn,			
		enState_FadeOut,		
		enState_Idle,			
	};
	SpriteRender FadeTexture;
	EnState State = enState_Idle;		
	float Alpha = 1.0f;		
	bool Reset = true;

	Vector4 ButtonCollar = { 1.0f,1.0f,1.0f,1.0f };
	bool ButtonFadeIn = true;
	bool ButtonFadeOut = false;
	float ButtonAlpha = 1.0f;
};

