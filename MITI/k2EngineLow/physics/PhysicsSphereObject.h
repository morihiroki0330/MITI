/*!
 * @brief	���̓����蔻��B
 */

#pragma once

#include "physics/SphereCollider.h"
#include "physics/RigidBody.h"

namespace nsK2EngineLow {
	/// <summary>
	/// ���^�����I�u�W�F�N�g
	/// </summary>
	class PhysicsSphereObject : public Noncopyable {
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		PhysicsSphereObject();
		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~PhysicsSphereObject();
		/// <summary>
		/// ���̍쐬�B
		/// </summary>
		/// <param name="size">���̑傫���B</param>
		/// <param name="position">���̍��W�B</param>
		/// <param name="rotation">���̉�]�B</param>
		/// <param name="restitution">���̔����́B</param>
		/// <param name="mass">���̏d���B0�ɂ���Ɠ����Ȃ��B</param>
		void CreateCylinder(const float size, const Vector3 position, const Quaternion rotation,
			const float restitution = 0.0f, const float mass = 0.0f);
		/// <summary>
		/// ���C�͂�ݒ肷��B
		/// </summary>
		/// <param name="friction">���C�́B10���ő�l�B</param>
		void SetFriction(float friction)
		{
			m_rigidBody.SetFriction(friction);
		}
		btCollisionObject* GetbtCollisionObject()
		{
			return m_rigidBody.GetBody();
		}
		/// <summary>
		/// ���̂��擾�B
		/// </summary>
		RigidBody* GetRigidBody() {
			return &m_rigidBody;
		}
		/// <summary>
		/// ���̂�j���B
		/// </summary>
		void Release()
		{
			m_rigidBody.Release();
		}
	private:
		SphereCollider m_SphereCollider;		//���R���C�_�[�B
		RigidBody m_rigidBody;						//���́B
	};
}