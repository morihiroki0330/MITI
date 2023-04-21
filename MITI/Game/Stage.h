#pragma once

class G_IceFloor;
class G_BreakFloar;
class G_WeightBoard;
class G_Wall;
class Hole;

struct Map
{
	bool ice_on;
	G_IceFloor* ice;

	bool breakfloar_on;
	G_BreakFloar* breakfloar;

	bool weightboard_on;
	G_WeightBoard* weightboard;

	bool wall_on;
	G_Wall* wall;

	bool hole_on;
	Hole* hole;
};

class Stage : public IGameObject
{
public:
	Stage();
	~Stage();

	void Render(RenderContext& rc);

	ModelRender m_modelRender;
	PhysicsStaticObject m_physicsStaticObject;
	float stageID[10][10];

	AllLight stageLight;

	//•Ç‰æ
	ModelRender Kabe;
	Vector3 Kabe_P;

	//’n–Ê
	ModelRender Ground[10][10];
	Vector3 Ground_P[10][10];
	Map map[10][10];

	PhysicsStaticObjectPos k_physicsStaticObjectpos;
	PhysicsStaticObjectPos g_physicsStaticObjectpos[10][10];
};

