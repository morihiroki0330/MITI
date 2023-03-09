#pragma once

#include "geometry/AABB.h"

namespace nsK2EngineLow
{
	class RenderingEngine;

	class ModelRender : public IRender
	{
	public:
		ModelRender();
		~ModelRender();

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

		void Update();

		void Draw(RenderContext& rc);


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

		void OnRender(RenderContext& rc) override;

	private:

		void UpdaterWorldMatrixInModes();
		
	private:
		Model m_model;
		ModelInitData m_modelInitData;

		Vector3 					m_position = Vector3::Zero;			// 座標。
		Quaternion	 				m_rotation = Quaternion::Identity;	// 回転。
		Vector3						m_scale = Vector3::One;				// 拡大率。
		EnModelUpAxis				m_enFbxUpAxis = enModelUpAxisZ;

		bool						m_isEnableInstancingDraw = false;
	};
}

