#include "k2EngineLowPreCompile.h"
#include "FontRender.h"
namespace nsK2EngineLow
{
	void FontRender::Draw(RenderContext& rc)
	{
		if (m_text == nullptr)
		{
			return;
		}

		g_renderingEngine->InRenderObject(this);
	}

	bool FontRender::TextOkuriUpdate(const float addTime)
	{
		// メッセージ送りフラグがtrueなら更新処理を行う
		if (m_okuriFlag == true) {

			m_textOkuri_Timer += addTime;
			if (m_textOkuri_Interval <= m_textOkuri_Timer) {

				// レッツ更新！
				m_textOkuri_NowLen++;

				// 移植
				for (int n = 0; n < m_textOkuri_NowLen + 1; n++) {
					m_text[n] = m_text_stock[n];
				}

				// 効果音再生（ここで再生するのは本当は好ましくないけど）
				if (m_textOkuriSE) {
					SoundSource* text = NewGO<SoundSource>(0);
					text->Init(TEXT_SE_NUMBER);
					text->SetVolume(VOL);
					text->Play(false);
				}

				// 後始末
				m_textOkuri_Timer = 0.0f;
				if (m_textOkuri_NowLen >= m_textOkuri_Len) {
					m_okuriFlag = false;		// 終了
				}

				return true;
			}

			return false;
		}

	}

	void FontRender::SetTextOkuri(const wchar_t* text, const float& Interval, const bool& TextOkuriSE_Flag)
	{
		m_textOkuri_Len = (int)wcslen(text);	// 文字数を取得
		for (int n = 0; n < m_textOkuri_Len + 1; n++) {
			m_text_stock[n] = text[n];
		}

		// 設定
		m_textOkuri_Interval = Interval;
		m_textOkuri_Timer = 0;
		m_okuriFlag = true;
		m_textOkuri_NowLen = -1;
		m_textOkuriSE = TextOkuriSE_Flag;

		// テキスト送り音の登録
		if (m_textOkuriSE) {
			g_soundEngine->ResistWaveFileBank(10, "Assets/text_out.wav");
		}
	}

	void FontRender::OnRender2D(RenderContext& rc)
	{
		m_font.Begin(rc);
		m_font.Draw(m_text, Vector2(m_position.x, m_position.y), m_color, m_rotation, m_scale, m_pivot);
		m_font.End(rc);
	}
}