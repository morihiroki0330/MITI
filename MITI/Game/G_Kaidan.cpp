#include "stdafx.h"
#include "G_Kaidan.h"
#include "Box.h"
#include "Game.h"
#include "Stage.h"
#include "Number_Storage.h"
bool G_Kaidan::Start()
{
	Kaidan.Init("Assets/modelData/kaidan3.tkm", Light);
	Kaidan.SetPosition({ Grid_ExemptPosition_X, Grid_ExemptPosition_Y, Grid_ExemptPosition_Z });
	Kaidan.SetScale(Kaidan_Scale);
	
	game = FindGO<Game>("game");
	stage = FindGO<Stage>("stage");
	box = FindGO<Box>("box");

	LevelSet();
	return true;
}
void G_Kaidan::LevelSet()
{
	Kaidan.SetRotation(Kaidan_Rotation);
	Kaidan.Update();

}
void G_Kaidan::Map_SetPosition(Vector3 Position)
{
	Kaidan_Position.x = Position.x;
	Kaidan_Position.y = 20.0f;
	Kaidan_Position.z = Position.z;
}
void G_Kaidan::Update()
{
	Kaidan.SetRotation(Kaidan_Rotation);
	Kaidan.SetPosition(Kaidan_Position);
	box->KaidanBox_SetPosition(Kaidan_Position);
	Kaidan.Update();
}
void G_Kaidan::Render(RenderContext& rc)
{
	Kaidan.Draw(rc);
}