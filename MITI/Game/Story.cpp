#include "stdafx.h"
#include "Story.h"
#include "Game.h"
#include "Title.h"
#include "StoryFlag.h"
#include "Fade.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"
#include "Number_Storage.h"
#include "Bgm.h"
#define TextNormalSpeed 1.0
#define TextDoubleSpeed 3.0
Story::Story()
{
	
	InitTexture();
	BackChange();

	Word = new FontRender;
}
Story::~Story()
{
	DeleteGO(BGM);
}
bool Story::Start()
{
	game = FindGO<Game>("game");
	if (game != nullptr)
	{
		StoryNumber = game->GetLevel();
	}
	fade = FindGO<Fade>("fade");
	fade->StartFadeIn();
	StorySwitch();
	return true;
}

void Story::InitTexture()
{
	WhiteOutTexture.Init("Assets/sprite/white.DDS", ScreenWide,ScreenHeight);
	WhiteOutTexture.SetMulColor({ Red,Green,Blue,0.0f });

	BlackOutTexture.Init("Assets/sprite/black.DDS", ScreenWide,ScreenHeight);
	BlackOutTexture.SetMulColor({ Red,Green,Blue,0.0f });

	TriangleTexture.Init("Assets/sprite/Triangle2.DDS", 100.0f, 100.0f);
	TriangleTexture.SetPosition({ 6000.0f,-300-TriangleY,0.0f });
	TriangleTexture.Update();
}

void Story::TriangleMove()
{
	if (Word->GetMessageOkuriFlag() == false) 
	{
		
		switch (TriangleUpAndDown)
		{
		case 1:
			TriangleY += 0.5f;
			break;
		default:
			TriangleY -= 0.5f;
			break;
		}

		if (TriangleY > 10) 
		{
			TriangleUpAndDown = 0;
		}else if (TriangleY < 0) {
			TriangleUpAndDown = 1;
		}

		TriangleTexture.SetPosition({ 600.0f,200 - TriangleY,0.0f });
		TriangleTexture.SetScale({ 0.5f,0.5f,0.0f });
		TriangleTexture.Update();
		TextOkuri();
	}else {
		TriangleTexture.SetPosition({ 6000.0f,-300 - TriangleY,0.0f });
	}
}
void Story::TextOkuri()
{
	if (g_pad[0]->IsTrigger(enButtonA) && EndText == false)
	{

		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(S_TEXTBUTTON, BgmVolume, LoopNot);
		TextNumber++;
		PlaySe();
		TextUpdate();
	}
}
void Story::TextSpeed()
{
	if (BackgroundAlpha < NON)
	{
		Word->TextOkuriUpdate(g_gameTime->GetFrameDeltaTime() * TextSpeedMagnification);
		if (g_pad[0]->IsPress(enButtonX) == true) 
		{
			TextSpeedMagnification = TextDoubleSpeed;
		}else {
			TextSpeedMagnification = TextNormalSpeed;
		}
	}else{
		BackgroundAlpha -= 0.015f;
		BlackOutTexture.SetMulColor({ Red,Green,Blue,BackgroundAlpha });
		BlackOutTexture.Update();
	}
}
void Story::BackGroundFadeOut()
{
	if (EndText == true && BackgroundAlpha <= 1.0f) {
		if (Clear == true) {
			BackgroundAlpha += 0.02f;
		}
		else {
			BackgroundAlpha += 0.04f;
		}
	}
}
void Story::TextPostProcessing()
{
	if (EndText == true && BackgroundAlpha > 1.0f && Clear == false && fade->IsFade() == false)
	{
		if (game == NULL) 
		{
			game = NewGO<Game>(0, "game");
		}else {
		if (game->GetGameClearFlag()) {
			Clear = true;
		}else {
			game->CreateFlagSet(true);
		}
		}
		DeleteGO(this);
	}
}
void Story::EndPostProcessing()
{
	if (BackgroundAlpha > 1.0f && Clear == true && EndText == true)
	{
		Clear = false;
		NewGO<Title>(0, "title");
		game->Delete();
		DeleteGO(this);
	}

}
void Story::Update()
{
	TriangleMove();

	TextSpeed();

	BackGroundFadeOut();

	TextPostProcessing();

	EndPostProcessing();
	
	TriangleTexture.Update();
}

void Story::Render(RenderContext& rc)
{
	BackgroundTexture.Draw(rc);
	TriangleTexture.Draw(rc);
	BlackOutTexture.Draw(rc);
	WhiteOutTexture.Draw(rc);
	Word->Draw(rc);
}

void Story::PlaySe()
{
	if (StoryNumber == Chapter4 && TextNumber == 2)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(S_QUESTION, BgmVolume, LoopNot);
	}

	if (StoryNumber == Chapter7 && TextNumber == 1)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(B_TRAIN, BgmVolume, LoopNot);
	}

	if (StoryNumber == Chapter8 && TextNumber == 3)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(S_QUESTION, BgmVolume, LoopNot);
	}

	if (StoryNumber == Chapter9 && TextNumber == 4)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(B_HEART, BgmVolume, LoopNot);
	}
}

void Story::TextUpdate()
{
	int Len;
	if (StoryNumber == Chapter0 && Clear == false) 
	{
		switch (TextNumber)
		{
		case 1:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"目が覚めると、見覚えのない場所にいた。\n"
				"なぜここにいるのかは思い出せない。", TextIntervals);
			Word->SetNowLen(Len - 1);
			break;
		case 2:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"目が覚めると、見覚えのない場所にいた。\n"
				"なぜここにいるのかは思い出せない。\n"
				"さらに、記憶にも一部穴がある。", TextIntervals);
			Word->SetNowLen(Len-1);
			break;
		case 3:
			TextReset();
			Word->SetTextOkuri(L"・・・辺りを見渡す。"
				"どうやら遺跡のようだ。", TextIntervals);
			TextCreate();
			break;
		case 4:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"・・・辺りを見渡す。"
				"どうやら遺跡のようだ。\n"
				"探索すれば出られるかもしれない。", TextIntervals);
			Word->SetNowLen(Len - 1);
			break;
		case 5:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"・・・辺りを見渡す。"
				"どうやら遺跡のようだ。\n"
				"探索すれば出られるかもしれない。\n"
				"そう思い、先に進むことにした。", TextIntervals);
			Word->SetNowLen(Len - 1);
			break;
		default:
			TextReset();
			EndText = true;
			fade->StartFadeOut();
			break;
		}
	}
	
	if (StoryNumber == Chapter1)
	{
		switch (TextNumber)
		{
		case 1:
			TextReset();
			Word->SetTextOkuri(L"そして設置した鉄球を含め、\n次の層には持っていけないことが分かった。", TextIntervals);
			TextCreate();
			break;
		default:
			TextReset();
			EndText = true;
			fade->StartFadeOut();
			break;
		}
	}

	if (StoryNumber == Chapter2)
	{
		switch (TextNumber)
		{
		case 1:
			TextReset();
			Word->SetTextOkuri(L"ただし感圧板から離れると、\n発動したギミックは戻ってしまうようだ。", TextIntervals);
			TextCreate();
			break;
		default:
			TextReset();
			EndText = true;
			fade->StartFadeOut();
			break;
		}
	}

	if (StoryNumber == Chapter3) 
	{
		switch (TextNumber)
		{
		case 1:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"少しずつ階段に向かうことが難しくなってきた。\n"
				"そろそろ気を引き締めないといけないだろう。", TextIntervals);
			Word->SetNowLen(Len - 1);
			break;
		default:
			TextReset();
			EndText = true;
			fade->StartFadeOut();
			break;
		}
	}

	if (StoryNumber == Chapter4) 
	{
		switch (TextNumber)
		{
		case 1:
			TextReset();
			Word->SetTextOkuri(L"一部かすれているが\n"
				"「L・f・ and ・e・・h」と書かれているようだ。", TextIntervals);
			TextCreate();
			break;
		case 2:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"一部かすれているが\n"
				"「L・f・ and ・e・・h」と書かれているようだ。\n"
				"これはいったい何を意味するのだろうか。", 0.15f);
			Word->SetNowLen(Len - 1);
			break;
		default:
			TextReset();
			EndText = true;
			fade->StartFadeOut();
			break;
		}
	}

	if (StoryNumber == Chapter5) 
	{
		switch (TextNumber)
		{
		case 1:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"この層は今までより広くなっていた。\n"
				"そして、そこには今までの景色とは\n"
				"不釣り合いな草原が広がっていた。", TextIntervals);
			Word->SetNowLen(Len - 1);
			break;
		case 2:
			TextReset();
			Word->SetTextOkuri(L"私はこの場所に見覚えがあった。", TextIntervals);
			TextCreate();
			break;
		case 3:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"私はこの場所に見覚えがあった。\n"
				"ここは私がよく鳥を見に行く場所だ。", TextIntervals);
			Word->SetNowLen(Len - 1);
			break;
		case 4:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"私はこの場所に見覚えがあった。\n"
				"ここは私がよく鳥を見に行く場所だ。\n"
				"にしても、なぜ唐突に草原が出現したのか・・・。", TextIntervals);
			Word->SetNowLen(Len - 1);
			break;
		default:
			TextReset();
			EndText = true;
			fade->StartFadeOut();
			break;
		}
	}

	if (StoryNumber == Chapter6)
	{
		switch (TextNumber)
		{
		case 1:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"床に指輪とおもちゃが落ちている。\n"
				"どこかで見たことがある気はするが・・・", TextIntervals);
			Word->SetNowLen(Len - 1);
			break;
		case 2:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"床に指輪とおもちゃが落ちている。\n"
				"どこかで見たことがある気はするが・・・\n"
				"どこで見たのかは思い出せなかった。", TextIntervals);
			Word->SetNowLen(Len - 1);
			break;
		default:
			TextReset();
			EndText = true;
			fade->StartFadeOut();
			break;
		}
	}

	if (StoryNumber == Chapter7) 
	{
		switch (TextNumber)
		{
		case 1:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"唐突に電車が突っ込んでくる幻覚を見た。\n"
				"幻覚にしてはやけに現実味があった気がしたが・・・", TextIntervals);
			Word->SetNowLen(Len - 1);
			break;
		case 2:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"唐突に電車が突っ込んでくる幻覚を見た。\n"
				"幻覚にしてはやけに現実味があった気がしたが・・・\n"
				"これはいったい何を意味するのだろうか。", TextIntervals);
			Word->SetNowLen(Len - 1);
			break;
		default:
			TextReset();
			EndText = true;
			fade->StartFadeOut();
			break;
		}
	}

	if (StoryNumber == Chapter8) 
	{
		switch (TextNumber)
		{
		case 1:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"この遺跡はどこまで続いているのだろうか。\n"
				"そう考えていると、壁面に文字が\n彫られていることに気づいた。", TextIntervals);
			Word->SetNowLen(Len - 1);
			break;
		case 2:
			TextReset();
			Word->SetTextOkuri(L"そこには【memory】と彫られてあった。", TextIntervals);
			TextCreate();
			break;
		case 3:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"そこには【memory】と彫られてあった。\n"
				"少しずづ遺跡の真実に近づいている気がする。", TextIntervals);
			Word->SetNowLen(Len - 1);
			break;
		default:
			TextReset();
			EndText = true;
			fade->StartFadeOut();
			break;
		}
	}

	if (StoryNumber == Chapter9 && game->GetGameClearFlag()==false)
	{
		switch (TextNumber)
		{
		case 1:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"どうも気になる。\n"
				"ここまで見つけたものは全て\n私から抜け落ちた記憶に関係している。", TextIntervals);
			Word->SetNowLen(Len - 1);
			break;
		case 2:
			TextReset();
			Word->SetTextOkuri(L"そこから得られる結論は、\n"
				"「遺跡が記憶を映している」ということだろう。", TextIntervals);
			TextCreate();
			break;
		case 3:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"そこから得られる結論は、\n"
				"「遺跡が記憶を映している」ということだろう。\n"
				"ということは私は死にかけている・・・？", TextIntervals);
			Word->SetNowLen(Len - 1);
			break;
		case 4:
			TextReset();
			Word->SetTextOkuri(L"その時、心電図の音が鳴り始める。\n"
				"・・・急がねば。", TextIntervals);
			TextCreate();
			break;
		default:
			TextReset();
			EndText = true;
			fade->StartFadeOut();
			break;
		}
	}

	if (StoryNumber == Chapter9 && game->GetGameClearFlag() == true)
	{
			switch (TextNumber)
			{
			case 1:
				Len = Word->GetMaxLen();
				Word->SetTextOkuri(L"出口へ急ぐ。\n"
					"声が聞こえてくる。", TextIntervals);
				Word->SetNowLen(Len - 1);
				break;
			case 2:
				Len = Word->GetMaxLen();
				Word->SetTextOkuri(L"出口へ急ぐ。\n"
					"声が聞こえてくる。\n"
					"私の目覚めを待つ声が。", TextIntervals);
				Word->SetNowLen(Len - 1);
				break;
			case 3:
				TextReset();
				Word->SetTextOkuri(L"遺跡を抜ける。", TextIntervals);
				TextCreate();
				break;
			case 4:
				Len = Word->GetMaxLen();
				Word->SetTextOkuri(L"遺跡を抜ける。\n"
					"愛する人たちのもとに戻るために。", TextIntervals);
				Word->SetNowLen(Len - 1);
				break;
			case 5:
				Len = Word->GetMaxLen();
				Word->SetTextOkuri(L"遺跡を抜ける。\n"
					"愛する人たちのもとに戻るために。\n"
					"　　　　　　　　　　　　　　　　　　　～Fin～", 0.08f);
				Word->SetNowLen(Len - 1);
				break;
			default:
				TextReset();
				EndText = true;
				fade->StartFadeOut();
				break;
			}
		}
}

void Story::StorySwitch()
{
	if (StoryNumber == Chapter0 && Clear == false) 
	{
		BGM = NewGO<SoundSource>(0);
		BGM->SoundSet(S_QUESTION2, BgmVolume, Loop);
		BackgroundTexture.SetMulColor({ HalfRed,HalfGreen,HalfBlue,1.0f });
		Word->SetTextOkuri(L"目が覚めると、見覚えのない場所にいた。", TextIntervals);
		TextCreate();
	}

	if (StoryNumber == Chapter1)
	{
		BGM = NewGO<SoundSource>(0);
		BGM->SoundSet(S_QUESTION2, BgmVolume, Loop);
		BackgroundTexture.SetMulColor({ HalfRed,HalfGreen,HalfBlue,1.0f });
		Word->SetTextOkuri(L"この遺跡はどうやら鉄球を適切に配置することで\n"
			"階段に向かえるようだ。", TextIntervals);
		TextCreate();
	}

	//2章
	if (StoryNumber == Chapter2)
	{
		BackgroundTexture.Init("Assets/sprite/STORY/step.DDS", ScreenWide,ScreenHeight);
		BGM = NewGO<SoundSource>(0);
		BGM->SoundSet(S_QUESTION3, BgmVolume, Loop);
		BackgroundTexture.SetMulColor({ HalfRed,HalfGreen,HalfBlue,1.0f });
		Word->SetTextOkuri(L"感圧板は何かを出現させたり\n"
			"消したりすることができるらしい。", TextIntervals);
		TextCreate();
	}

	//3章
	if (StoryNumber == Chapter3)
	{
		BackgroundTexture.Init("Assets/sprite/STORY/step.DDS", ScreenWide,ScreenHeight);
		BGM = NewGO<SoundSource>(0);
		BGM->SoundSet(S_QUESTION3, BgmVolume, Loop);
		BackgroundTexture.SetMulColor({ HalfRed,HalfGreen,HalfBlue,1.0f });
		Word->SetTextOkuri(L"少しずつ階段に向かうことが難しくなってきた。", TextIntervals);
		TextCreate();
	}

	//4章
	if (StoryNumber == Chapter4)
	{
		BackgroundTexture.Init("Assets/sprite/STORY/sekihiwall.DDS", ScreenWide,ScreenHeight);
		BGM = NewGO<SoundSource>(0);
		BGM->SoundSet(B_STREET, BgmVolume, Loop);
		BackgroundTexture.SetMulColor({ HalfRed,HalfGreen,HalfBlue,1.0f });
		Word->SetTextOkuri(L"階段を上ってしばらくすると、\n古びた石碑が見えた。", TextIntervals);
		TextCreate();
		
	}

	//5章
	if (StoryNumber == Chapter5)
	{
		BackgroundTexture.Init("Assets/sprite/STORY/story_plain.DDS", ScreenWide,ScreenHeight);
		BGM = NewGO<SoundSource>(0);
		BGM->SoundSet(S_QUESTION2, BgmVolume, Loop);
		BackgroundTexture.SetMulColor({ HalfRed,HalfGreen,HalfBlue,1.0f });
		Word->SetTextOkuri(L"この層は今までより広くなっていた。", TextIntervals);
		TextCreate();
		
	}

	//6章
	if (StoryNumber == Chapter6)
	{
		BGM = NewGO<SoundSource>(0);
		BGM->SoundSet(S_QUESTION2, BgmVolume, Loop);
		BackgroundTexture.SetMulColor({ HalfRed,HalfGreen,HalfBlue,1.0f });
		Word->SetTextOkuri(L"床に指輪とおもちゃが落ちている。", TextIntervals);
		TextCreate();
		
	}

	//7章
	if (StoryNumber == Chapter7)
	{
		BackgroundTexture.Init("Assets/sprite/STORY/plathome_sunset.DDS", ScreenWide,ScreenHeight);
		BGM = NewGO<SoundSource>(0);
		BGM->SoundSet(B_DISTRUST, BgmVolume, Loop);
		BackgroundTexture.SetMulColor({ HalfRed,HalfGreen,HalfBlue,1.0f });
		Word->SetTextOkuri(L"唐突に電車が突っ込んでくる幻覚を見た。", TextIntervals);
		TextCreate();
		
	}

	//8章
	if (StoryNumber == Chapter8)
	{
		BackgroundTexture.Init("Assets/sprite/STORY/sekihiwall.DDS", ScreenWide,ScreenHeight);
		BGM = NewGO<SoundSource>(0);
		BGM->SoundSet(B_DESTINY, BgmVolume, Loop);
		BackgroundTexture.SetMulColor({ HalfRed,HalfGreen,HalfBlue,1.0f });
		Word->SetTextOkuri(L"この遺跡はどこまで続いているのだろうか。", TextIntervals);
		TextCreate();
		
	}

	//9章
	if (StoryNumber == Chapter9)
	{
		BGM = NewGO<SoundSource>(0);
		BGM->SoundSet(B_SAD, BgmVolume, Loop);
		BackgroundTexture.SetMulColor({ HalfRed,HalfGreen,HalfBlue,1.0f });
		Word->SetTextOkuri(L"どうも気になる。", TextIntervals);
		TextCreate();
		
	}

	if (Clear == true)
	{
		BGM = NewGO<SoundSource>(0);
		BGM->SoundSet(B_WELCOME, BgmVolume, Loop);
		//BackgroundTexture.SetMulColor({ 0.5f,0.5f,0.5f,1.0f });
		Word->SetTextOkuri(L"出口へ急ぐ。", TextIntervals);
		TextCreate();
		
	}
}
void Story::BackChange()
{
	switch (BackGroundNumber)
	{
	case Chapter0:
		BackgroundTexture.Init("Assets/sprite/STORY/story_00_B.DDS", ScreenWide,ScreenHeight);
		break;
	case Chapter1:
		BackgroundTexture.Init("Assets/sprite/STORY/step.DDS", ScreenWide,ScreenHeight);
		break;
	case Chapter2:
		BackgroundTexture.Init("Assets/sprite/STORY/step.DDS", ScreenWide,ScreenHeight);
		break;
	case Chapter3:
		BackgroundTexture.Init("Assets/sprite/STORY/step.DDS", ScreenWide,ScreenHeight);
		break;
	case Chapter4:
		BackgroundTexture.Init("Assets/sprite/STORY/sekihiwall.DDS", ScreenWide,ScreenHeight);
		break;
	case Chapter5:
		BackgroundTexture.Init("Assets/sprite/STORY/story_plain.DDS", ScreenWide,ScreenHeight);
		break;
	case Chapter6:
		BackgroundTexture.Init("Assets/sprite/STORY/whitewall.DDS", ScreenWide,ScreenHeight);
		break;
	case Chapter7:
		BackgroundTexture.Init("Assets/sprite/STORY/whitewall.DDS", ScreenWide,ScreenHeight);
		break;
	case Chapter8:
		BackgroundTexture.Init("Assets/sprite/STORY/whitewall.DDS", ScreenWide,ScreenHeight);
		break;
	case Chapter9:
		BackgroundTexture.Init("Assets/sprite/STORY/whitewall.DDS", ScreenWide,ScreenHeight);
		break;
	case Chapter10:
		BackgroundTexture.Init("Assets/sprite/STORY/whitewall.DDS", ScreenWide,ScreenHeight);
		break;
	}
}