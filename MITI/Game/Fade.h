#pragma once
#include "NumberStorage.h"
class Fade : public IGameObject
{
public:
	Fade();

	void ButtonFade(SpriteRender& Button , bool Press_Button);
	void StartFadeIn(){M_State = ENSTATE_FADEIN;}
	void StartFadeOut(){M_State = ENSTATE_FADEOUT;}

	const bool IsFade() const
	{
		return M_State != ENSTATE_IDLE;
	}
	const float GetCurrentAlpha() const
	{
		return M_Alpha;
	}
	
	void Update() override;
	void Render(RenderContext& rc) override;
private:
	enum EnState 
	{
		ENSTATE_FADEIN = 1,			
		ENSTATE_FADEOUT = 2,		
		ENSTATE_IDLE = 3,			
	};
	SpriteRender M_FadeTexture;
	int M_State = ENSTATE_IDLE;
	Vector4 M_ButtonCollar = { 1.0f, 1.0f, 1.0f, 1.0f };
	
	bool M_AlphaResetDecision = true;
	bool M_ButtonFadeInDecision = true;
	bool M_ButtonFadeOutDecision = false;
	float M_ButtonAlpha = 1.0f;
	float M_Alpha = 1.0f;

	TextureHeight S_TextureHeight;
	TextureWide S_TextureWide;
	Color S_Color;
	FadeInformation S_FadeInformation;
};

