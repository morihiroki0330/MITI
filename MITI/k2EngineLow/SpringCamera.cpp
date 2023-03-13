#include "k2EngineLowPreCompile.h"
#include "SpringCamera.h"

namespace nsK2EngineLow
{
	//コンストラクタ
	SpringCamera::SpringCamera()
	{

	}

	//デストラクタ
	SpringCamera::~SpringCamera()
	{

	}

	//初期化
	void SpringCamera::Init
	(
		Camera& camera,
		float maxMoveSpeed,
		bool isEnableCollisionSolver,
		float sphereCollisionRadius)
	{
		m_camera = &camera;
		SetTarget(m_camera->GetTarget());
		SetPosition(m_camera->GetPosition());
		m_isEnableCollisionSolver = isEnableCollisionSolver;
		m_cameraCollisionSolver.Init(sphereCollisionRadius);
		m_targetMoveSpeed = Vector3::Zero;
		m_positionMoveSpeed = Vector3::Zero;
		m_maxMoveSpeed = maxMoveSpeed;
		m_isRefresh = true;
	}

	//更新
	void SpringCamera::Update()
	{
		if (m_isEnableCollisionSolver) 
		{
			Vector3 result;
			m_cameraCollisionSolver.Execute
			(
				result,
				m_camera->GetPosition(),
				m_camera->GetTarget()
			);
			m_camera->SetPosition(result);
		}
		UpdateCamera();
	}
}
