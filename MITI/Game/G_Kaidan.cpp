#include "stdafx.h"
#include "G_Kaidan.h"
#include "Box.h"

G_Kaidan::G_Kaidan()
{
	Kaidan.Init("Assets/modelData/kaidan3.tkm", Light);
	Kaidan.SetScale({ 1.0f,1.0f,2.5f });
}

G_Kaidan::~G_Kaidan()
{

}

void G_Kaidan::Update()
{
	if (box == NULL)
	{
		box = FindGO<Box>("box");
	}

	Kaidan.SetPosition(Kaidan_P);
	box->box_kaidan.SetPosition(Kaidan_P);
	Kaidan.Update();
}

void G_Kaidan::Render(RenderContext& rc)
{
	Kaidan.Draw(rc);
}