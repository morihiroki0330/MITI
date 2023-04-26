#pragma once

class G_IceFloor;
class G_BreakFloar;
class G_WeightBoard;
class G_Wall;
class G_Hole;
class G_Block;
class G_Kaidan;
class G_Ground;

struct MapData
{
	bool ice_on;
	G_IceFloor* ice;

	bool breakfloar_on;
	G_BreakFloar* breakfloar;

	bool weightboard_map;
	
	G_WeightBoard* weightboard;

	bool wall_on;
	G_Wall* wall;

	bool hole_on;
	G_Hole* hole;

	bool block_on;
	G_Block* block;

	bool kaidan_on;
	G_Kaidan* kaidan;

	G_Ground* ground;

};

struct Map 
{
	G_IceFloor* Ice;
	G_BreakFloar* Breakfloar;
	G_WeightBoard* Weightboard;
	G_Wall* Wall;
	G_Hole* Hole;
	G_Block* Block;
	G_Kaidan* Kaidan;
	G_Ground* Ground;
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

	//壁画
	ModelRender Kabe;
	Vector3 Kabe_P;

	//地面
	ModelRender Ground[10][10];
	Vector3 Ground_P[10][10];
	MapData mapdata[10][10];
	Map map;

	PhysicsStaticObjectPos k_physicsStaticObjectpos;
	PhysicsStaticObjectPos g_physicsStaticObjectpos[10][10];
	
	//地面の生成【穴・氷・床・破壊床】
	bool hole_create;
	bool ice_create;
	bool ground_create;
	bool break_create;

	//床上の設置物【ゴール用の階段・感圧板・障壁ブロック・ゴール解放の扉】
	bool kaidan_create;
	bool weightboard_create;
	bool block_create;
	bool wall_create;
	
	int l = 0;
	int r = 0;
	
};

