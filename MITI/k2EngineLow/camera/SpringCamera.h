#pragma once

#include "CameraCollisionSolver.h"

namespace nsK2EngineLow
{
	class SpringCamera : public Noncopyable
	{
	public:
	//�R���X�g���N�^�E�f�X�g���N�^�E�������E�X�V
	
		//�R���X�g���N�^
		SpringCamera();

		//�f�X�g���N�^
		~SpringCamera();

		//������
		void Init
		(
			Camera& camera,
			float maxMoveSpeed,
			bool isEnableCollisionSolver,
			float sphereCollisionRadius
		);

		//�X�V
		void Update();
		
		//�J���������̂̍X�V
		void UpdateCamera()
		{
			if (m_camera) {
				m_camera->Update();
			}
		}

		//�o�l�J�����̍X�V
		//void UpdateSpringCamera();

	//���_�Ȃǂ̐ݒ�

		//�����_�̐ݒ�
		void SetTarget(const Vector3& target)
		{
			m_target = target;
		}

		//�����_�̎擾
		const Vector3& GetTratget() const
		{
			return m_target;
		}

		//���ۂ̒����_�̎擾
		const Vector3& GetRealTarget() const
		{
			if (m_camera == nullptr)
			{
				return Vector3::Zero;
			}
			return m_camera->GetTarget();
		}

		//���_�̐ݒ�
		void SetPosition(const Vector3& position)
		{
			m_position = position;
		}

		//���_�̎擾
		const Vector3& GetPosition() const
		{
			return m_position;
		}

		//���ۂ̎��_�̎擾
		const Vector3& GetRealPosition() const
		{
			if (m_camera == nullptr)
			{
				return Vector3::Zero;
			}
			return m_camera->GetPosition();
		}

		//�����ʂ̐ݒ�
		void SetFar(float _far)
		{
			if (m_camera = nullptr)
			{
				return;
			}
			m_camera->SetFar(_far);
		}

		//�ߕ��ʂ̐ݒ�
		void SetNear(float _near)
		{
			if (m_camera = nullptr)
			{
				return;
			}
			m_camera->SetNear(_near);
		}

	//�J����

		//�J�����̎擾1
		const Camera* GetCamera() const
		{
			return m_camera;
		}

		//�J�����̎擾2
		Camera* GetCamera()
		{
			return m_camera;
		}

		//�J�����̉�]�s����擾
		const Matrix& GetCameraRotation() const
		{
			if (m_camera == nullptr) {
				return Matrix::Identity;
			}
			return m_camera->GetCameraRotation();
		}

		//��p�̐ݒ�
		void SetViewAngle(float angle)
		{
			if (m_camera == nullptr)
			{
				return;
			}

			m_camera->GetViewAngle();

		}
		
		//��p�̎擾
		float GetViewAngle() const
		{
			if (m_camera == nullptr)
			{
				return 0.0f;
			}
			return m_camera->GetViewAngle();
		}

		//�o�l�̌�������ݒ�
		/*
		void SetDampingRate(float dampingRate)
		{
			m_targetDampingRate = dampingRate;
		}
		*/

		//�o�l�J�����̃��t���b�V��
		/*
		void Refresh()
		{
			m_targetMoveSpeed = Vector3::Zero;
			m_positionMoveSpeed = Vector3::Zero;
			m_isRefresh = true;
		}
		*/

	private:
	//�J����

		//�J����
		Camera* m_camera = nullptr;
		
		//�J�����̃��t���b�V��
		bool m_isRefresh = true;

		//�J�����̍ő呬�x
		float m_maxMoveSpeed = 0.0f;

		//�J�����̌�����
		float m_targetDampingRate = 1.0f;
		float m_dampingRate = 1.0f;

		//�R���W��������
		bool m_isEnableCollisionSolver = false;
		
		//�X�v�����O�J�����̉���
		float m_dampingRateVel = 0.0f;

	//�J�����̍��W
	
		//�����_
		Vector3 m_target = Vector3::Zero;

		//���_
		Vector3 m_position = Vector3::Zero;

		//�����_�̈ړ����x
		Vector3 m_targetMoveSpeed = Vector3::Zero;

		//���_�̈ړ����x
		Vector3 m_positionMoveSpeed = Vector3::Zero;

		
		
		

		//�R���W�����������L���H
		CameraCollisionSolver m_cameraCollisionSolver;
	};
}

