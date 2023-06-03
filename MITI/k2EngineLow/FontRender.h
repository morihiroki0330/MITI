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

		/// <summary>
		/// テキスト送り演出
		/// SetTextの代わりに呼んでください
		/// </summary>
		/// <param name="text">表示するテキスト</param>
		/// <param name="Interval">1文字ごとのインターバル</param>
		/// <param name="TextOkuriSE_Flag">文字送りの効果音を再生するかどうか</param>
		void SetTextOkuri(const wchar_t* text, const float& Interval, const bool& TextOkuriSE_Flag = true);
		/// <summary>
		/// テキスト送りをする場合Updateから呼んでね☆
		/// 
		/// あえて呼び出しを止めることで一時的にメッセージ送りを止めることも可能
		/// </summary>
		/// <param name="addTime"> g_gameTime->GetFrameDeltaTime()を入れてください！ </param>
		/// <returns>このフレームで文字更新したかどうか trueなら更新した</returns>
		bool TextOkuriUpdate(const float addTime);

		/// <summary>
		/// メッセージ送り中ならtrueを返す
		/// </summary>
		const bool GetMessageOkuriFlag() {
			return m_okuriFlag;
		}
		/// <summary>
		/// 現在何文字目まで表示しているかを返す
		/// </summary>
		const int GetNowLen() {
			return m_textOkuri_NowLen;
		}
		/// <summary>
		/// 最大文字数を返す
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

		wchar_t m_text_stock[256] = L"";			// 予備テキスト
		float m_textOkuri_Interval = 0;				// テキスト送りのインターバルフレーム
		float m_textOkuri_Timer = 0;				// テキスト送りタイマー
		bool m_okuriFlag = false;					// メッセージ送り処理のフラグ
		int m_textOkuri_Len = 0;					// 予備テキストの文字数
		int m_textOkuri_NowLen = 0;					// 現在の文字数
		bool m_textOkuriSE = true;					// テキスト送り中にSEを鳴らす？
		const int TEXT_SE_NUMBER = 10;				// テキスト送り音の登録番号
		const float VOL = 0.15f;
	};
}


