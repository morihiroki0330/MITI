#pragma once

#include "geometry/AABB.h"

namespace nsK2EngineLow
{
	class RenderingEngine;

	struct AllLight
	{
		Vector3 DirectionLight_D = { 0.0f,0.0f,0.0f };
		float pad1;
		Vector4 DirectionLight_C = { 0.0f,0.0f,0.0f,0.0f };

		Vector3 Point_P = { 0.0f,0.0f,0.0f };
		float pad2;
		Vector4 Point_C = { 0.0f,0.0f,0.0f,0.0f };
		float Point_R = 0.0f;

		Vector3 Spot_P = { 0.0f,0.0f,0.0f };
		float pad3;
		Vector4 Spot_C = { 0.0f,0.0f,0.0f,0.0f };
		float Spot_R = 0.0f;
		Vector3 Spot_D = { 0.0f,0.0f,0.0f };
		float Spot_A = 0.0f;
		Vector3 Ground_C = { 0.0f,0.0f,0.0f };
		float pad4;
		Vector4 Sky_C;
		float pad5;
		Vector3 Ground_N = { 0.0f,0.0f,0.0f };
		float pad6;

		
		Vector3 eye_P = g_camera3D->GetPosition();
		float pad_1;
		Vector3 ambientlight = { 0.0f,0.0f,0.0f };
	};

	class ModelRender : public IRender
	{
	public:
		void Init
		(
			const char* filePath,
			struct AllLight light,
			AnimationClip* animationClips = nullptr,
			int numAnimationClips = 0,
			EnModelUpAxis enModelUpAxis = enModelUpAxisZ
		);

		void Update();

//描画処理

		void Draw(RenderContext& rc);
		
		void OnRender(RenderContext& rc) override;

//座標・回転・拡大

		void SetTRS(const Vector3& pos, const Quaternion& rotation, const Vector3& scale)
		{
			SetPosition(pos);
			SetRotation(rotation);
			SetScale(scale);
		}

		void SetPosition(const Vector3& pos)
		{
			m_position = pos;
		}

		void SetRotation(const Quaternion& rotation)
		{
			m_rotation = rotation;
		}

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
		
		void InitAnimation
		(
			AnimationClip* animationClips,
			int numAnimationClips,
			EnModelUpAxis enModelUpAxis
		);

		void InitSkeleton(const char* filePath);

		void PlayAnimation(int animNo, float interpolareTime = 0.0f)
		{
			m_animation.Play(animNo, interpolareTime);
		}

		bool IsPlayAnimation() const
		{
			return m_animation.IsPlaying();
		}

		void SetAnimationSpeed(const float animationSpeed)
		{

		}

		Bone* GetBone(int boneNo) const
		{
			return m_skeleton.GetBone(boneNo);
		}

		int FindBoneID(const wchar_t* boneName)
		{
			return m_skeleton.FindBoneID(boneName);
		}

//ライト

		void SetDirectionLight(const Vector3& Direction,const Vector4& Color)
		{
			m_light.DirectionLight_D = Direction;
			m_light.DirectionLight_D.Normalize();
			m_light.DirectionLight_C = Color;
		}

		void SetPositionLight(const Vector4& Color , const Vector3& Position , const float Range)
		{
			m_light.Point_P = Position;
			m_light.Point_C = Color;
			m_light.Point_R = Range;
		}

		void SetSpotLight(const Vector3& Direction , const Vector4& Color , const Vector3 Position , const float Range , const float Angle)
		{
			m_light.Spot_D = Direction;
			m_light.Spot_D.Normalize();
			m_light.Spot_C = Color;
			m_light.Spot_P = Position;
			m_light.Spot_R = Range;
			m_light.Spot_A = Angle;
		}

		void SetCommonLight(const Vector3& Color)
		{
			m_light.ambientlight = Color;
		}

	private:

		void UpdaterWorldMatrixInModes();
		
//モデル

		Model m_model;

		ModelInitData m_modelInitData;

//アニメーション

		Animation m_animation;

		AnimationClip* m_animationClips = nullptr;

		int m_numAnimationClips = 0;

		float m_animationSpeed = 1.0f;

		bool m_isUpdateAnimation = true;
		
		EnModelUpAxis m_enFbxUpAxis = enModelUpAxisZ;

//スケルトン

		Skeleton m_skeleton;

		Vector3 m_position = Vector3::Zero;			
		Quaternion m_rotation = Quaternion::Identity;	
		Vector3 m_scale = Vector3::One;				

		bool m_isEnableInstancingDraw = false;

//ライト
		AllLight m_light;
	};
}

