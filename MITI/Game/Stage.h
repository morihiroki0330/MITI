#pragma once

class G_IceFloor;
class G_BreakFloar;
class G_WeightBoard;
class G_Wall;
class G_Hole;
class G_Block;
class G_Kaidan;
class G_Ground;
class Player;
class Game;
struct MapData
{
	bool ice_on;

	bool breakfloar_on;

	bool weightboard_map;

	int weightboard_linknumber[10];

	int weightboard_linkobject[5];

	int weightboard_count;

	bool wall_on;

	bool hole_on;

	bool block_on;

	bool blockonly_on;

	bool kaidan_on;

	bool ground_on;

	int grounddata;

	int skydata;
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

enum Mapchip
{
	HOLE,//0
	ICE,//1
	GROUND,//2
	BREAKFLOOR,//3

	KAIDAN,//4
	WEIGHTBOARD,//5
	BLOCK,//6
	WALL,//7
	NULL_A
};

enum LinkObject
{
	NOON,//0
	L_HOLE,//1
	L_ICE,//2
	L_GROUND,//3
	L_BREAKFLOOR,//4

	L_KAIDAN,//5
	L_WEIGHTBOARD,//6
	L_BLOCK,//7
	G_BLOCK,//8
	I_BLOCK,//9
	H_BLOCK,//10
	L_WALL//11
};

class Stage : public IGameObject
{
public:
	Stage();
	~Stage();
	void Update();
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
	
	LinkObject Link;

	Player* player;

	//1.レベル　2.行　3.列
	MapData Level[10][10][10];

	bool Map_SetGround[10][10];

	bool Map_SetSky[10][10];

	bool Level_Set;

	bool Map_Set;

	Vector3 Reset_P;

	Game* game;
};

