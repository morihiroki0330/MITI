#include "stdafx.h"
#include "Fade.h"
Fade::Fade()
{
	M_FadeTexture.Init("Assets/sprite/black.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_FadeTexture.Update();
}
void Fade::ButtonFade(SpriteRender& Button , bool Press_Button)
{
	if (Press_Button)
	{
		if (M_ButtonFadeInDecision)
		{
			M_ButtonAlpha -= S_FadeInformation.M_FadeHighSpeed * g_gameTime->GetFrameDeltaTime();
			if (M_ButtonAlpha <= S_Color.M_NonAlpha)
			{
				M_ButtonAlpha = S_Color.M_NonAlpha;
				M_ButtonFadeInDecision = false;
				M_ButtonFadeOutDecision = true;
			}
		}else {
			if (M_ButtonFadeOutDecision)
			{
				M_ButtonAlpha += S_FadeInformation.M_FadeHighSpeed * g_gameTime->GetFrameDeltaTime();
				if (M_ButtonAlpha >= S_Color.M_ResetAlpha)
				{
					M_ButtonAlpha = S_Color.M_ResetAlpha;
					M_ButtonFadeInDecision = true;
					M_ButtonFadeOutDecision = false;
				}
			}
		}
	}else {
		if (M_ButtonFadeInDecision)
		{
			M_ButtonAlpha -= S_FadeInformation.M_FadeLowSpeed * g_gameTime->GetFrameDeltaTime();
			if (M_ButtonAlpha <= S_Color.M_NonAlpha)
			{
				M_ButtonAlpha = S_Color.M_ResetAlpha;
				M_ButtonFadeInDecision = false;
				M_ButtonFadeOutDecision = true;
			}
		}else {
			if (M_ButtonFadeOutDecision)
			{
				M_ButtonAlpha += S_FadeInformation.M_FadeLowSpeed * g_gameTime->GetFrameDeltaTime();
				if (M_ButtonAlpha >= S_Color.M_ResetAlpha)
				{
					M_ButtonAlpha = S_Color.M_ResetAlpha;
					M_ButtonFadeInDecision = true;
					M_ButtonFadeOutDecision = false;
				}
			}
		}
	}
	M_ButtonCollar = { S_Color.M_Red , S_Color.M_Green , S_Color.M_Blue , M_ButtonAlpha };
	Button.SetMulColor(M_ButtonCollar);
}
void Fade::Update()
{
	if (M_State == ENSTATE_FADEIN)
	{
		if (M_AlphaResetDecision)
		{
			M_Alpha = S_Color.M_ResetAlpha;
			M_AlphaResetDecision = false;
		}
		M_Alpha -= S_FadeInformation.M_FadeLowSpeed * g_gameTime->GetFrameDeltaTime();
		if (M_Alpha <= S_Color.M_NonAlpha)
		{
			M_Alpha = S_Color.M_NonAlpha;
			M_State = ENSTATE_IDLE;
			M_AlphaResetDecision = true;
		}
	}else {
		if (M_State == ENSTATE_FADEOUT)
		{
			if (M_AlphaResetDecision)
			{
				M_Alpha = S_Color.M_NonAlpha;
				M_AlphaResetDecision = false;
			}
			M_Alpha += S_FadeInformation.M_FadeLowSpeed * g_gameTime->GetFrameDeltaTime();
			if (M_Alpha >= S_Color.M_ResetAlpha)
			{
				M_Alpha = S_Color.M_ResetAlpha;
				M_State = ENSTATE_IDLE;
				M_AlphaResetDecision = true;
			}
		}
	}
}
void Fade::Render(RenderContext& rc)
{
	if (M_Alpha > S_Color.M_NonAlpha)
	{
		M_FadeTexture.SetMulColor({ S_Color.M_Red , S_Color.M_Green , S_Color.M_Blue , M_Alpha });
		M_FadeTexture.Draw(rc);
	}
}