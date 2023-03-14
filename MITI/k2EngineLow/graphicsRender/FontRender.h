#pragma once

#include "IRender.h"

namespace nsK2EngineLow
{
	class FontRender : IRender
	{
	public:
		//�e�L�X�g�T�C�Y�̏���l
		static const int MAX_TEXT_SIZE = 256;
		
		//�f�X�g���N�^
		~FontRender()
		{

		}

	//����

		void SetText(const wchar_t* text)
		{
			swprintf_s(m_text, text);
		}

		const wchar_t* GetText() const
		{
			return m_text;
		}

	//���W�E�g��E�F�E��]�E�s�{�b�g

		//���W�̐ݒ�1
		void SetPosition(const Vector3& pos)
		{
			m_position = pos;
		}
		
		//���W�̐ݒ�2
		void SetPosition(float x,float y,float z)
		{
			SetPosition({ x,y,z });
		}

		//���W�̎擾
		const Vector3& GetPosition() const
		{
			return m_position;
		}

		//�傫���̐ݒ�
		void SetScale(const float& scale)
		{
			m_scale = scale;
		}

		//�傫���̎擾
		const float GetScale() const
		{
			return m_scale;
		}

		//�F�̐ݒ�1
		void SetColor(float r, float g, float b, float a)
		{
			SetColor({ r, g, b, a });
		}

		//�F�̐ݒ�2
		void SetColor(const Vector4& color)
		{
			m_color = color;
		}

		//�F�̎擾
		const Vector4& GetColor() const
		{
			return m_color;
		}

		//��]�̐ݒ�
		void SetRotation(const float rotation)
		{
			m_rotation = rotation;
		}

		//��]�̎擾
		const float GetRotation() const
		{
			return m_rotation;
		}

		//�s�{�b�g�̐ݒ�1
		void SetPivot(float x, float y)
		{
			SetPivot({ x, y });
		}
		
		//�s�{�b�g�̐ݒ�2
		void SetPivot(const Vector2& pivot)
		{
			m_pivot = pivot;
		}

		//�s�{�b�g�̎擾2
		const Vector2& GetPivot() const
		{
			return m_pivot;
		}

//�`��

		void Draw(RenderContext& rc);

		void OnRender2D(RenderContext& rc) override;

	private:

		//���W
		Vector3 m_position = Vector3::Zero;		

		//�傫��
		float	m_scale = 1.0f;			

		//�F
		Vector4 m_color = g_vec4White;

		//��]
		float   m_rotation = 0.0f;

		//�s�{�b�g
		Vector2 m_pivot = Sprite::DEFAULT_PIVOT;

		//����
		wchar_t m_text[MAX_TEXT_SIZE];

		//�t�H���g
		Font m_font;
	};
}


