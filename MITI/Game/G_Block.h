#pragma once

class G_WeightBoard;
class Box;
class Stage;
class G_Block : public IGameObject
{
public:
	G_Block();
	~G_Block();
	void Update();
	void Render(RenderContext& rc);

	ModelRender Block[10][10];
	Vector3 Block_P[10][10];
	AllLight Light;
	PhysicsStaticObjectPos m_physicsStaticObjectpos[10][10];

	G_WeightBoard* weightboard;
	Box* box;
	Stage* stage;

	bool Block_on[10][10];
	bool Block_only[10][10];
};

