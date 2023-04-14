#include "stdafx.h"
#include "UNITY.h"

UNITY::UNITY()
{
	
	Unity_P1.x = -100.0f;
	Unity_P1.y = 0.0f;
	Unity_P1.z = 0.0f;
	
	Unity_P2.x = 100.0f;
	Unity_P2.y = 0.0f;
	Unity_P2.z = 0.0f;

	Unity_L1.DirectionLight_D.x = Unity_P1.x + 1.0f;
	Unity_L1.DirectionLight_D.y = Unity_P1.y - 1.0f;
	Unity_L1.DirectionLight_D.z = Unity_P1.z - 1.0f;

	Unity_L1.DirectionLight_C.x = 1.0f;
	Unity_L1.DirectionLight_C.y = 1.0f;
	Unity_L1.DirectionLight_C.z = 1.0f;
	
	Unity_L2.DirectionLight_D.x = Unity_P2.x + 1.0f;
	Unity_L2.DirectionLight_D.y = Unity_P2.x - 1.0f;
	Unity_L2.DirectionLight_D.z = Unity_P2.x - 1.0f;

	Unity_L2.DirectionLight_C.x = 1.0f;
	Unity_L2.DirectionLight_C.y = -1.0f;
	Unity_L2.DirectionLight_C.z = 1.0f;

	Unity_M1.Init("Assets/modelData/unityChan.tkm",Unity_L1);
	Unity_M2.Init("Assets/modelData/unityChan.tkm",Unity_L2);

	

}

UNITY::~UNITY()
{

}

void UNITY::Update()
{
	
	Unity_M1.SetPosition(Unity_P1);
	Unity_M1.Update();
	
	Unity_M2.SetPosition(Unity_P2);
	Unity_M2.Update();
}	

void UNITY::Render(RenderContext& rc)
{
	Unity_M1.Draw(rc);
	Unity_M2.Draw(rc);
}