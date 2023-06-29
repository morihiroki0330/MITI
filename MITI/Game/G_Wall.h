#pragma once
#include "Number_Storage.h"
class G_Wall:public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender Wall;
	Vector3 Wall_Position = { NON,82.0f,NON };
	PhysicsStaticObjectPos Wall_PSO;
	AllLight Light;
};

