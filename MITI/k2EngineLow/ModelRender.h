#pragma once

#include "geometry/AABB.h"
//#include "graphics/ComputeAnimationVertexBuffer.h"

namespace nsK2EngineLow
{
	class RenderingEngine;

	//ライトの構造体
	//※Vector型が連続して宣言される場合は間に【float pad(数字)】を入れる
	//共通ライトは【float pad_(数字)】を使用する
	struct AllLight
	{
		//ディレクションライト
		Vector3 DirectionLight_D = { 0.0f,0.0f,0.0f };//ライトの方向
		float pad1;
		Vector4 DirectionLight_C = { 0.0f,0.0f,0.0f,0.0f };//ライトのカラー


		//ポイントライト
		Vector3 Point_P = { 0.0f,0.0f,0.0f };//ライトの位置
		float pad2;
		Vector4 Point_C = { 0.0f,0.0f,0.0f,0.0f };//ライトのカラー
		float Point_R = 0.0f;//ライトの影響範囲


		//スポットライト
		Vector3 Spot_P = { 0.0f,0.0f,0.0f };//ライトの位置
		float pad3;
		Vector4 Spot_C = { 0.0f,0.0f,0.0f,0.0f };//ライトのカラー
		float Spot_R = 0.0f;;//影響範囲
		Vector3 Spot_D = { 0.0f,0.0f,0.0f };//ライトの方向
		float Spot_A = 0.0f;//ライトの角度


		//半球ライト
		Vector3 Ground_C = { 0.0f,0.0f,0.0f };//地面のカラー
		float pad4;
		Vector4 Sky_C;//ライトのカラー
		float pad5;
		Vector3 Ground_N = { 0.0f,0.0f,0.0f };//地面の法線
		float pad6;

		//共通ライト
		Vector3 eye_P = g_camera3D->GetPosition();//視点の位置
		float pad_1;
		Vector3 ambientlight = { 0.0f,0.0f,0.0f };//環境光
	};

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
			struct AllLight light,
			AnimationClip* animationClips = nullptr,
			int numAnimationClips = 0,
			EnModelUpAxis enModelUpAxis = enModelUpAxisZ
			
		);
	
		//アニメーションの初期化
		void InitAnimation
		(
		AnimationClip* animationClips,
		int numAnimationClips,
		EnModelUpAxis enModelUpAxis
		);

		void InitSkeleton(const char* filePath);

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
			return m_skeleton.GetBone(boneNo);
		}

		//ボーン検索
		int FindBoneID(const wchar_t* boneName)
		{
			return m_skeleton.FindBoneID(boneName);
		}

//ライト

		//ディレクションライトの設定
		void SetDirectionLight(const Vector3& Direction,const Vector4& Color)
		{
			m_light.DirectionLight_D = Direction;
			m_light.DirectionLight_D.Normalize();
			m_light.DirectionLight_C = Color;
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

//ライト
		AllLight m_light;
	};
}

