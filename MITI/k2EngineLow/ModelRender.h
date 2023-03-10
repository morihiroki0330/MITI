#pragma once

#include "geometry/AABB.h"
//#include "graphics/ComputeAnimationVertexBuffer.h"

namespace nsK2EngineLow
{
	class RenderingEngine;

	class ModelRender : public IRender
	{
	public:
		//コンストラクタ・デストラクタ
		ModelRender();
		~ModelRender();

		//初期化
		void Init
		(
			const char* filePath,
			AnimationClip* animationClips = nullptr,
			int numAnimationClips = 0,
			EnModelUpAxis enModelUpAxis = enModelUpAxisZ,
			bool isShadowReciever = true,
			int maxInstance = 1,
			bool isFrontCullingOnDrawShadowMap = false
		);

	
	
		//更新
		void Update();

//描画処理

		//描画
		void Draw(RenderContext& rc);
		
		//描画処理
		void OnRender(RenderContext& rc) override;

//座標・回転・拡大

		//座標・回転・拡大設定
		void SetTRS(const Vector3& pos, const Quaternion& rotation, const Vector3& scale)
		{
			SetPosition(pos);
			SetRotation(rotation);
			SetScale(scale);
		}

		//座標設定
		void SetPosition(const Vector3& pos)
		{
			m_position = pos;
		}

		//回転設定
		void SetRotation(const Quaternion& rotation)
		{
			m_rotation = rotation;
		}

		//拡大設定
		void SetScale(const Vector3& scale)
		{
			m_scale = scale;
		}

//モデル

		//モデルの取得
		Model& GetModel()
		{
			return m_model;
		}

//アニメーション
		

		//アニメーションの再生
		//引数：（アニメーションクリップの番号）,（補間時間、単位：秒）
		void PlayAnimation(int animNo, float interpolareTime = 0.0f)
		{
			m_animation.Play(animNo, interpolareTime);
		}

		//アニメーションが再生中か？
		
		bool IsPlayAnimation() const
		{
			return m_animation.IsPlaying();
		}

		//アニメーションの再生速度設定
		
		void SetAnimationSpeed(const float animationSpeed)
		{

		}

		//ボーンを取得
		Bone* GetBone(int boneNo) const
		{

		}

		//ボーン検索
		int FindBoneID(const wchar_t* boneName)
		{

		}
	private:

		void UpdaterWorldMatrixInModes();
		
	private:
//モデル

		Model m_model;

		ModelInitData m_modelInitData;

//アニメーション

		//アニメーション
		Animation m_animation;

		//アニメーションクリップ
		AnimationClip* m_animationClips = nullptr;

		//アニメーションクリップの数
		int m_numAnimationClips = 0;

		//アニメーションの速度
		float m_animationSpeed = 1.0f;

		//アニメーションを更新するか？
		bool m_isUpdateAnimation = true;
		
		//FBXの上方向
		EnModelUpAxis m_enFbxUpAxis = enModelUpAxisZ;

//スケルトン

		Skeleton m_skeleton;

		Vector3 					m_position = Vector3::Zero;			// 座標。
		Quaternion	 				m_rotation = Quaternion::Identity;	// 回転。
		Vector3						m_scale = Vector3::One;				// 拡大率。

		bool						m_isEnableInstancingDraw = false;
	};
}

