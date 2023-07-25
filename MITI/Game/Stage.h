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
	bool M_Ice_On;
	bool M_WeightBoard_On;
	int M_WeightBoard_LinkNumber[15];
	int M_WeightBoard_LinkObject[15];
	int M_WeightBoard_LinkCount;
	bool M_Hole_On;
	bool M_Block_On;
	bool M_NonBlock_On;
	bool M_Kaidan_On;
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
	NONBLOCK,
	GROUNDBLOCK,
	ICEBLOCK,
	DELETEBLOCK,
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

	Player* M_Player = nullptr;
	Game* M_Game = nullptr;

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