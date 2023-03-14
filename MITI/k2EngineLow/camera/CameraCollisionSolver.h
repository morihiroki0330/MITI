#pragma once
namespace nsK2EngineLow
{
	class CameraCollisionSolver : public Noncopyable
	{
	public:
	//コンストラクタ・デストラクタ・初期化・更新・描画
	
		//コンストラクタ
		CameraCollisionSolver();

		//デストラクタ
		~CameraCollisionSolver();

		//初期化
		void Init(float radius);

		//コリジョン解決の実行
		bool Execute
		(
			Vector3& result,
			const Vector3& position,
			const Vector3& target
		);
	private:
		//コライダー
		SphereCollider m_collider;

		//半径
		float m_radius = 0.0f;

		//初期化済みのフラグ
		bool m_isInited = false;
	};
}

