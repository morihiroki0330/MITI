#include "k2EngineLowPreCompile.h"
#include "ModelRender.h"
#include "RenderingEngine.h"

namespace nsK2EngineLow
{
//コンストラクタ・デストラクタ・初期化・更新・描画

	//コンストラクタ
	ModelRender::ModelRender()
	{

	}

	//デストラクタ
	ModelRender::~ModelRender()
	{

	}

	//初期化
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

		//スケルトンの初期化
		std::string skeletonFilePath = filePath;
		int pos = (int)skeletonFilePath.find(".tkm");
		skeletonFilePath.replace(pos, 4, ".tks");
		m_skeleton.Init(skeletonFilePath.c_str());


		//アニメーションの初期化
		m_animationClips = animationClips;
		m_numAnimationClips = numAnimationClips;
		m_animation.Init(m_skeleton,animationClips,numAnimationClips);

		//モデルの初期化
		m_model.Init(m_modelInitData);
	}

	//更新
	void ModelRender::Update()
	{

		if (m_isEnableInstancingDraw)
		{
			return;
		}

		UpdaterWorldMatrixInModes();

		if (m_skeleton.IsInited()) {
			m_skeleton.Update(m_model.GetWorldMatrix());
		}

		m_animation.Progress(g_gameTime->GetFrameDeltaTime() * m_animationSpeed);
	}

	void ModelRender::UpdaterWorldMatrixInModes()
	{
		m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);
	}

	//モデルデータの移動
	void ModelRender::Draw(RenderContext& rc)
	{
		g_renderingEngine->InRenderObject(this);
	}

	//モデルの描画
	void ModelRender::OnRender(RenderContext& rc) 
	{
		m_model.Draw(rc);
	}

}