#include "k2EngineLowPreCompile.h"
#include "ModelRender.h"

namespace nsK2EngineLow
{
	ModelRender::ModelRender()
	{

	}

	ModelRender::~ModelRender()
	{

	}

	void ModelRender::Init
	(
		const char* filePath,
		AnimationClip* animationClips,
		int numAnimationClips,
		EnModelUpAxis enModelUpAxis,
		bool isShadowReciever,
		int maxInstance,
		bool isFrontCullingOnDrawShadowMap
	)
	{
		m_modelInitData.m_tkmFilePath = filePath;
		m_modelInitData.m_fxFilePath = "Assets/shader/model.fx";
		m_modelInitData.m_modelUpAxis = enModelUpAxis;

		m_model.Init(m_modelInitData);
	}

	void ModelRender::Update()
	{

		if (m_isEnableInstancingDraw)
		{
			return;
		}

		UpdaterWorldMatrixInModes();
	}

	void ModelRender::UpdaterWorldMatrixInModes()
	{
		m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);
	}

	void ModelRender::Draw(RenderContext& rc)
	{
		g_renderingEngine->InRenderObject(this);
	}


	void ModelRender::OnRender(RenderContext& rc) 
	{
		m_model.Draw(rc);
	}
}