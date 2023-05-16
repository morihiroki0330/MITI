#include "stdafx.h"
#include "G_Kaidan.h"
#include "Box.h"

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
	if (box == NULL)
	{
		box = FindGO<Box>("box");
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