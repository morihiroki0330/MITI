#pragma once
class G_WeightBoard;
class G_Block : public IGameObject
{
public:
	G_Block();
	~G_Block();
	void Update();
	void Render(RenderContext& rc);

	ModelRender Block[10][10];
	Vector3 Block_P[10][10];

	PhysicsStaticObjectPos m_physicsStaticObjectpos[10][10];

	G_WeightBoard* g_weightBoard;

	AllLight light;

	//階段を表示するかしないか
	bool Block_on[10][10];

	int blockcount;
};

