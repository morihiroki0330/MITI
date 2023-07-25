#pragma once
#include "NumberStorage.h"
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
	G_IceFloor* M_Ice;
	G_WeightBoard* M_Weightboard;
	G_Wall* M_Wall;
	G_Hole* M_Hole;
	G_Block* M_Block;
	G_Kaidan* M_Kaidan;
	G_Ground* M_Ground;
};
enum StageOrder
{
	STAGE0 = 0,
	STAGE1 = 1,
	STAGE2 = 2,
	STAGE3 = 3,
	STAGE4 = 4,
	STAGE5 = 5,
	STAGE6 = 6,
	STAGE7 = 7,
	STAGE8 = 8,
	STAGE9 = 9
};
enum LevelOrder
{
	LEVEL0 = 0,
	LEVEL1 = 1,
	LEVEL2 = 2,
	LEVEL3 = 3,
	LEVEL4 = 4,
	LEVEL5 = 5,
	LEVEL6 = 6,
	LEVEL7 = 7,
	LEVEL8 = 8,
	LEVEL9 = 9
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
	NONBLOCK = 1,
	GROUNDBLOCK = 2,
	ICEBLOCK = 3,
	DELETEBLOCK = 4
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
	MapChip M_Map;
	Vector3 M_MapPosition[10][10];
	MapChipData M_MapData[10][10];
	MapChipData M_Level[10][10][10];

	Game* P_Game = nullptr;

	int M_StageOrder[10];

	TextureHeight S_TextureHeight;
	TextureWide S_TextureWide;
	Color S_Color;
	FadeInformation S_FadeInformation;
	GridPosition S_GridPosition;
	SoundSetting S_SoundSetting;
	PlayerInformation S_PlayerInformation;
	BlockInformation S_BlockInformation;
	WorldInformation S_WorldInformation;
	IronBallInformation S_IronBallInformation;
};