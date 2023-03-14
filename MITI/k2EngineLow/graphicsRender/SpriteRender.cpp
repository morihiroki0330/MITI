#include "k2EngineLowPreCompile.h"
#include "SpriteRender.h"

namespace nsK2EngineLow
{

	void SpriteRender::Init
	(
		const char* filePath,
		const float w,
		const float h,
		AlphaBlendMode alphaBlendMode
	)
	{
		m_spriteInitData.m_ddsFilePath[0] = filePath;
		m_spriteInitData.m_fxFilePath = "Assets/shader/sprite.fx";

		m_spriteInitData.m_width = static_cast<UINT>(w);
		m_spriteInitData.m_height = static_cast<UINT>(h);

		m_spriteInitData.m_alphaBlendMode = alphaBlendMode;

		m_sprite.Init(m_spriteInitData);
	}


	void SpriteRender::Draw(RenderContext& rc)
	{
		g_renderingEngine->InRenderObject(this);
	}
	
	void SpriteRender::OnRender2D(RenderContext& rc)
	{
		m_sprite.Draw(rc);
	}
}

