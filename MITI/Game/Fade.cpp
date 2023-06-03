#include "stdafx.h"
#include "Fade.h"

namespace
{
	const Vector3	SCALE = Vector3(2.16f, 2.16f, 1.0f);
	const Vector3	POSITIOIN = Vector3(-140.0f, 10.0, 0.0f);
}

Fade::Fade()
{
	m_spriteRender.Init("Assets/sprite/black.DDS", 1920, 1080);
	m_spriteRender.Update();
}

Fade::~Fade()
{
	
}

void Fade::Update()
{
	if (m_state == enState_FadeIn)
	{
		if (Reset == true)
		{
			m_currentAlpha = 1.0f;
			Reset = false;
		}
		m_currentAlpha -= 1.0f * g_gameTime->GetFrameDeltaTime();
		if (m_currentAlpha <= 0.0f) 
		{
			m_currentAlpha = 0.0f;
			m_state = enState_Idle;
			Reset = true;
		}
	}else {
	if (m_state == enState_FadeOut)
	{
		if (Reset == true)
		{
			m_currentAlpha = 0.0f;
			Reset = false;
		}
		m_currentAlpha += 1.0f * g_gameTime->GetFrameDeltaTime();
		if (m_currentAlpha >= 1.0f)
		{
			m_currentAlpha = 1.0f;
			m_state = enState_Idle;
			Reset = true;
		}
	}else {
	if (m_state == enState_Idle)
	{

	}
	}
	}
}

void Fade::Render(RenderContext& rc)
{
	if (m_currentAlpha > 0.0f)
	{
		m_spriteRender.SetMulColor({ 1.0f, 1.0f, 1.0f, m_currentAlpha });
		m_spriteRender.Draw(rc);
	}
}