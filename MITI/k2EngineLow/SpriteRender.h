#pragma once
namespace nsK2EngineLow
{
	class RenderingEngine;
	class SpriteRender : public IRender
	{
	public:
		void Init
		(
		const char* filePath, 
		const float w, 
		const float h, 
		AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans
		);

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

		void Draw(RenderContext& rc);

//ç¿ïWÅEâÒì]ÅEägëÂ

		void SetPosition(const Vector3& pos)
		{
			m_position = pos;
		}

		const Vector3& GetPosition() const
		{
			return m_position;
		}

		void SetRotation(const Quaternion& rot)
		{
			m_rotation = rot;
		}

		const Quaternion& GetRotation() const
		{
			return m_rotation;
		}

		void SetScale(const Vector3 scale)
		{
			m_scale = scale;
		}

		const Vector3& GetScale() const
		{
			return m_scale;
		}

		void SetPivot(const Vector2& pivot)
		{
			m_pivot = pivot;
		}

		const Vector2& GetPivot() const
		{
			return m_pivot;
		}

		void SetMulColor(const Vector4& mulColor)
		{
			m_sprite.SetMulColor(mulColor);
		}

		const Vector4& GetMulColor() const
		{
			return m_sprite.GetMulColor();
		}

		void OnRender2D(RenderContext& rc) override;

	private:
		Sprite m_sprite;
		SpriteInitData m_spriteInitData;
		Vector3 m_position = Vector3::Zero;

		Quaternion m_rotation = Quaternion::Identity;

		Vector3 m_scale = Vector3::One;

		Vector2 m_pivot = Sprite::DEFAULT_PIVOT;
	};
}


