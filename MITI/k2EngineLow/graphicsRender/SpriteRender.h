#pragma once
namespace nsK2EngineLow
{
	class RenderingEngine;

	class SpriteRender : public IRender
	{
	public:
		//������
		//�����F�i�t�@�C���p�X�A�摜�̉����A�摜�̏c���A�����������j
		void Init
		(
		const char* filePath, 
		const float w, 
		const float h, 
		AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans
		);

		//�X�V
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

		//�`��
		void Draw(RenderContext& rc);

	//���W�E��]�E�g��

		//���W�̐ݒ�
		void SetPosition(const Vector3& pos)
		{
			m_position = pos;
		}

		//���W�̎擾
		const Vector3& GetPosition() const
		{
			return m_position;
		}

		//��]�̐ݒ�
		void SetRotation(const Quaternion& rot)
		{
			m_rotation = rot;
		}

		//��]�̎擾
		const Quaternion& GetRotation() const
		{
			return m_rotation;
		}

		//�g�嗦�̐ݒ�
		void SetScale(const Vector3 scale)
		{
			m_scale = scale;
		}

		//���W�̎擾
		const Vector3& GetScale() const
		{
			return m_scale;
		}

		//�s�{�b�g�̐ݒ�
		void SetPivot(const Vector2& pivot)
		{
			m_pivot = pivot;
		}

		//�s�{�b�g�̎擾
		const Vector2& GetPivot() const
		{
			return m_pivot;
		}

		//��Z�J���[�̐ݒ�
		void SetMulColor(const Vector4& mulColor)
		{
			m_sprite.SetMulColor(mulColor);
		}

		//��Z�J���[�̎擾
		const Vector4& GetMulColor() const
		{
			return m_sprite.GetMulColor();
		}

		void OnRender2D(RenderContext& rc) override;

	private:
		//�X�v���C�g
		Sprite m_sprite;
		SpriteInitData m_spriteInitData;
		//���W
		Vector3 m_position = Vector3::Zero;

		//��]
		Quaternion m_rotation = Quaternion::Identity;

		//�g�嗦
		Vector3 m_scale = Vector3::One;

		//�s�{�b�g
		Vector2 m_pivot = Sprite::DEFAULT_PIVOT;


	};
}


