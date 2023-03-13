#pragma once

#include "CameraCollisionSolver.h"

namespace nsK2EngineLow
{
	class SpringCamera : public Noncopyable
	{
	public:
	//コンストラクタ・デストラクタ・初期化・更新
	
		//コンストラクタ
		SpringCamera();

		//デストラクタ
		~SpringCamera();

		//初期化
		void Init
		(
			Camera& camera,
			float maxMoveSpeed,
			bool isEnableCollisionSolver,
			float sphereCollisionRadius
		);

		//更新
		void Update();
		
		//カメラだけのの更新
		void UpdateCamera()
		{
			if (m_camera) {
				m_camera->Update();
			}
		}

		//バネカメラの更新
		//void UpdateSpringCamera();

	//視点などの設定

		//注視点の設定
		void SetTarget(const Vector3& target)
		{
			m_target = target;
		}

		//注視点の取得
		const Vector3& GetTratget() const
		{
			return m_target;
		}

		//実際の注視点の取得
		const Vector3& GetRealTarget() const
		{
			if (m_camera == nullptr)
			{
				return Vector3::Zero;
			}
			return m_camera->GetTarget();
		}

		//視点の設定
		void SetPosition(const Vector3& position)
		{
			m_position = position;
		}

		//視点の取得
		const Vector3& GetPosition() const
		{
			return m_position;
		}

		//実際の視点の取得
		const Vector3& GetRealPosition() const
		{
			if (m_camera == nullptr)
			{
				return Vector3::Zero;
			}
			return m_camera->GetPosition();
		}

		//遠平面の設定
		void SetFar(float _far)
		{
			if (m_camera = nullptr)
			{
				return;
			}
			m_camera->SetFar(_far);
		}

		//近平面の設定
		void SetNear(float _near)
		{
			if (m_camera = nullptr)
			{
				return;
			}
			m_camera->SetNear(_near);
		}

	//カメラ

		//カメラの取得1
		const Camera* GetCamera() const
		{
			return m_camera;
		}

		//カメラの取得2
		Camera* GetCamera()
		{
			return m_camera;
		}

		//カメラの回転行列を取得
		const Matrix& GetCameraRotation() const
		{
			if (m_camera == nullptr) {
				return Matrix::Identity;
			}
			return m_camera->GetCameraRotation();
		}

		//画角の設定
		void SetViewAngle(float angle)
		{
			if (m_camera == nullptr)
			{
				return;
			}

			m_camera->GetViewAngle();

		}
		
		//画角の取得
		float GetViewAngle() const
		{
			if (m_camera == nullptr)
			{
				return 0.0f;
			}
			return m_camera->GetViewAngle();
		}

		//バネの減衰率を設定
		/*
		void SetDampingRate(float dampingRate)
		{
			m_targetDampingRate = dampingRate;
		}
		*/

		//バネカメラのリフレッシュ
		/*
		void Refresh()
		{
			m_targetMoveSpeed = Vector3::Zero;
			m_positionMoveSpeed = Vector3::Zero;
			m_isRefresh = true;
		}
		*/

	private:
	//カメラ

		//カメラ
		Camera* m_camera = nullptr;
		
		//カメラのリフレッシュ
		bool m_isRefresh = true;

		//カメラの最大速度
		float m_maxMoveSpeed = 0.0f;

		//カメラの減衰率
		float m_targetDampingRate = 1.0f;
		float m_dampingRate = 1.0f;

		//コリジョン処理
		bool m_isEnableCollisionSolver = false;
		
		//スプリングカメラの何か
		float m_dampingRateVel = 0.0f;

	//カメラの座標
	
		//注視点
		Vector3 m_target = Vector3::Zero;

		//視点
		Vector3 m_position = Vector3::Zero;

		//注視点の移動速度
		Vector3 m_targetMoveSpeed = Vector3::Zero;

		//視点の移動速度
		Vector3 m_positionMoveSpeed = Vector3::Zero;

		
		
		

		//コリジョン処理が有効？
		CameraCollisionSolver m_cameraCollisionSolver;
	};
}

