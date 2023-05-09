#include "stdafx.h"
#include "G_Kaidan.h"
#include "Player.h"
#include "Stage.h"
#include "Box.h"

G_Kaidan::G_Kaidan()
{
	Kaidan.Init("Assets/test/kaidan2.tkm", light);
	Kaidan.SetScale({ 1.0f,1.0f,2.5f });
}

G_Kaidan::~G_Kaidan()
{

}

void G_Kaidan::Update()
{
	clearflag = false;
	if (player == NULL)
	{
		//ƒvƒŒƒCƒ„[‚ğ’T‚·
		player = FindGO<Player>("player");
	}

	if (stage == NULL)
	{
		stage = FindGO<Stage>("stage");
	}

	if (box == NULL)
	{
		box = FindGO<Box>("box");
	}

	Kaidan.SetPosition(Kaidan_P);
	box->box_kaidan.SetPosition(Kaidan_P);
	//Kaidan.SetRotation(Kaidan_R);
	Kaidan.Update();
}

void G_Kaidan::Render(RenderContext& rc)
{
	Kaidan.Draw(rc);
}