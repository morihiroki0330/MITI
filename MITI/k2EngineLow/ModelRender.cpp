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
		EnModelUpAxis enModelUpAxis
	)
	{
		m_modelInitData.m_tkmFilePath = filePath;
		m_modelInitData.m_fxFilePath = "Assets/shader/model.fx";
		m_modelInitData.m_modelUpAxis = enModelUpAxis;


		InitSkeleton(filePath);
		InitAnimation(animationClips, numAnimationClips, enModelUpAxis);
			

		directionLight.directionlight.x = 1.0f;
		directionLight.directionlight.y = -1.0f;
		directionLight.directionlight.z = -1.0f;

		directionLight.directionlight.Normalize();

		directionLight.lightcolor.x = 1.2f;
		directionLight.lightcolor.y = 1.2f;
		directionLight.lightcolor.z = 1.2f;
		directionLight.lightcolor.w = 1.0f;

		directionLight.eyePos = g_camera3D->GetPosition();

		m_modelInitData.m_expandConstantBuffer = &directionLight;
		m_modelInitData.m_expandConstantBufferSize = sizeof(directionLight);

		if (m_animationClips != nullptr)
		{
			m_modelInitData.m_skeleton = &m_skeleton;

			m_modelInitData.m_vsSkinEntryPointFunc = "VSSkinMain";
		}

		
		m_model.Init(m_modelInitData);
	}

	void ModelRender::InitSkeleton(const char* filePath)
	{
		std::string skeletonFilePath = filePath;
		int pos = (int)skeletonFilePath.find(".tkm");
		skeletonFilePath.replace(pos, 4, ".tks");
		m_skeleton.Init(skeletonFilePath.c_str());
	}

	void ModelRender::InitAnimation(AnimationClip* animationClips, int numAnimationClips, EnModelUpAxis enModelUpAxis)
	{
		m_animationClips = animationClips;
		m_numAnimationClips = numAnimationClips;
		if (m_animationClips != nullptr) {
			m_animation.Init(m_skeleton,
				m_animationClips,
				numAnimationClips);
		}
	}

	void ModelRender::Update()
	{

		if (m_isEnableInstancingDraw)
		{
			return;
		}

		UpdaterWorldMatrixInModes();

		if (m_skeleton.IsInited())
		{
			m_skeleton.Update(m_model.GetWorldMatrix());
		}

		m_animation.Progress(g_gameTime->GetFrameDeltaTime() * m_animationSpeed);
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