#pragma once
#include "NumberStorage.h"
class G_IceFloor;
class G_WeightBoard;
class G_Wall;
class G_Hole;
class G_Block;
class G_Kaidan;
class G_Ground;
class Game;
struct MapChipData
{
	bool M_IceOn;
	bool M_WeightBoardOn;
	int M_WeightBoardLinkNumber[15];
	int M_WeightBoardLinkObject[15];
	int M_WeightBoardLinkCount;
	bool M_HoleOn;
	bool M_BlockOn;
	bool M_NonBlockOn;
	bool M_KaidanOn;
	int M_GroundData;
	int M_SkyData;
};
struct MapChip
{
	G_IceFloor* P_Ice;
	G_WeightBoard* P_Weightboard;
	G_Wall* P_Wall;
	G_Hole* P_Hole;
	G_Block* P_Block;
	G_Kaidan* P_Kaidan;
	G_Ground* P_Ground;
};
enum StageOrder
{
	STAGE0,
	STAGE1,
	STAGE2,
	STAGE3,
	STAGE4,
	STAGE5,
	STAGE6,
	STAGE7,
	STAGE8,
	STAGE9
};
enum LevelOrder
{
	LEVEL0,
	LEVEL1,
	LEVEL2,
	LEVEL3,
	LEVEL4,
	LEVEL5,
	LEVEL6,
	LEVEL7,
	LEVEL8,
	LEVEL9
};
enum MapchipNumber
{
	HOLE = 0,
	ICE = 1,
	GROUND = 2,
	KAIDAN = 3,
	WEIGHTBOARD = 4,
	BLOCK = 5,
	WALL = 6
};
enum LinkObject
{
	NOTBLOCK,
	NONBLOCK,
	GROUNDBLOCK,
	ICEBLOCK,
	DELETEBLOCK
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

	void GroundDataSet(int Y, int X, int Data);
	void SkyDataSet(int Y, int X, int Data);

	void StageOrderSet();

	int GetGroundData(int Map, int Direction = 4);
	int GetSkyData(int Map, int Direction = 4);
private:
	MapChip S_Map;
	Vector3 M_MapPosition[M_Ymas][M_Xmas];
	MapChipData S_MapData[M_Ymas][M_Xmas];
	MapChipData S_Level[M_Ymas][M_Xmas][10];

	Game* P_Game = nullptr;

	int M_StageOrder[10];
};