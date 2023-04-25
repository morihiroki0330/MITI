#include "stdafx.h"
#include "UI.h"

UI::UI()
{
	A[0].Init("Assets/UI/A(C)-0.DDS", 128.0f, 128.0f);
	A[0].SetPosition({ 550.0f,-400.0f,0.0f });

	A[1].Init("Assets/UI/A(C)-1.DDS", 128.0f, 128.0f);
	A[1].SetPosition({ 550.0f,-400.0f,0.0f });

	B[0].Init("Assets/UI/B(C)-0.DDS", 128.0f, 128.0f); 
	B[0].SetPosition({ 670.0f,-400.0f,0.0f });

	B[1].Init("Assets/UI/B(C)-1.DDS", 128.0f, 128.0f); 
	B[1].SetPosition({ 670.0f,-400.0f,0.0f });

	Non.Init("Assets/UI/Controller-Non.DDS", 256.0f, 256.0f);
	Non.SetPosition({ -620.0f,-300.0f,0.0f });
	
	Up.Init("Assets/UI/Controller-Up.DDS", 256.0f, 256.0f);
	Up.SetPosition({ -620.0f,-300.0f,0.0f });

	Down.Init("Assets/UI/Controller-Down.DDS", 256.0f, 256.0f);

	Left.Init("Assets/UI/Controller-Left.DDS", 256.0f, 256.0f);

	Right.Init("Assets/UI/Controller-Right.DDS", 256.0f, 256.0f);



	Iron[0].Init("Assets/UI/Iron-Non.DDS",128.0f, 512.0f);
	Iron[0].SetPosition({ 600.0f,-10.0f,0.0f });
}

UI::~UI()
{

}

void UI::Update()
{
	A[0].Update();
	B[0].Update();
	Non.Update();
	Iron[0].Update();
}

void UI::Render(RenderContext& rc)
{
	A[0].Draw(rc);
	B[0].Draw(rc);
	Non.Draw(rc);
	Iron[0].Draw(rc);
}