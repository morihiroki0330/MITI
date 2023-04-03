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
			
		{
		//�f�B���N�V�������C�g�̏����ݒ�
		
			//���C�g�̕���
			light.DirectionLight.x = 1.0f;
			light.DirectionLight.y = -1.0f;
			light.DirectionLight.z = -1.0f;

			light.DirectionLight.Normalize();

			//���C�g�̃J���[
			light.DirectionLight_C.x = 1.0f;
			light.DirectionLight_C.y = 1.0f;
			light.DirectionLight_C.z = 1.0f;

		//�|�C���g���C�g�̏����ݒ�
		
			//���C�g�̍��W
			light.Point_P.x = 50.0f;
			light.Point_P.y = 50.0f;
			light.Point_P.z = 0.0f;

			//���C�g�̃J���[
			light.Point_C.x = 1.0f;
			light.Point_C.y = 1.0f;
			light.Point_C.z = 1.0f;

			//���C�g�̉e���͈�
			light.Point_R = 100.0f;

		//�X�|�b�g���C�g�̏����ݒ�
		
			//���C�g�̍��W
			light.Spot_P.x = 50.0f;
			light.Spot_P.y = 50.0f;
			light.Spot_P.z = 0.0f;

			//���C�g�̃J���[
			light.Spot_C.x = 1.0f;
			light.Spot_C.y = 1.0f;
			light.Spot_C.z = 1.0f;

			//���C�g�̕���
			light.Spot_D.x = 1.0f;
			light.Spot_D.y = -1.0f;
			light.Spot_D.z = 1.0f;

			//���C�g�͈̔�
			light.Spot_R = 300.0f;

			//���C�g�̊p�x
			light.Spot_A = Math::DegToRad(25.0f);

		//�������C�g
		
			//�n�ʂ̃J���[
			light.Ground_C.x = 0.7f;
			light.Ground_C.y = 0.5f;
			light.Ground_C.z = 0.3f;

			//���C�g�̃J���[
			light.Sky_C.x = 0.15f;
			light.Sky_C.y = 0.7f;
			light.Sky_C.z = 0.95f;

			//�n�ʂ̖@��
			light.Ground_N.x = 0.0f;
			light.Ground_N.y = 1.0f;
			light.Ground_N.z = 0.0f;

		//���ʃ��C�g
		
			//���C�g�̎��_
			light.eye_P = g_camera3D->GetPosition();

			//���C�g�̊���
			light.ambientlight.x = 0.5f;
			light.ambientlight.y = 0.5f;
			light.ambientlight.z = 0.5f;

			m_modelInitData.m_expandConstantBuffer = &light;
			m_modelInitData.m_expandConstantBufferSize = sizeof(light);
		}


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