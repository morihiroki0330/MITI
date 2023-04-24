#pragma once

class G_IceFloor;
class G_BreakFloar;
class G_WeightBoard;
class G_Wall;
class Hole;
class G_Block;
class G_Kaidan;

struct MapData
{
	bool ice_on;
	G_IceFloor* ice;

	bool breakfloar_on;
	G_BreakFloar* breakfloar;

	bool weightboard_map;
	int weightboard_block_map[10][10];
	bool weightboard_block_link;
	
	G_WeightBoard* weightboard;

	bool wall_on;
	G_Wall* wall;

	bool hole_on;
	Hole* hole;

	bool block_on;
	G_Block* block;

	bool kaidan_on;
	G_Kaidan* kaidan;

};

struct Map 
{
	G_IceFloor* ice;
	G_BreakFloar* breakfloar;
	G_WeightBoard* weightboard;
	G_Wall* wall;
	Hole* hole;
	G_Block* block;
	G_Kaidan* kaidan;
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
	MapData mapdata[10][10];
	Map map;

	PhysicsStaticObjectPos k_physicsStaticObjectpos;
	PhysicsStaticObjectPos g_physicsStaticObjectpos[10][10];
	
	bool weightblock_create;
};

