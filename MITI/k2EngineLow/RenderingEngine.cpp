#include "k2EngineLowPreCompile.h"
#include "RenderingEngine.h"

namespace nsK2EngineLow
{
	RenderingEngine::RenderingEngine()
	{

	}

	RenderingEngine::~RenderingEngine()
	{

	}

	void RenderingEngine::Update()
	{

	}

	void RenderingEngine::AddRenderObject(RenderContext& rc)
	{
		for (auto& objData : m_renderObjects)
		{
			objData->OnRender(rc);
		}
	}

	void RenderingEngine::Execute(RenderContext& rc)
	{
		AddRenderObject(rc);
		m_renderObjects.clear();
	}
}