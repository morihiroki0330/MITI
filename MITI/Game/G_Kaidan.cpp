#include "stdafx.h"
#include "G_Kaidan.h"
#include "Player.h"

G_Kaidan::G_Kaidan()
{
	Kaidan.Init("Assets/test/kaidan2.tkm", light);
	m_physicsStaticObjectpos.CreateFromModel(Kaidan.GetModel(), Kaidan.GetModel().GetWorldMatrix());
	//Kaidan_R.SetRotationDegY(90.0f);
}

G_Kaidan::~G_Kaidan()
{

}

void G_Kaidan::Update()
{

	if (player == NULL)
	{
		//ƒvƒŒƒCƒ„[‚ğ’T‚·
		player = FindGO<Player>("player");
	}
	else
	{
		if (player->player_P.x<Kaidan_P.x + 150 && player->player_P.x > Kaidan_P.x - 150
			&& player->player_P.z<Kaidan_P.z + 150 && player->player_P.z > Kaidan_P.z - 150)
		{
			clearflag = true;
		}
		else
		{
			clearflag = false;
		}
	}

	m_physicsStaticObjectpos.SetPosition(Kaidan_P);
	Kaidan.SetPosition(Kaidan_P);
	//Kaidan.SetRotation(Kaidan_R);
	Kaidan.Update();
}

void G_Kaidan::Render(RenderContext& rc)
{
	Kaidan.Draw(rc);
}