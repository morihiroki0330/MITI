/*!
* @brief	静的オブジェクト。
*/


#include "k2EngineLowPreCompile.h"
#include "physics/PhysicsStaticObjectPos.h"

namespace nsK2EngineLow {
	PhysicsStaticObjectPos::PhysicsStaticObjectPos()
	{
	}
	PhysicsStaticObjectPos::~PhysicsStaticObjectPos()
	{
	}
	void PhysicsStaticObjectPos::CreateFromModel(Model& model, const Matrix& worldMatrix, const float restitution)
	{
		m_meshCollider.CreateFromModel(model, worldMatrix);
		RigidBodyInitData rbInfo;
		rbInfo.collider = &m_meshCollider;
		rbInfo.mass = 0.0f;
		rbInfo.restitution = restitution;
		m_rigidBody.Init(rbInfo);
	}
}
