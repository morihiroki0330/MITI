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
	int weightboard_block_map[10][10];
	bool weightboard_block_link;
	
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

	//�ǉ�
	ModelRender Kabe;
	Vector3 Kabe_P;

	//�n��
	ModelRender Ground[10][10];
	Vector3 Ground_P[10][10];
	MapData mapdata[10][10];
	Map map;

	PhysicsStaticObjectPos k_physicsStaticObjectpos;
	PhysicsStaticObjectPos g_physicsStaticObjectpos[10][10];
	
	//�n�ʂ̐����y���E�X�E���E�j�󏰁z
	bool hole_create;
	bool ice_create;
	bool ground_create;
	bool break_create;

	//����̐ݒu���y�S�[���p�̊K�i�E�����E��ǃu���b�N�E�S�[������̔��z
	bool kaidan_create;
	bool weightboard_create;
	bool block_create;
	bool wall_create;
	
	
	
};

