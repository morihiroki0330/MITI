#include "stdafx.h"
#include "Stage.h"

#include "G_IceFloor.h"
#include "G_WeightBoard.h"
#include "G_Wall.h"
#include "G_Hole.h"
#include "G_Block.h"
#include "G_Kaidan.h"
#include "G_Ground.h"

#include "Player.h"
#include "Game.h"

Stage::Stage()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			MapPosition[Y][X].x = (Y * 191.0f) + -865.0f;
			MapPosition[Y][X].y = 0.0f;
			MapPosition[Y][X].z = (X * 191.0f) + -865.0f;
		}
	}
	
	MapChipCreate();
}

Stage::~Stage()
{
	DeleteGO(Map.Ice);
	DeleteGO(Map.Ground);
	DeleteGO(Map.Hole);
	DeleteGO(Map.Block);
	DeleteGO(Map.Kaidan);
	DeleteGO(Map.Weightboard);
	DeleteGO(Map.Wall);
}

bool Stage::Start()
{
	game = FindGO<Game>("game");
	
	StageOrderSet();
	LevelSet();
	MapToCopy();
	MapSet();
	return true;
}

void Stage::MapChipCreate()
{
	Map.Hole = NewGO<G_Hole>(0, "hole");
	Map.Ice = NewGO<G_IceFloor>(0, "ice");
	Map.Ground = NewGO<G_Ground>(0, "ground");
	Map.Kaidan = NewGO<G_Kaidan>(0, "kaidan");
	Map.Weightboard = NewGO<G_WeightBoard>(0, "weightboard");
	Map.Block = NewGO<G_Block>(0, "block");
	Map.Wall = NewGO<G_Wall>(0, "wall");
}


void Stage::StageOrderSet()
{
	StageOrder[Stage0] = { Level0 };
	StageOrder[Stage1] = { Level1 };
	StageOrder[Stage2] = { Level2 };
	StageOrder[Stage3] = { Level3 };
	StageOrder[Stage4] = { Level4 };
	StageOrder[Stage5] = { Level5 };
	StageOrder[Stage6] = { Level6 };
	StageOrder[Stage7] = { Level7 };
	StageOrder[Stage8] = { Level8 };
	StageOrder[Stage9] = { Level9 };
}


void Stage::GroundDataSet(int Y, int X, int Data)
{
	MapData[Y][X].GroundData = Data;
}
void Stage::SkyDataSet(int Y, int X, int Data)
{
	MapData[Y][X].SkyData = Data;
}


void Stage::MapToCopy()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			MapData[Y][X].Ice_On = Level[StageOrder[game->GetLevel()]][Y][X].Ice_On;

			MapData[Y][X].Block_On = Level[StageOrder[game->GetLevel()]][Y][X].Block_On;
			MapData[Y][X].NonBlock_On = Level[StageOrder[game->GetLevel()]][Y][X].NonBlock_On;

			MapData[Y][X].Hole_On = Level[StageOrder[game->GetLevel()]][Y][X].Hole_On;

			MapData[Y][X].WeightBoard_On = Level[StageOrder[game->GetLevel()]][Y][X].WeightBoard_On;

			MapData[Y][X].Kaidan_On = Level[StageOrder[game->GetLevel()]][Y][X].Kaidan_On;
		}
	}
}


void Stage::LevelSet()
{
	LevelIceSet();
	LevelHoleSet();
	LevelKaidanSet();
	LevelBlockSet();
	LevelWeightBoardSet();
	
}
int Stage::LevelIceSet()
{
	const char* FilePath = nullptr;
	switch (game->GetLevel())
	{
	case Level0:
		FilePath = "Assets/Level/Level0/Ice.txt";
		break;
	case Level1:
		return 1;
		break;
	case Level2:
		FilePath = "Assets/Level/Level2/Ice.txt";
		break;
	case Level3:
		FilePath = "Assets/Level/Level3/Ice.txt";
		break;
	case Level4:
		FilePath = "Assets/Level/Level4/Ice.txt";
		break;
	case Level5:
		FilePath = "Assets/Level/Level5/Ice.txt";
		break;
	case Level6:
		FilePath = "Assets/Level/Level6/Ice.txt";
		break;
	case Level7:
		FilePath = "Assets/Level/Level7/Ice.txt";
		break;
	case Level8:
		FilePath = "Assets/Level/Level8/Ice.txt";
		break;
	case Level9:
		FilePath = "Assets/Level/Level9/Ice.txt";
		break;
	default:
		break;
	}
	FILE* FilePointer = nullptr;

	fopen_s(&FilePointer, FilePath, "r");

	if (FilePointer == NULL)
	{
		getchar();
		return 0;
	}

	int LevelValue = 99, Y = 99, X = 99;
	char Value[256];
	while (fgets(Value, 2, FilePointer) != NULL)
	{
		if (Value[0] == 'X')
		{
			LevelValue = 99;
			Y = 99;
			X = 99;
		}else {
		if (LevelValue == 99)
		{
			if (Value[0] != '\n')
			{
				int Count = atoi(Value);
				LevelValue = Count;
			}
		}else {
		if (Y == 99)
		{
			if (Value[0] != '\n')
			{
				int Count = atoi(Value);
				Y = Count;
			}
		}else {
		if (X == 99)
		{
			if (Value[0] != '\n')
			{
				int Count = atoi(Value);
				X = Count;
				Level[LevelValue][Y][X].Ice_On = true;
			}
		}
		}
		}
		}
	}
	fclose(FilePointer);
	getchar();
}
int Stage::LevelHoleSet()
{
	const char* FilePath = nullptr;
	switch (game->GetLevel())
	{
	case Level0:
		FilePath = "Assets/Level/Level0/Hole.txt";
		break;
	case Level1:
		FilePath = "Assets/Level/Level1/Hole.txt";
		break;
	case Level2:
		FilePath = "Assets/Level/Level2/Hole.txt";
		break;
	case Level3:
		FilePath = "Assets/Level/Level3/Hole.txt";
		break;
	case Level4:
		FilePath = "Assets/Level/Level4/Hole.txt";
		break;
	case Level5:
		FilePath = "Assets/Level/Level5/Hole.txt";
		break;
	case Level6:
		FilePath = "Assets/Level/Level6/Hole.txt";
		break;
	case Level7:
		FilePath = "Assets/Level/Level7/Hole.txt";
		break;
	case Level8:
		FilePath = "Assets/Level/Level8/Hole.txt";
		break;
	case Level9:
		FilePath = "Assets/Level/Level9/Hole.txt";
		break;
	default:
		break;
	}
	FILE* FilePointer = nullptr;

	fopen_s(&FilePointer, FilePath, "r");

	if (FilePointer == NULL)
	{
		getchar();
		return 0;
	}

	int LevelValue = 99, Y = 99, X = 99;
	char Value[256];
	while (fgets(Value, 2, FilePointer) != NULL)
	{
		if (Value[0] == 'X')
		{
			LevelValue = 99;
			Y = 99;
			X = 99;
		}else {
		if (LevelValue == 99)
		{
			if (Value[0] != '\n')
			{
				int Count = atoi(Value);
				LevelValue = Count;
			}
		}else {
		if (Y == 99)
		{
			if (Value[0] != '\n')
			{
				int Count = atoi(Value);
				Y = Count;
			}
		}else {
		if (X == 99)
		{
			if (Value[0] != '\n')
			{
				int Count = atoi(Value);
				X = Count;
				Level[LevelValue][Y][X].Hole_On = true;
			}
		}
		}
		}
		}
	}
	fclose(FilePointer);
	getchar();
}
int Stage::LevelBlockSet()
{
	const char* FilePath = nullptr;
	switch (game->GetLevel())
	{
	case Level0:
		FilePath = "Assets/Level/Level0/Block.txt";
		break;
	case Level1:
		FilePath = "Assets/Level/Level1/Block.txt";
		break;
	case Level2:
		FilePath = "Assets/Level/Level2/Block.txt";
		break;
	case Level3:
		FilePath = "Assets/Level/Level3/Block.txt";
		break;
	case Level4:
		FilePath = "Assets/Level/Level4/Block.txt";
		break;
	case Level5:
		FilePath = "Assets/Level/Level5/Block.txt";
		break;
	case Level6:
		FilePath = "Assets/Level/Level6/Block.txt";
		break;
	case Level7:
		FilePath = "Assets/Level/Level7/Block.txt";
		break;
	case Level8:
		FilePath = "Assets/Level/Level8/Block.txt";
		break;
	case Level9:
		FilePath = "Assets/Level/Level9/Block.txt";
		break;
	default:
		break;
	}
	FILE* FilePointer = nullptr;

	fopen_s(&FilePointer, FilePath, "r");

	if (FilePointer == NULL)
	{
		getchar();
		return 0;
	}

	int LevelValue = 99, Y = 99, X = 99;
	char Value[256];
	while (fgets(Value, 2, FilePointer) != NULL)
	{
		if (Value[0] == 'X')
		{
			LevelValue = 99;
			Y = 99;
			X = 99;
		}else {
		if (Value[0] == 'N')
		{
			Level[LevelValue][Y][X].NonBlock_On = true;
		}else{
		if (LevelValue == 99)
		{
			if (Value[0] != '\n')
			{
				int Count = atoi(Value);
				LevelValue = Count;
			}
		}else {
		if (Y == 99)
		{
			if (Value[0] != '\n')
			{
				int Count = atoi(Value);
				Y = Count;
			}
		}else {
		if (X == 99)
		{
			if (Value[0] != '\n')
			{
				int Count = atoi(Value);
				X = Count;
				Level[LevelValue][Y][X].Block_On = true;
			}
		}
		}
		}
		}
		}
	}
	fclose(FilePointer);
	getchar();
}
int Stage::LevelKaidanSet()
{
	const char* FilePath = nullptr;
	switch (game->GetLevel())
	{
	case Level0:
		FilePath = "Assets/Level/Level0/Kaidan.txt";
		break;
	case Level1:
		FilePath = "Assets/Level/Level1/Kaidan.txt";
		break;
	case Level2:
		FilePath = "Assets/Level/Level2/Kaidan.txt";
		break;
	case Level3:
		FilePath = "Assets/Level/Level3/Kaidan.txt";
		break;
	case Level4:
		FilePath = "Assets/Level/Level4/Kaidan.txt";
		break;
	case Level5:
		FilePath = "Assets/Level/Level5/Kaidan.txt";
		break;
	case Level6:
		FilePath = "Assets/Level/Level6/Kaidan.txt";
		break;
	case Level7:
		FilePath = "Assets/Level/Level7/Kaidan.txt";
		break;
	case Level8:
		FilePath = "Assets/Level/Level8/Kaidan.txt";
		break;
	case Level9:
		FilePath = "Assets/Level/Level9/Kaidan.txt";
		break;
	default:
		break;
	}
	FILE* FilePointer = nullptr;

	fopen_s(&FilePointer, FilePath, "r");

	if (FilePointer == NULL)
	{
		getchar();
		return 0;
	}

	int LevelValue = 99, Y = 99, X = 99;
	char Value[256];
	while (fgets(Value, 2, FilePointer) != NULL)
	{
		if (Value[0] == 'X')
		{
			LevelValue = 99;
			Y = 99;
			X = 99;
		}else {
		if (LevelValue == 99)
		{
			if (Value[0] != '\n')
			{
				int Count = atoi(Value);
				LevelValue = Count;
			}
		}else {
		if (Y == 99)
		{
			if (Value[0] != '\n')
			{
				int Count = atoi(Value);
				Y = Count;
			}
		}else {
		if (X == 99)
		{
			if (Value[0] != '\n')
			{
				int Count = atoi(Value);
				X = Count;
				Level[LevelValue][Y][X].Kaidan_On = true;
			}
		}
		}
		}
		}
	}
	fclose(FilePointer);
	getchar();
}
int Stage::LevelWeightBoardSet()
{
	const char* FilePath = nullptr;
	switch (game->GetLevel())
	{
	case Level0:
		FilePath = "Assets/Level/Level0/WeightBoard.txt";
		break;
	case Level1:
		FilePath = "Assets/Level/Level1/WeightBoard.txt";
		break;
	case Level2:
		FilePath = "Assets/Level/Level2/WeightBoard.txt";
		break;
	case Level3:
		FilePath = "Assets/Level/Level3/WeightBoard.txt";
		break;
	case Level4:
		FilePath = "Assets/Level/Level4/WeightBoard.txt";
		break;
	case Level5:
		FilePath = "Assets/Level/Level5/WeightBoard.txt";
		break;
	case Level6:
		FilePath = "Assets/Level/Level6/WeightBoard.txt";
		break;
	case Level7:
		FilePath = "Assets/Level/Level7/WeightBoard.txt";
		break;
	case Level8:
		FilePath = "Assets/Level/Level8/WeightBoard.txt";
		break;
	case Level9:
		FilePath = "Assets/Level/Level9/WeightBoard.txt";
		break;
	default:
		break;
	}
	FILE* FilePointer = nullptr;

	fopen_s(&FilePointer, FilePath, "r");

	if (FilePointer == NULL)
	{
		getchar();
		return 0;
	}

	int LevelValue = 99, Y = 99, X = 99;
	int  Order = 99 , Number10 = 99, Number1 = 99;
	int LinkObject = 99;
	int LinkCount = 0;
	bool Step1 = false, Step2 = false, Step3 = false;
	bool FullReset = false, MiddleReset = false;
	char Value[256];
	while (fgets(Value, 2, FilePointer) != NULL)
	{

		if (MiddleReset == true)
		{
			Order = 99;
			Number10 = 99;
			Number1 = 99;
			LinkObject = 99;
			MiddleReset = false;
		}else {
		if (FullReset == true)
		{
			Step1 = false;
			Step2 = false;
			Step3 = false;
			LevelValue = 99;
			Y = 99;
			X = 99;
			Order = 99;
			Number10 = 99;
			Number1 = 99;
			LinkObject = 99;
			LinkCount = 0;
			FullReset = false;
		}
		}

		if (Step1 == false)
		{
			if (Value[0] == 'X')
			{
				Step1 = true;
			}else {
			if (LevelValue == 99)
			{
				if (Value[0] != '\n')
				{
					int Count = atoi(Value);
					LevelValue = Count;
				}
			}else {
			if (Y == 99)
			{
				if (Value[0] != '\n')
				{
					int Count = atoi(Value);
					Y = Count;
				}
			}else {
			if (X == 99)
			{
				if (Value[0] != '\n')
				{
					int Count = atoi(Value);
					X = Count;
					Level[LevelValue][Y][X].WeightBoard_On = true;
				}
			}
			}
			}
			}
		}else {
		if (Step1 == true && Step2 == false)
		{
			if (Value[0] == 'Y')
			{
				Step2 = true;
			}else {
			if (Order == 99)
			{
				if (Value[0] != '\n')
				{
					int Count = atoi(Value);
					Order = Count;
				}
			}else {
			if (Number10 == 99)
			{
				if (Value[0] != '\n')
				{
					int Count = atoi(Value);
					Number10 = Count;
				}
			}else {
			if (Number1 == 99)
			{
				if (Value[0] != '\n')
				{
					int Count = atoi(Value);
					Number1 = Count;
					Level[LevelValue][Y][X].WeightBoard_LinkNumber[Order] = (Number10 * 10) + Number1;
				}
			}
			}
			}
			}
		}else {
		if (Step1 == true && Step2 == true && Step3 == false)
		{
			if (Value[0] == 'Z')
			{
				Step2 = false;
				MiddleReset = true;
			}else {
			if (Value[0] == 'F')
			{
				Step3 = true;
				FullReset = true;
			}else {
			if (LinkObject == 99)
			{
				if (Value[0] != '\n')
				{
					int Count = atoi(Value);
					LinkObject = Count;
					Level[LevelValue][Y][X].WeightBoard_LinkObject[Order] = LinkObject;
					LinkCount++;
					Level[LevelValue][Y][X].WeightBoard_LinkCount = LinkCount;
				}
			}
			}
			}
		}
		}
		}
	}
	fclose(FilePointer);
	getchar();
}


void Stage::MapSet()
{
	MapSetGround();
	MapSetSky();
}
void Stage::MapSetGround()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (MapData[Y][X].Hole_On == true)
			{
				GroundDataSet(Y, X, HOLE);
			}else {
			if (MapData[Y][X].Ice_On == true)
			{
				Map.Ice->IceFloorOnTrue(Y, X);
				Map.Ice->IceFloorSetPosition(Y, X, MapPosition[Y][X]);
				GroundDataSet(Y, X, ICE);
			}else {
				Map.Ground->GroundOnTrue(Y, X);
				Map.Ground->GroundSetPosition(Y, X, MapPosition[Y][X]);
				GroundDataSet(Y, X, GROUND);
			}
			}
		}
	}
}
void Stage::MapSetSky()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (MapData[Y][X].Kaidan_On == true)
			{
				Map.Kaidan->Map_SetPosition(MapPosition[Y][X]);
				SkyDataSet(Y, X, KAIDAN);
			}else {
			if (MapData[Y][X].WeightBoard_On == true)
			{
				for (int W = 1; W < Level[StageOrder[game->GetLevel()]][Y][X].WeightBoard_LinkCount + 1; W++)
				{
					Map.Weightboard->LinkNumberSet(Y, X, W, Level[StageOrder[game->GetLevel()]][Y][X].WeightBoard_LinkNumber[W]);
					Map.Weightboard->LinkObjectSet(Y, X, W, Level[StageOrder[game->GetLevel()]][Y][X].WeightBoard_LinkObject[W]);
				}
				Map.Weightboard->LinkCountSet(Y, X, Level[StageOrder[game->GetLevel()]][Y][X].WeightBoard_LinkCount);
				Map.Weightboard->WeightBoardOnTrue(Y, X);
				Map.Weightboard->WeightBoardSetPosition(Y, X, MapPosition[Y][X]);
				SkyDataSet(Y, X, WEIGHTBOARD);
			}else {
			if (MapData[Y][X].Block_On == true)
			{
				if (MapData[Y][X].NonBlock_On == true){Map.Block->BlockOn(Y, X);}
				Map.Block->BlockSetPosition(Y, X, MapPosition[Y][X]);
				SkyDataSet(Y, X, BLOCK);
			}
			}
			}
		}
	}
}

int Stage::GetGroundData(int Map, int Direction)
{
	switch (Direction)
	{
	case PlayerDirectionUp:
		return MapData[(Map / 10) - 1][(Map % 10)].GroundData;
		break;
	case PlayerDirectionDown:
		return MapData[(Map / 10) + 1][(Map % 10)].GroundData;
		break;
	case PlayerDirectionRight:
		return MapData[(Map / 10)][(Map % 10) + 1].GroundData;
		break;
	case PlayerDirectionLeft:
		return MapData[(Map / 10)][(Map % 10) - 1].GroundData;
		break;
	default:
		if (Map == 0)
		{
			return MapData[0][0].GroundData;
		}else {
			return MapData[(Map / 10)][(Map % 10)].GroundData;
		}
		break;
	}
}

int Stage::GetSkyData(int Map, int Direction)
{
	switch (Direction)
	{
	case PlayerDirectionUp:
		return MapData[(Map / 10) - 1][(Map % 10)].SkyData;
		break;
	case PlayerDirectionDown:
		return MapData[(Map / 10) + 1][(Map % 10)].SkyData;
		break;
	case PlayerDirectionRight:
		return MapData[(Map / 10)][(Map % 10) + 1].SkyData;
		break;
	case PlayerDirectionLeft:
		return MapData[(Map / 10)][(Map % 10) - 1].SkyData;
		break;
	default:
		return MapData[(Map / 10)][(Map % 10)].SkyData;
		break;
	}
}

