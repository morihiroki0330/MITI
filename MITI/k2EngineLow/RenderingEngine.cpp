#include "k2EngineLowPreCompile.h"
#include "RenderingEngine.h"

namespace nsK2EngineLow
{
	void RenderingEngine::AddRenderObject(RenderContext& rc)
	{
		for (auto& objData : m_renderObjects)
		{
			objData->OnRender(rc);
		}

		for (auto& objData : s_renderObjects)
		{
			objData->OnRender2D(rc);
		}
		
		for (auto& objData : f_renderObjects)
		{
			objData->OnRender2D(rc);
		}
	}

	void RenderingEngine::Execute(RenderContext& rc)
	{
		AddRenderObject(rc);
		m_renderObjects.clear();
		s_renderObjects.clear();
		f_renderObjects.clear();
	}
}