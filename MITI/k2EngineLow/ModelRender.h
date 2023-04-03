#pragma once

#include "geometry/AABB.h"
//#include "graphics/ComputeAnimationVertexBuffer.h"

namespace nsK2EngineLow
{
	class RenderingEngine;

	struct Light
	{
	//�f�B���N�V�������C�g
		Vector3 DirectionLight;//���C�g�̕���
		float pad0;
		Vector3 DirectionLight_C;//���C�g�̃J���[
		float pad1;

	//�|�C���g���C�g
		Vector3 Point_P;//���C�g�̈ʒu
		float pad2;
		Vector3 Point_C;//�J���[
		float Point_R;//�e���͈�

	//�X�|�b�g���C�g
		Vector3 Spot_P;//���C�g�̈ʒu
		float pad3;
		Vector3 Spot_C;//���C�g�̃J���[
		float Spot_R;//�e���͈�
		Vector3 Spot_D;//���C�g�̕���
		float Spot_A;//���C�g�̊p�x

	//�������C�g
		Vector3 Ground_C;//�n�ʂ̃J���[
		float pad4;
		Vector3 Sky_C;//���C�g�̃J���[
		float pad5;
		Vector3 Ground_N;//�n�ʂ̖@��

	//����
		Vector3 eye_P;//���_�̈ʒu
		Vector3 ambientlight;//����
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
		Light light;
	};
}

