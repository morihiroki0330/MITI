#include "stdafx.h"
#include "Title.h"
#include "Story.h"
#include "Bgm.h"
#include "Fade.h"
#include "sound/SoundEngine.h"
Title::Title()
{
	InitTexture();
	InitSound();
}
Title::~Title()
{
	DeleteGO(P_Bgm);
}
bool Title::Start()
{
	P_Fade = FindGO<Fade>("fade");
	P_Fade->StartFadeIn();
	return true;
}

void Title::InitTexture()
{
	M_TitleTexture.Init("Assets/sprite/RoM_Title3.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_AbuttonTexture.Init("Assets/sprite/PRESS_A.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
}
void Title::InitSound()
{
	P_Bgm = NewGO<SoundSource>(0);
	P_Bgm->SoundSet(BGM_TITLE , S_SoundSetting.M_BgmVolume , S_SoundSetting.M_Loop);
}

void Title::ScreenChange()
{
	if (!P_Fade->IsFade() && M_ClassDeleteDecision)
	{
		NewGO<Story>(0, "story");
		DeleteGO(this);
	}else{
		if (g_pad[0]->IsTrigger(enButtonA) && !M_ClassDeleteDecision && !P_Fade->IsFade())
		{
			SoundSource* P_Se = NewGO<SoundSource>(0);
			P_Se->SoundSet(SE_TITLEBUTTON , S_SoundSetting.M_BgmVolume , S_SoundSetting.M_LoopNot);

			P_Fade->StartFadeOut();

			M_PressAbuttonDecision = true;
			M_ClassDeleteDecision = true;
		}
	}
}

void Title::Update()
{
	P_Fade->ButtonFade(M_AbuttonTexture, M_PressAbuttonDecision);
	ScreenChange();
}
void Title::Render(RenderContext& rc)
{
	M_TitleTexture.Draw(rc);
	M_AbuttonTexture.Draw(rc);
}