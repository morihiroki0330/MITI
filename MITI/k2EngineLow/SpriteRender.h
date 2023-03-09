#pragma once
namespace nsK2EngineLow
{
	class RenderingEngine;

	class SpriteRender : public IRender
	{
	public:
		//初期化
		//引数：（ファイルパス、画像の横幅、画像の縦幅、半透明合成）
		void Init
		(
		const char* filePath, 
		const float w, 
		const float h, 
		AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans
		);

		//更新
		void Update()
		{
			m_sprite.Update
			(
				m_position,
				m_rotation,
				m_scale,
				m_pivot
			);
		}

		//描画
		void Draw(RenderContext& rc);

	//座標・回転・拡大

		//座標の設定
		void SetPosition(const Vector3& pos)
		{
			m_position = pos;
		}

		//座標の取得
		const Vector3& GetPosition() const
		{
			return m_position;
		}

		//回転の設定
		void SetRotation(const Quaternion& rot)
		{
			m_rotation = rot;
		}

		//回転の取得
		const Quaternion& GetRotation() const
		{
			return m_rotation;
		}

		//拡大率の設定
		void SetScale(const Vector3 scale)
		{
			m_scale = scale;
		}

		//座標の取得
		const Vector3& GetScale() const
		{
			return m_scale;
		}

		//ピボットの設定
		void SetPivot(const Vector2& pivot)
		{
			m_pivot = pivot;
		}

		//ピボットの取得
		const Vector2& GetPivot() const
		{
			return m_pivot;
		}

		//乗算カラーの設定
		void SetMulColor(const Vector4& mulColor)
		{
			m_sprite.SetMulColor(mulColor);
		}

		//乗算カラーの取得
		const Vector4& GetMulColor() const
		{
			return m_sprite.GetMulColor();
		}

		void OnRender2D(RenderContext& rc) override;

	private:
		//スプライト
		Sprite m_sprite;
		SpriteInitData m_spriteInitData;
		//座標
		Vector3 m_position = Vector3::Zero;

		//回転
		Quaternion m_rotation = Quaternion::Identity;

		//拡大率
		Vector3 m_scale = Vector3::One;

		//ピボット
		Vector2 m_pivot = Sprite::DEFAULT_PIVOT;


	};
}


