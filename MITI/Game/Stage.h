#pragma once

class G_IceFloor;
class G_WeightBoard;
class G_Wall;
class G_Hole;
class G_Block;
class G_Kaidan;
class G_Ground;
class Player;
class Game;
struct MapChipData
{
	bool Ice_On;
	bool WeightBoard_On;
	int WeightBoard_LinkNumber[15];
	int WeightBoard_LinkObject[15];
	int WeightBoard_LinkCount;
	bool Hole_On;
	bool Block_On;
	bool NonBlock_On;
	bool Kaidan_On;
	int GroundData;
	int SkyData;
};
struct MapChip 
{
	G_IceFloor* Ice;
	G_WeightBoard* Weightboard;
	G_Wall* Wall;
	G_Hole* Hole;
	G_Block* Block;
	G_Kaidan* Kaidan;
	G_Ground* Ground;
};
enum StageOrder 
{
	Stage0,
	Stage1,
	Stage2,
	Stage3,
	Stage4,
	Stage5,
	Stage6,
	Stage7,
	Stage8,
	Stage9
};
enum LevelOrder
{
	Level0,
	Level1,
	Level2,
	Level3,
	Level4,
	Level5,
	Level6,
	Level7,
	Level8,
	Level9
};
enum MapchipNumber
{
	HOLE,
	ICE,
	GROUND,
	KAIDAN,
	WEIGHTBOARD,
	BLOCK,
	WALL,
};
enum LinkObject
{
	NOON,
	Block,
	GroundBlock,
	IceBlock,
	DeleteBlock,
};

class Stage : public IGameObject
{
public:
	Stage();
	~Stage();
	bool Start();

	void MapChipCreate();

	void MapToCopy();

	void LevelSet();
	int LevelIceSet();
	int LevelHoleSet();
	int LevelBlockSet();
	int LevelKaidanSet();
	int LevelWeightBoardSet();

	void MapSet();
	void MapSetGround();
	void MapSetSky();

	void GroundDataSet(int Y , int X , int Data);
	void SkyDataSet(int Y, int X,  int Data);

	void StageOrderSet();

	int GetGroundData(int Map, int Direction = 4);
	int GetSkyData(int Map, int Direction = 4);
private:
	MapChip Map;
	Vector3 MapPosition[10][10];
	MapChipData MapData[10][10];
	MapChipData Level[10][10][10];

	Player* player = nullptr;
	Game* game = nullptr;

	int StageOrder[10];
};

