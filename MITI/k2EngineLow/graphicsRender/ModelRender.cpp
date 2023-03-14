#include "k2EngineLowPreCompile.h"
#include "ModelRender.h"
#include "RenderingEngine.h"

namespace nsK2EngineLow
{
//�R���X�g���N�^�E�f�X�g���N�^�E�������E�X�V�E�`��

	//�R���X�g���N�^
	ModelRender::ModelRender()
	{

	}

	//�f�X�g���N�^
	ModelRender::~ModelRender()
	{

	}

	//������
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

		//�X�P���g���̏�����
		std::string skeletonFilePath = filePath;
		int pos = (int)skeletonFilePath.find(".tkm");
		skeletonFilePath.replace(pos, 4, ".tks");
		m_skeleton.Init(skeletonFilePath.c_str());


		//�A�j���[�V�����̏�����
		m_animationClips = animationClips;
		m_numAnimationClips = numAnimationClips;
		m_animation.Init(m_skeleton,animationClips,numAnimationClips);

		//���f���̏�����
		m_model.Init(m_modelInitData);
	}

	//�X�V
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

	//���f���f�[�^�̈ړ�
	void ModelRender::Draw(RenderContext& rc)
	{
		g_renderingEngine->InRenderObject(this);
	}

	//���f���̕`��
	void ModelRender::OnRender(RenderContext& rc) 
	{
		m_model.Draw(rc);
	}

}