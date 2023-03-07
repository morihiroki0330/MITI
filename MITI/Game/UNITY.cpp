#include "stdafx.h"
#include "UNITY.h"

UNITY::UNITY()
{
	Unity.Init("Assets/modelData/test4.tkm");

	Unity_P.x = 000.0f;
	Unity_P.y = 0.0f;
	Unity_P.z = 0.0f;

	Unity.SetPosition(Unity_P);
}

UNITY::~UNITY()
{

}

void UNITY::Update()
{
	Unity_P.x -= 1.0f;
	Unity.SetPosition(Unity_P);
	Unity.Update();
}

void UNITY::Render(RenderContext& rc)
{
	Unity.Draw(rc);
}