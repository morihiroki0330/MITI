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

		void SetPosition(float x, float y, float z)
		{
			SetPosition({ x, y, z });
		}

		void SetRotation(const Quaternion& rotation)
		{
			m_rotation = rotation;
		}


		void SetScale(const Vector3& scale)
		{
			m_scale = scale;
		}
		void SetScale(float x, float y, float z)
		{
			SetScale({ x, y, z });
		}

		void OnRender(RenderContext& rc);

	private:

		//void UpdaterWorldMatrixInModes();

	private:
		Model m_model;
		ModelInitData m_modelInitData;
		Model m_mainRenderModel;

		Vector3 					m_position = Vector3::Zero;			// ç¿ïWÅB
		Quaternion	 				m_rotation = Quaternion::Identity;	// âÒì]ÅB
		Vector3						m_scale = Vector3::One;				// ägëÂó¶ÅB
		EnModelUpAxis				m_enFbxUpAxis = enModelUpAxisZ;

	};
}

