#include "stdafx.h"
#include "Story.h"
#include "Game.h"
#include "Title.h"
#include "StoryFlag.h"
#include "Fade.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"
#include "Number_Storage.h"

Story::Story()
{
	game = FindGO<Game>("game");
	if (game != nullptr) {
		storyNum = game->GetLevel();
	}
	
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
	fade = FindGO<Fade>("fade");
	fade->StartFadeIn();
	StorySwitch();
	return true;
}

void Story::InitTexture()
{
	WhiteOutTexture.Init("Assets/sprite/white.DDS", 1920.0f, 1080.0f);
	WhiteOutTexture.SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	BlackOutTexture.Init("Assets/sprite/black.DDS", 1920.0f, 1080.0f);
	BlackOutTexture.SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	TriangleTexture.Init("Assets/sprite/Triangle2.DDS", 100.0f, 100.0f);
	TriangleTexture.SetPosition({ 6000.0f,-300-Y,0.0f });
	TriangleTexture.Update();
}

void Story::TriangleMove()
{
	if (Word->GetMessageOkuriFlag() == false) 
	{
		TriangleTexture.SetPosition({ 600.0f,200 - Y,0.0f });
		TriangleTexture.SetScale({ 0.5f,0.5f,0.0f });
		TriangleTexture.Update();
		switch (ud)
		{
		case 1:
			Y += 0.5f;
			break;
		default:
			Y -= 0.5f;
			break;
		}

		if (Y > 10) {
			ud = 0;
		}
		else if (Y < 0) {
			ud = 1;
		}
		TriangleTexture.Update();
		if (g_pad[0]->IsTrigger(enButtonA) && Endtext == false) {

			SoundSource* SE = NewGO<SoundSource>(0);
			SE->SoundSet(6, BgmVolume, LoopNot);
			out++;
			PlaySe();
			BackChange();
			BackgroundTexture.Update();
			TextUpdate();
		}

	}
	else {
		TriangleTexture.SetPosition({ 6000.0f,-300 - Y,NON });
	}
}
void Story::FastForwardText()
{
	//Xボタン押下で早送り
	if (alpha < NON)
	{
		Word->TextOkuriUpdate(g_gameTime->GetFrameDeltaTime() * mul);
		if (g_pad[0]->IsPress(enButtonX) == true) 
		{
			mul = 3.0f;
		}else {
			mul = 1.0f;
		}
	}else{
		BlackOutTexture.SetMulColor({ 1.0f,1.0f,1.0f,alpha });
		alpha -= 0.015f;
		BlackOutTexture.Update();
	}
}
void Story::Update()
{
	TriangleMove();
	FastForwardText();

	//フェードアウト処理
	if (Endtext == true && alpha <= 1.0f) {
		if (Clear == true) {
			alpha += 0.02f;
		}
		else {
			alpha += 0.04f;
		}
	}

	//テキスト終了処理
	if (Endtext == true && alpha > 1.0f && Clear == false && fade->IsFade() == false) {
		if (game == NULL) {
			game = NewGO<Game>(0, "game");
		}
		else if (storyNum == 9) {
			Clear = true;
			game->CreateFlagSet(true);
		}
		else {
			game->CreateFlagSet(true);
		}
		
		DeleteGO(this);
	}

	//エンディング終了処理
	else if (alpha>1.0f&& Clear == true&& Endtext == true){
		Clear = false;
		NewGO<Title>(0, "title");
		DeleteGO(this);
	}

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
	if (storyNum == 4 && out == 2) {
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(9, BgmVolume, LoopNot);
	}

	if (storyNum == 7 && out == 1) {
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(13, BgmVolume, LoopNot);
	}

	if (storyNum == 8 && out == 3) {
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(9, BgmVolume, LoopNot);
	}

	if (storyNum == 9 && out == 4) {
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(19, BgmVolume, LoopNot);
	}
}

void Story::TextUpdate()
{
	int Len;

	//始まり。
	if (storyNum == 0 && Clear == false) {
		switch (out)
		{
		case 1:
			//最大文字列を取得
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"目が覚めると、見覚えのない場所にいた。\n"
				"なぜここにいるのかは思い出せない。", HIGH);
			Word->SetNowLen(Len - 1);
			break;
		case 2:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"目が覚めると、見覚えのない場所にいた。\n"
				"なぜここにいるのかは思い出せない。\n"
				"さらに、記憶にも一部穴がある。", HIGH);
			Word->SetNowLen(Len-1);
			break;
		case 3:
			TextReset();
			Word->SetTextOkuri(L"・・・辺りを見渡す。"
				"どうやら遺跡のようだ。", HIGH);
			TextCreate();
			break;
		case 4:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"・・・辺りを見渡す。"
				"どうやら遺跡のようだ。\n"
				"探索すれば出られるかもしれない。", HIGH);
			Word->SetNowLen(Len - 1);
			break;
		case 5:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"・・・辺りを見渡す。"
				"どうやら遺跡のようだ。\n"
				"探索すれば出られるかもしれない。\n"
				"そう思い、先に進むことにした。", HIGH);
			Word->SetNowLen(Len - 1);
			break;
		default:
			TextReset();
			Endtext = true;
			fade->StartFadeOut();
			break;
		}
	}
	
	//1。
	if (storyNum == 1) {
		switch (out)
		{
		case 1:
			TextReset();
			Word->SetTextOkuri(L"そして設置した鉄球を含め、\n次の層には持っていけないことが分かった。", HIGH);
			TextCreate();
			break;
		default:
			TextReset();
			Endtext = true;
			fade->StartFadeOut();
			break;
		}
	}

	//2
	if (storyNum == 2) {
		switch (out)
		{
		case 1:
			TextReset();
			Word->SetTextOkuri(L"ただし感圧板から離れると、\n発動したギミックは戻ってしまうようだ。", HIGH);
			TextCreate();
			break;
		default:
			TextReset();
			Endtext = true;
			fade->StartFadeOut();
			break;
		}
	}

	//3
	if (storyNum == 3) {
		switch (out)
		{
		case 1:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"少しずつ階段に向かうことが難しくなってきた。\n"
				"そろそろ気を引き締めないといけないだろう。", HIGH);
			Word->SetNowLen(Len - 1);
			break;
		default:
			TextReset();
			Endtext = true;
			fade->StartFadeOut();
			break;
		}
	}

	//4
	if (storyNum == 4) {
		switch (out)
		{
		case 1:
			TextReset();
			Word->SetTextOkuri(L"一部かすれているが\n"
				"「L・f・ and ・e・・h」と書かれているようだ。", HIGH);
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
			Endtext = true;
			fade->StartFadeOut();
			break;
		}
	}

	//5
	if (storyNum == 5) {
		switch (out)
		{
		case 1:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"この層は今までより広くなっていた。\n"
				"そして、そこには今までの景色とは\n"
				"不釣り合いな草原が広がっていた。", HIGH);
			Word->SetNowLen(Len - 1);
			break;
		case 2:
			TextReset();
			Word->SetTextOkuri(L"私はこの場所に見覚えがあった。", HIGH);
			TextCreate();
			break;
		case 3:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"私はこの場所に見覚えがあった。\n"
				"ここは私がよく鳥を見に行く場所だ。", HIGH);
			Word->SetNowLen(Len - 1);
			break;
		case 4:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"私はこの場所に見覚えがあった。\n"
				"ここは私がよく鳥を見に行く場所だ。\n"
				"にしても、なぜ唐突に草原が出現したのか・・・。", HIGH);
			Word->SetNowLen(Len - 1);
			break;
		default:
			TextReset();
			Endtext = true;
			fade->StartFadeOut();
			break;
		}
	}

	//6
	if (storyNum == 6) {
		switch (out)
		{
		case 1:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"床に指輪とおもちゃが落ちている。\n"
				"どこかで見たことがある気はするが・・・", HIGH);
			Word->SetNowLen(Len - 1);
			break;
		case 2:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"床に指輪とおもちゃが落ちている。\n"
				"どこかで見たことがある気はするが・・・\n"
				"どこで見たのかは思い出せなかった。", HIGH);
			Word->SetNowLen(Len - 1);
			break;
		default:
			TextReset();
			Endtext = true;
			fade->StartFadeOut();
			break;
		}
	}

	//7
	if (storyNum == 7) {
		switch (out)
		{
		case 1:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"唐突に電車が突っ込んでくる幻覚を見た。\n"
				"幻覚にしてはやけに現実味があった気がしたが・・・", HIGH);
			Word->SetNowLen(Len - 1);
			break;
		case 2:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"唐突に電車が突っ込んでくる幻覚を見た。\n"
				"幻覚にしてはやけに現実味があった気がしたが・・・\n"
				"これはいったい何を意味するのだろうか。", HIGH);
			Word->SetNowLen(Len - 1);
			break;
		default:
			TextReset();
			Endtext = true;
			fade->StartFadeOut();
			break;
		}
	}

	//8
	if (storyNum == 8) {
		switch (out)
		{
		case 1:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"この遺跡はどこまで続いているのだろうか。\n"
				"そう考えていると、壁面に文字が\n彫られていることに気づいた。", HIGH);
			Word->SetNowLen(Len - 1);
			break;
		case 2:
			TextReset();
			Word->SetTextOkuri(L"そこには【memory】と彫られてあった。", HIGH);
			TextCreate();
			break;
		case 3:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"そこには【memory】と彫られてあった。\n"
				"少しずづ遺跡の真実に近づいている気がする。", HIGH);
			Word->SetNowLen(Len - 1);
			break;
		default:
			TextReset();
			Endtext = true;
			fade->StartFadeOut();
			break;
		}
	}

	//9
	if (storyNum == 9) {
		switch (out)
		{
		case 1:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"どうも気になる。\n"
				"ここまで見つけたものは全て\n私から抜け落ちた記憶に関係している。", HIGH);
			Word->SetNowLen(Len - 1);
			break;
		case 2:
			TextReset();
			Word->SetTextOkuri(L"そこから得られる結論は、\n"
				"「遺跡が記憶を映している」ということだろう。", HIGH);
			TextCreate();
			break;
		case 3:
			Len = Word->GetMaxLen();
			Word->SetTextOkuri(L"そこから得られる結論は、\n"
				"「遺跡が記憶を映している」ということだろう。\n"
				"ということは私は死にかけている・・・？", HIGH);
			Word->SetNowLen(Len - 1);
			break;
		case 4:
			TextReset();
			Word->SetTextOkuri(L"その時、心電図の音が鳴り始める。\n"
				"・・・急がねば。", HIGH);
			TextCreate();
			break;
		default:
			TextReset();
			Endtext = true;
			fade->StartFadeOut();
			break;
		}
	}

	//10
	if (Clear==true) {
			switch (out)
			{
			case 1:
				Len = Word->GetMaxLen();
				Word->SetTextOkuri(L"出口へ急ぐ。\n"
					"声が聞こえてくる。", HIGH);
				Word->SetNowLen(Len - 1);
				break;
			case 2:
				Len = Word->GetMaxLen();
				Word->SetTextOkuri(L"出口へ急ぐ。\n"
					"声が聞こえてくる。\n"
					"私の目覚めを待つ声が。", HIGH);
				Word->SetNowLen(Len - 1);
				break;
			case 3:
				TextReset();
				Word->SetTextOkuri(L"遺跡を抜ける。", HIGH);
				TextCreate();
				break;
			case 4:
				Len = Word->GetMaxLen();
				Word->SetTextOkuri(L"遺跡を抜ける。\n"
					"愛する人たちのもとに戻るために。", HIGH);
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
				Endtext = true;
				fade->StartFadeOut();
				break;
			}
		}
}

//ストーリーの面ごとの変更処理(最初の言葉のみ)
void Story::StorySwitch()
{
	//序章(始まり)
	if (storyNum == 0 && Clear == false) {
		BGM = NewGO<SoundSource>(0);
		BGM->SoundSet(20, 0.6, true);
		BackgroundTexture.SetMulColor({ 0.5f,0.5f,0.5f,1.0f });
		Word->SetTextOkuri(L"目が覚めると、見覚えのない場所にいた。", HIGH);
		TextCreate();
	}

	//1章
	if (storyNum == 1) {
		BGM = NewGO<SoundSource>(0);
		BGM->Init(20);
		BGM->SetVolume(0.6f);
		BGM->Play(true);
		BackgroundTexture.SetMulColor({ 0.5f,0.5f,0.5f,1.0f });
		Word->SetTextOkuri(L"この遺跡はどうやら鉄球を適切に配置することで\n"
			"階段に向かえるようだ。", HIGH);
		TextCreate();
	}

	//2章
	if (storyNum == 2) {
		BackgroundTexture.Init("Assets/sprite/STORY/step.DDS", 1920.0f, 1080.0f);
		BGM = NewGO<SoundSource>(0);
		BGM->Init(21);
		BGM->SetVolume(0.6f);
		BGM->Play(true);
		BackgroundTexture.SetMulColor({ 0.5f,0.5f,0.5f,1.0f });
		Word->SetTextOkuri(L"感圧板は何かを出現させたり\n"
			"消したりすることができるらしい。", HIGH);
		TextCreate();
	}

	//3章
	if (storyNum == 3) {
		BackgroundTexture.Init("Assets/sprite/STORY/step.DDS", 1920.0f, 1080.0f);
		BGM = NewGO<SoundSource>(0);
		BGM->Init(21);
		BGM->SetVolume(0.6f);
		BGM->Play(true);
		BackgroundTexture.SetMulColor({ 0.5f,0.5f,0.5f,1.0f });
		Word->SetTextOkuri(L"少しずつ階段に向かうことが難しくなってきた。", HIGH);
		TextCreate();
	}

	//4章
	if (storyNum == 4) {
		BackgroundTexture.Init("Assets/sprite/STORY/sekihiwall.DDS", 1920.0f, 1080.0f);
		BGM = NewGO<SoundSource>(0);
		BGM->Init(24);
		BGM->SetVolume(0.6f);
		BGM->Play(true);
		BackgroundTexture.SetMulColor({ 0.5f,0.5f,0.5f,1.0f });
		Word->SetTextOkuri(L"階段を上ってしばらくすると、\n古びた石碑が見えた。", HIGH);
		TextCreate();
		
	}

	//5章
	if (storyNum == 5) {
		BackgroundTexture.Init("Assets/sprite/STORY/story_plain.DDS", 1920.0f, 1080.0f);
		BGM = NewGO<SoundSource>(0);
		BGM->Init(20);
		BGM->SetVolume(0.6f);
		BGM->Play(true);
		BackgroundTexture.SetMulColor({ 0.5f,0.5f,0.5f,1.0f });
		Word->SetTextOkuri(L"この層は今までより広くなっていた。", HIGH);
		TextCreate();
		
	}

	//6章
	if (storyNum == 6) {
		BGM = NewGO<SoundSource>(0);
		BGM->Init(20);
		BGM->SetVolume(0.6f);
		BGM->Play(true);
		BackgroundTexture.SetMulColor({ 0.5f,0.5f,0.5f,1.0f });
		Word->SetTextOkuri(L"床に指輪とおもちゃが落ちている。", HIGH);
		TextCreate();
		
	}

	//7章
	if (storyNum == 7) {
		BackgroundTexture.Init("Assets/sprite/STORY/plathome_sunset.DDS", 1920.0f, 1080.0f);
		BGM = NewGO<SoundSource>(0);
		BGM->Init(32);
		BGM->SetVolume(0.6f);
		BGM->Play(true);
		BackgroundTexture.SetMulColor({ 0.5f,0.5f,0.5f,1.0f });
		Word->SetTextOkuri(L"唐突に電車が突っ込んでくる幻覚を見た。", HIGH);
		TextCreate();
		
	}

	//8章
	if (storyNum == 8) {
		BackgroundTexture.Init("Assets/sprite/STORY/sekihiwall.DDS", 1920.0f, 1080.0f);
		BGM = NewGO<SoundSource>(0);
		BGM->Init(28);
		BGM->SetVolume(0.8f);
		BGM->Play(true);
		BackgroundTexture.SetMulColor({ 0.5f,0.5f,0.5f,1.0f });
		Word->SetTextOkuri(L"この遺跡はどこまで続いているのだろうか。", HIGH);
		TextCreate();
		
	}

	//9章
	if (storyNum == 9) {
		BGM = NewGO<SoundSource>(0);
		BGM->Init(25);
		BGM->SetVolume(0.8f);
		BGM->Play(true);
		BackgroundTexture.SetMulColor({ 0.5f,0.5f,0.5f,1.0f });
		Word->SetTextOkuri(L"どうも気になる。", HIGH);
		TextCreate();
		
	}

	//10章/End
	if (Clear == true) {
		BGM = NewGO<SoundSource>(0);
		BGM->Init(30);
		BGM->SetVolume(0.6f);
		BGM->Play(true);
		//BackgroundTexture.SetMulColor({ 0.5f,0.5f,0.5f,1.0f });
		Word->SetTextOkuri(L"出口へ急ぐ。", HIGH);
		TextCreate();
		
	}
}

//背景変更関数(と言っても最初しか変えられない)
void Story::BackChange()
{
	switch (BackNumber)
	{
		//0層
	case 0:
		BackgroundTexture.Init("Assets/sprite/STORY/story_00_B.DDS", 1920.0f, 1080.0f);
		break;
		//1層
	case 1:
		BackgroundTexture.Init("Assets/sprite/STORY/step.DDS", 1920.0f, 1080.0f);
		break;
		//2層
	case 2:
		BackgroundTexture.Init("Assets/sprite/STORY/step.DDS", 1920.0f, 1080.0f);
		break;
		//3層
	case 3:
		BackgroundTexture.Init("Assets/sprite/STORY/step.DDS", 1920.0f, 1080.0f);
		break;
		//4層
	case 4:
		BackgroundTexture.Init("Assets/sprite/STORY/sekihiwall.DDS", 1920.0f, 1080.0f);
		break;
		//5層
	case 5:
		BackgroundTexture.Init("Assets/sprite/STORY/story_plain.DDS", 1920.0f, 1080.0f);
		break;
		//6層
	case 6:
		BackgroundTexture.Init("Assets/sprite/STORY/whitewall.DDS", 1920.0f, 1080.0f);
		break;
		//7層
	case 7:
		BackgroundTexture.Init("Assets/sprite/STORY/whitewall.DDS", 1920.0f, 1080.0f);
		break;
		//8層
	case 8:
		BackgroundTexture.Init("Assets/sprite/STORY/whitewall.DDS", 1920.0f, 1080.0f);
		break;
		//9層
	case 9:
		BackgroundTexture.Init("Assets/sprite/STORY/whitewall.DDS", 1920.0f, 1080.0f);
		break;
		//10層(End)
	case 10:
		BackgroundTexture.Init("Assets/sprite/STORY/whitewall.DDS", 1920.0f, 1080.0f);
		break;
	}
}