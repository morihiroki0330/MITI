#include "stdafx.h"
#include "UNITY.h"

UNITY::UNITY()
{
	Unity.Init("Assets/modelData/unityChan.tkm");
}

UNITY::~UNITY()
{

}

void UNITY::Update()
{
	Unity.Update();
}

void UNITY::Render(RenderContext& rc)
{
	Unity.Draw(rc);
}