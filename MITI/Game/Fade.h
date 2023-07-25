#pragma once
#include "NumberStorage.h"
class Fade : public IGameObject
{
public:
	Fade();
	void Update() override;
	void Render(RenderContext& rc) override;
	void StartFadeIn(){M_State = ENSTATE_FADEIN;}
	void StartFadeOut(){M_State = ENSTATE_FADEOUT;}
	const bool IsFade() const{return M_State != ENSTATE_IDLE;}
	const float GetCurrentAlpha() const{return M_Alpha;}
	void ButtonFade(SpriteRender& Button , bool Press_Button);
private:
	enum EnState 
	{
		ENSTATE_FADEIN = 1,			
		ENSTATE_FADEOUT = 2,		
		ENSTATE_IDLE = 3,			
	};
	SpriteRender M_FadeTexture;
	EnState M_State = ENSTATE_IDLE;
	Vector4 M_ButtonCollar = { 1.0f, 1.0f, 1.0f, 1.0f };
	
	bool M_AlphaReset = true;
	bool M_ButtonFadeIn = true;
	bool M_ButtonFadeOut = false;
	float M_ButtonAlpha = 1.0f;
	float M_Alpha = 1.0f;

	TextureHeight S_TextureHeight;
	TextureWide S_TextureWide;
	Color S_Color;
	FadeInformation S_FadeInformation;
};

