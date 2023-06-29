#pragma once
#include "Number_Storage.h"
class G_Hole : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender Hole;
	Vector3 Hole_Position = { NON,-300.0f,NON };
	PhysicsStaticObjectPos Hole_PSO;
	AllLight Light;
};

