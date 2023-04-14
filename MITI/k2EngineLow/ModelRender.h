#pragma once

#include "geometry/AABB.h"
//#include "graphics/ComputeAnimationVertexBuffer.h"

namespace nsK2EngineLow
{
	class RenderingEngine;

	//���C�g�̍\����
	//��Vector�^���A�����Đ錾�����ꍇ�͊ԂɁyfloat pad(����)�z������
	//���ʃ��C�g�́yfloat pad_(����)�z���g�p����
	struct AllLight
	{
		//�f�B���N�V�������C�g
		Vector3 DirectionLight_D = { 0.0f,0.0f,0.0f };//���C�g�̕���
		float pad1;
		Vector4 DirectionLight_C = { 0.0f,0.0f,0.0f,0.0f };//���C�g�̃J���[


		//�|�C���g���C�g
		Vector3 Point_P = { 0.0f,0.0f,0.0f };//���C�g�̈ʒu
		float pad2;
		Vector4 Point_C = { 0.0f,0.0f,0.0f,0.0f };//���C�g�̃J���[
		float Point_R = 0.0f;//���C�g�̉e���͈�


		//�X�|�b�g���C�g
		Vector3 Spot_P = { 0.0f,0.0f,0.0f };//���C�g�̈ʒu
		float pad3;
		Vector4 Spot_C = { 0.0f,0.0f,0.0f,0.0f };//���C�g�̃J���[
		float Spot_R = 0.0f;;//�e���͈�
		Vector3 Spot_D = { 0.0f,0.0f,0.0f };//���C�g�̕���
		float Spot_A = 0.0f;//���C�g�̊p�x


		//�������C�g
		Vector3 Ground_C = { 0.0f,0.0f,0.0f };//�n�ʂ̃J���[
		float pad4;
		Vector4 Sky_C;//���C�g�̃J���[
		float pad5;
		Vector3 Ground_N = { 0.0f,0.0f,0.0f };//�n�ʂ̖@��
		float pad6;

		//���ʃ��C�g
		Vector3 eye_P = g_camera3D->GetPosition();//���_�̈ʒu
		float pad_1;
		Vector3 ambientlight = { 0.0f,0.0f,0.0f };//����
	};

	class ModelRender : public IRender
	{
	public:
		//�R���X�g���N�^�E�f�X�g���N�^
		ModelRender();
		~ModelRender();

		//������
		void Init
		(
			const char* filePath,
			struct AllLight light,
			AnimationClip* animationClips = nullptr,
			int numAnimationClips = 0,
			EnModelUpAxis enModelUpAxis = enModelUpAxisZ
			
		);
	
		//�A�j���[�V�����̏�����
		void InitAnimation
		(
		AnimationClip* animationClips,
		int numAnimationClips,
		EnModelUpAxis enModelUpAxis
		);

		void InitSkeleton(const char* filePath);

		//�X�V
		void Update();

//�`�揈��

		//�`��
		void Draw(RenderContext& rc);
		
		//�`�揈��
		void OnRender(RenderContext& rc) override;

//���W�E��]�E�g��

		//���W�E��]�E�g��ݒ�
		void SetTRS(const Vector3& pos, const Quaternion& rotation, const Vector3& scale)
		{
			SetPosition(pos);
			SetRotation(rotation);
			SetScale(scale);
		}

		//���W�ݒ�
		void SetPosition(const Vector3& pos)
		{
			m_position = pos;
		}

		//��]�ݒ�
		void SetRotation(const Quaternion& rotation)
		{
			m_rotation = rotation;
		}

		//�g��ݒ�
		void SetScale(const Vector3& scale)
		{
			m_scale = scale;
		}

//���f��

		//���f���̎擾
		Model& GetModel()
		{
			return m_model;
		}

//�A�j���[�V����
		
		//�A�j���[�V�����̍Đ�
		//�����F�i�A�j���[�V�����N���b�v�̔ԍ��j,�i��Ԏ��ԁA�P�ʁF�b�j
		void PlayAnimation(int animNo, float interpolareTime = 0.0f)
		{
			m_animation.Play(animNo, interpolareTime);
		}

		//�A�j���[�V�������Đ������H
		bool IsPlayAnimation() const
		{
			return m_animation.IsPlaying();
		}

		//�A�j���[�V�����̍Đ����x�ݒ�
		void SetAnimationSpeed(const float animationSpeed)
		{

		}

		//�{�[�����擾
		Bone* GetBone(int boneNo) const
		{
			return m_skeleton.GetBone(boneNo);
		}

		//�{�[������
		int FindBoneID(const wchar_t* boneName)
		{
			return m_skeleton.FindBoneID(boneName);
		}

//���C�g

		//�f�B���N�V�������C�g�̐ݒ�
		void SetDirectionLight(const Vector3& Direction,const Vector4& Color)
		{
			m_light.DirectionLight_D = Direction;
			m_light.DirectionLight_D.Normalize();
			m_light.DirectionLight_C = Color;
		}

	private:

		void UpdaterWorldMatrixInModes();
		
	private:
//���f��

		Model m_model;

		ModelInitData m_modelInitData;

//�A�j���[�V����

		//�A�j���[�V����
		Animation m_animation;

		//�A�j���[�V�����N���b�v
		AnimationClip* m_animationClips = nullptr;

		//�A�j���[�V�����N���b�v�̐�
		int m_numAnimationClips = 0;

		//�A�j���[�V�����̑��x
		float m_animationSpeed = 1.0f;

		//�A�j���[�V�������X�V���邩�H
		bool m_isUpdateAnimation = true;
		
		//FBX�̏����
		EnModelUpAxis m_enFbxUpAxis = enModelUpAxisZ;

//�X�P���g��

		Skeleton m_skeleton;

		Vector3 					m_position = Vector3::Zero;			// ���W�B
		Quaternion	 				m_rotation = Quaternion::Identity;	// ��]�B
		Vector3						m_scale = Vector3::One;				// �g�嗦�B

		bool						m_isEnableInstancingDraw = false;

//���C�g
		AllLight m_light;
	};
}

