#include "stdafx.h"
#include "UNITY.h"

UNITY::UNITY()
{
	Unity_M.Init("Assets/modelData/test4.tkm");
	Unity_S.Init("Assets/modelData/g_norm2.dds",1920.0f,1080.0f);

	Unity_P.x = 150.0f;
	Unity_P.y = 0.0f;
	Unity_P.z = 0.0f;

}

UNITY::~UNITY()
{

}

void UNITY::Update()
{
	Unity_P.x -= 10.0f;
	Unity_S.SetPosition(Unity_P);
	Unity_M.Update();
	Unity_S.Update();
}

void UNITY::Render(RenderContext& rc)
{
	Unity_M.Draw(rc);
	Unity_S.Draw(rc);
}