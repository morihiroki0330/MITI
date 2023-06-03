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

		/// <summary>
		/// �e�L�X�g���艉�o
		/// SetText�̑���ɌĂ�ł�������
		/// </summary>
		/// <param name="text">�\������e�L�X�g</param>
		/// <param name="Interval">1�������Ƃ̃C���^�[�o��</param>
		/// <param name="TextOkuriSE_Flag">��������̌��ʉ����Đ����邩�ǂ���</param>
		void SetTextOkuri(const wchar_t* text, const float& Interval, const bool& TextOkuriSE_Flag = true);
		/// <summary>
		/// �e�L�X�g���������ꍇUpdate����Ă�łˁ�
		/// 
		/// �����ČĂяo�����~�߂邱�Ƃňꎞ�I�Ƀ��b�Z�[�W������~�߂邱�Ƃ��\
		/// </summary>
		/// <param name="addTime"> g_gameTime->GetFrameDeltaTime()�����Ă��������I </param>
		/// <returns>���̃t���[���ŕ����X�V�������ǂ��� true�Ȃ�X�V����</returns>
		bool TextOkuriUpdate(const float addTime);

		/// <summary>
		/// ���b�Z�[�W���蒆�Ȃ�true��Ԃ�
		/// </summary>
		const bool GetMessageOkuriFlag() {
			return m_okuriFlag;
		}
		/// <summary>
		/// ���݉������ڂ܂ŕ\�����Ă��邩��Ԃ�
		/// </summary>
		const int GetNowLen() {
			return m_textOkuri_NowLen;
		}
		/// <summary>
		/// �ő啶������Ԃ�
		/// </summary>
		const int GetMaxLen() {
			return m_textOkuri_Len;
		}

		void SetNowLen(int Len) {
			m_textOkuri_NowLen = Len;
		}

		void TextStockReset() {
			wchar_t nullT[1] = L"";
			for (int n = 0; n < 255; n++) {
				m_text_stock[n] = nullT[0];
			}
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

		wchar_t m_text_stock[256] = L"";			// �\���e�L�X�g
		float m_textOkuri_Interval = 0;				// �e�L�X�g����̃C���^�[�o���t���[��
		float m_textOkuri_Timer = 0;				// �e�L�X�g����^�C�}�[
		bool m_okuriFlag = false;					// ���b�Z�[�W���菈���̃t���O
		int m_textOkuri_Len = 0;					// �\���e�L�X�g�̕�����
		int m_textOkuri_NowLen = 0;					// ���݂̕�����
		bool m_textOkuriSE = true;					// �e�L�X�g���蒆��SE��炷�H
		const int TEXT_SE_NUMBER = 10;				// �e�L�X�g���艹�̓o�^�ԍ�
		const float VOL = 0.15f;
	};
}


