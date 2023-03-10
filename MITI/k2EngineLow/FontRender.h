#pragma once

#include "IRender.h"

namespace nsK2EngineLow
{
	class FontRender : IRender
	{
	public:
		//テキストサイズの上限値
		static const int MAX_TEXT_SIZE = 256;
		
		//デストラクタ
		~FontRender()
		{

		}

	//文字

		void SetText(const wchar_t* text)
		{
			swprintf_s(m_text, text);
		}

		const wchar_t* GetText() const
		{
			return m_text;
		}

	//座標・拡大・色・回転・ピボット

		//座標の設定1
		void SetPosition(const Vector3& pos)
		{
			m_position = pos;
		}
		
		//座標の設定2
		void SetPosition(float x,float y,float z)
		{
			SetPosition({ x,y,z });
		}

		//座標の取得
		const Vector3& GetPosition() const
		{
			return m_position;
		}

		//大きさの設定
		void SetScale(const float& scale)
		{
			m_scale = scale;
		}

		//大きさの取得
		const float GetScale() const
		{
			return m_scale;
		}

		//色の設定1
		void SetColor(float r, float g, float b, float a)
		{
			SetColor({ r, g, b, a });
		}

		//色の設定2
		void SetColor(const Vector4& color)
		{
			m_color = color;
		}

		//色の取得
		const Vector4& GetColor() const
		{
			return m_color;
		}

		//回転の設定
		void SetRotation(const float rotation)
		{
			m_rotation = rotation;
		}

		//回転の取得
		const float GetRotation() const
		{
			return m_rotation;
		}

		//ピボットの設定1
		void SetPivot(float x, float y)
		{
			SetPivot({ x, y });
		}
		
		//ピボットの設定2
		void SetPivot(const Vector2& pivot)
		{
			m_pivot = pivot;
		}

		//ピボットの取得2
		const Vector2& GetPivot() const
		{
			return m_pivot;
		}

//描画

		void Draw(RenderContext& rc);

		void OnRender2D(RenderContext& rc) override;

	private:

		//座標
		Vector3 m_position = Vector3::Zero;		

		//大きさ
		float	m_scale = 1.0f;			

		//色
		Vector4 m_color = g_vec4White;

		//回転
		float   m_rotation = 0.0f;

		//ピボット
		Vector2 m_pivot = Sprite::DEFAULT_PIVOT;

		//文字
		wchar_t m_text[MAX_TEXT_SIZE];

		//フォント
		Font m_font;
	};
}


