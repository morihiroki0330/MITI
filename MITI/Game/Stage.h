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
struct MapChipData
{
	bool Ice_On;
	bool BreakFloar_On;
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
	G_BreakFloar* Breakfloar;
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
enum MapchipNumber
{
	HOLE,
	ICE,
	GROUND,
	BREAKFLOOR,
	KAIDAN,
	WEIGHTBOARD,
	BLOCK,
	WALL,
};
enum LinkObject
{
	NOON,
	L_BLOCK,
	G_BLOCK,
	I_BLOCK,
	H_BLOCK,
};

class Stage : public IGameObject
{
public:
	Stage();
	~Stage();
	bool Start();

	//クラス設計
	void MapChipCreate();

	//レベルデータの代入
	void MapToCopy();

	//レベルごとのマップ設定
	void LevelSet();
	int LevelIceSet();
	int LevelHoleSet();
	int LevelBlockSet();
	int LevelKaidanSet();
	int LevelWeightBoardSet();

	//マス地形のオブジェクト設定
	void MapSet();
	void MapSetGround();
	void MapSetSky();

	//マス地形の情報設定
	void GroundDataSet(int Y , int X , int Data);
	void SkyDataSet(int Y, int X,  int Data);

	//ステージの順番決め
	void StageOrderSet();

	//マス地形の情報
	int GetMapData(int Y, int X, int Direction);

	Vector3 Map_Position[10][10];

	MapChipData MapData[10][10];
	MapChip Map;
	LinkObject Link;

	Player* player = nullptr;
	Game* game = nullptr;

	MapChipData Level[10][10][10];

	int StageOrder[10];
};

