#pragma once

class Player;
class IronBall;
class G_Block;
class Stage;
class G_WeightBoard:public IGameObject
{
public:
	G_WeightBoard();
	~G_WeightBoard();
	void Update();
	void Render(RenderContext& rc);

	ModelRender Weightboard[10][10];
	Vector3 Weightboard_P[10][10];
	PhysicsStaticObjectPos m_physicsStaticObjectpos[10][10];
	AllLight Light;

	Player* player;
	IronBall* ironBall;
	G_Block* block;
	Stage* stage;

	bool BgmSet[10][10];
	bool HitFlag[10][10];
	bool PutFlag[10][10];
		
	bool WeightBoard_on[10][10];

	int Link_Number[10][10][10];
	int Link_Count[10][10];
	int Link[10][10][10];

	bool Link_on;
	bool Block_Link;

	FontRender Hit;
	
};

