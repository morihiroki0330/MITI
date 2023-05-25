#include "stdafx.h"
#include "G_Kaidan.h"
#include "Box.h"
#include "Game.h"
#include "Stage.h"

G_Kaidan::G_Kaidan()
{
	Kaidan.Init("Assets/modelData/kaidan3.tkm", Light);
	Kaidan.SetScale({ 1.0f,1.0f,2.0f });
	Kaidan_R.SetRotationDegY(180.0f);
}

G_Kaidan::~G_Kaidan()
{

}

void G_Kaidan::Update()
{
	game = FindGO<Game>("game");
	stage = FindGO<Stage>("stage");
	if (box == NULL)
	{
		box = FindGO<Box>("box");
	}

	if (Set == true)
	{
		if (stage->StageOrder[game->Level] == 0)
		{
			Kaidan_R.SetRotationDegY(180.0f);
		}

		if (stage->StageOrder[game->Level] == 1)
		{
			Kaidan_R.SetRotationDegY(0.0f);
		}

		if (stage->StageOrder[game->Level] == 2)
		{
			Kaidan_R.SetRotationDegY(90.0f);
		}

		if (stage->StageOrder[game->Level] == 3)
		{
			Kaidan_R.SetRotationDegY(0.0f);
		}

		if (stage->StageOrder[game->Level] == 4)
		{
			Kaidan_R.SetRotationDegY(0.0f);
		}

		if (stage->StageOrder[game->Level] == 5)
		{
			Kaidan_R.SetRotationDegY(0.0f);
		}
		
		if (stage->StageOrder[game->Level] == 6)
		{
			Kaidan_R.SetRotationDegY(0.0f);
		}
		
		if (stage->StageOrder[game->Level] == 7)
		{
			Kaidan_R.SetRotationDegY(0.0f);
		}
		
		if (stage->StageOrder[game->Level] == 8)
		{
			Kaidan_R.SetRotationDegY(0.0f);
		}
		
		if (stage->StageOrder[game->Level] == 9)
		{
			Kaidan_R.SetRotationDegY(0.0f);
		}
		Kaidan.SetRotation(Kaidan_R);
		Kaidan.Update();
		Set = false;
	}


	Kaidan.SetRotation(Kaidan_R);
	Kaidan.SetPosition(Kaidan_P);
	box->box_kaidan.SetPosition(Kaidan_P);
	Kaidan.Update();
}

void G_Kaidan::Render(RenderContext& rc)
{
	Kaidan.Draw(rc);
}