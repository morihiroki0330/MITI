#pragma once

class G_Wall:public IGameObject
{
public:
	G_Wall();
	~G_Wall();
	void Update();
	void Render(RenderContext& rc);
	
	ModelRender Wall;
	Vector3 Wall_P;
	PhysicsStaticObjectPos m_physicsStaticObjectpos;
	AllLight Light;

};

