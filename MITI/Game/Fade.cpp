#include "stdafx.h"
#include "Fade.h"
#include "Number_Storage.h"

namespace
{
	const Vector3	ScaleLE = Vector3(2.16f, 2.16f, 1.0f);
	const Vector3	PositionITIOIN = Vector3(-140.0f, 10.0, NON);
}

Fade::Fade()
{
	FadeTexture.Init("Assets/sprite/black.DDS", 1920, 1080);
	FadeTexture.Update();
}

void Fade::Update()
{
	if (State == enState_FadeIn)
	{
		if (Reset == true)
		{
			Alpha = 1.0f;
			Reset = false;
		}

		Alpha -= 1.0f * g_gameTime->GetFrameDeltaTime();

		if (Alpha <= NON) 
		{
			Alpha = NON;
			State = enState_Idle;
			Reset = true;
		}
	}else {
	if (State == enState_FadeOut)
	{
		if (Reset == true)
		{
			Alpha = NON;
			Reset = false;
		}
		Alpha += 1.0f * g_gameTime->GetFrameDeltaTime();
		if (Alpha >= 1.0f)
		{
			Alpha = 1.0f;
			State = enState_Idle;
			Reset = true;
		}
	}
	}
}

void Fade::ButtonFade(SpriteRender& Button , bool Press_Button)
{
	if (Press_Button)
	{
		if (ButtonFadeIn)
		{
			ButtonAlpha -= 10.0f * g_gameTime->GetFrameDeltaTime();
			if (ButtonAlpha <= NON)
			{
				ButtonAlpha = NON;
				ButtonFadeIn = false;
				ButtonFadeOut = true;
			}
		}else {
		if (ButtonFadeOut)
		{
			ButtonAlpha += 10.0f * g_gameTime->GetFrameDeltaTime();
			if (ButtonAlpha >= 1.0f)
			{
				ButtonAlpha = 1.0f;
				ButtonFadeIn = true;
				ButtonFadeOut = false;
			}
			}
		}
	}else {
		if (ButtonFadeIn)
		{
			ButtonAlpha -= 1.0f * g_gameTime->GetFrameDeltaTime();
			if (ButtonAlpha <= NON)
			{
				ButtonAlpha = NON;
				ButtonFadeIn = false;
				ButtonFadeOut = true;
			}
		}else {
		if (ButtonFadeOut)
		{

			ButtonAlpha += 1.0f * g_gameTime->GetFrameDeltaTime();
			if (ButtonAlpha >= 1.0f)
			{
				ButtonAlpha = 1.0f;
				ButtonFadeIn = true;
				ButtonFadeOut = false;
			}
			}
		}
	}
	ButtonCollar = { Red , Green , Blue , ButtonAlpha };
	Button.SetMulColor(ButtonCollar);
}

void Fade::Render(RenderContext& rc)
{
	if (Alpha > NON)
	{
		FadeTexture.SetMulColor({ 1.0f, 1.0f, 1.0f, Alpha });
		FadeTexture.Draw(rc);
	}
}