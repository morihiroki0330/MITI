#pragma once

#include "ICollider.h"
namespace nsK2EngineLow {
	/*!
	* @brief	ボックスコライダー。
	*/
	class BoxCollider : public ICollider
	{
	public:

		void Create(const Vector3& size);
		btCollisionShape* GetBody() const override
		{
			return shape.get();
		}

		void SetPosition(const Vector3& pos)
		{
			/*auto& btTrans = m_rigidBody.GetBody()->getWorldTransform();
			btVector3 btPos;
			btPos = btVector3(pos.x, pos.y, pos.z);
			btTrans.setOrigin(btPos);*/
		}
	private:
		std::unique_ptr<btBoxShape>		shape;
	};
}