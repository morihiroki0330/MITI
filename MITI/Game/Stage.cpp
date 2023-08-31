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
			M_MapPosition[Y][X].x = (Y * 191.0f) + -865.0f;
			M_MapPosition[Y][X].y = 0.0f;
			M_MapPosition[Y][X].z = (X * 191.0f) + -865.0f;
		}
	}

	MapChipCreate();
}

Stage::~Stage()
{
	DeleteGO(S_Map.P_Ice);
	DeleteGO(S_Map.P_Ground);
	DeleteGO(S_Map.P_Hole);
	DeleteGO(S_Map.P_Block);
	DeleteGO(S_Map.P_Kaidan);
	DeleteGO(S_Map.P_Weightboard);
	DeleteGO(S_Map.P_Wall);
}

bool Stage::Start()
{
	P_Game = FindGO<Game>("game");

	StageOrderSet();
	LevelSet();
	MapToCopy();
	MapSet();
	return true;
}

void Stage::MapChipCreate()
{
	S_Map.P_Hole = NewGO<G_Hole>(0, "hole");
	S_Map.P_Ice = NewGO<G_IceFloor>(0, "ice");
	S_Map.P_Kaidan = NewGO<G_Kaidan>(0, "kaidan");
	S_Map.P_Weightboard = NewGO<G_WeightBoard>(0, "weightboard");
	S_Map.P_Block = NewGO<G_Block>(0, "block");
	S_Map.P_Wall = NewGO<G_Wall>(0, "wall");
	S_Map.P_Ground = NewGO<G_Ground>(0, "ground");
}


void Stage::StageOrderSet()
{
	M_StageOrder[STAGE0] = { LEVEL0 };
	M_StageOrder[STAGE1] = { LEVEL1 };
	M_StageOrder[STAGE2] = { LEVEL2 };
	M_StageOrder[STAGE3] = { LEVEL3 };
	M_StageOrder[STAGE4] = { LEVEL4 };
	M_StageOrder[STAGE5] = { LEVEL5 };
	M_StageOrder[STAGE6] = { LEVEL6 };
	M_StageOrder[STAGE7] = { LEVEL7 };
	M_StageOrder[STAGE8] = { LEVEL8 };
	M_StageOrder[STAGE9] = { LEVEL9 };
}

void Stage::GroundDataSet(int Y, int X, int Data)
{
	S_MapData[Y][X].M_GroundData = Data;
}
void Stage::SkyDataSet(int Y, int X, int Data)
{
	S_MapData[Y][X].M_SkyData = Data;
}

void Stage::MapToCopy()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			S_MapData[Y][X].M_IceOn = S_Level[M_StageOrder[P_Game->GetLevel()]][Y][X].M_IceOn;

			S_MapData[Y][X].M_BlockOn = S_Level[M_StageOrder[P_Game->GetLevel()]][Y][X].M_BlockOn;
			S_MapData[Y][X].M_NonBlockOn = S_Level[M_StageOrder[P_Game->GetLevel()]][Y][X].M_NonBlockOn;

			S_MapData[Y][X].M_HoleOn = S_Level[M_StageOrder[P_Game->GetLevel()]][Y][X].M_HoleOn;

			S_MapData[Y][X].M_WeightBoardOn = S_Level[M_StageOrder[P_Game->GetLevel()]][Y][X].M_WeightBoardOn;

			S_MapData[Y][X].M_KaidanOn = S_Level[M_StageOrder[P_Game->GetLevel()]][Y][X].M_KaidanOn;
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
	switch (P_Game->GetLevel())
	{
	case LEVEL0:
		FilePath = "Assets/Level/Level0/Ice.txt";
		break;
	case LEVEL1:
		return 1;
		break;
	case LEVEL2:
		FilePath = "Assets/Level/Level2/Ice.txt";
		break;
	case LEVEL3:
		FilePath = "Assets/Level/Level3/Ice.txt";
		break;
	case LEVEL4:
		FilePath = "Assets/Level/Level4/Ice.txt";
		break;
	case LEVEL5:
		FilePath = "Assets/Level/Level5/Ice.txt";
		break;
	case LEVEL6:
		FilePath = "Assets/Level/Level6/Ice.txt";
		break;
	case LEVEL7:
		FilePath = "Assets/Level/Level7/Ice.txt";
		break;
	case LEVEL8:
		FilePath = "Assets/Level/Level8/Ice.txt";
		break;
	case LEVEL9:
		FilePath = "Assets/Level/Level9/Ice.txt";
		break;
	default:
		break;
	}
	FILE* FilePointer = nullptr;

	fopen_s(&FilePointer, FilePath, "r");

	if (FilePointer == NULL)
	{
		
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
		}
		else {
			if (LevelValue == 99)
			{
				if (Value[0] != '\n')
				{
					int Count = atoi(Value);
					LevelValue = Count;
				}
			}
			else {
				if (Y == 99)
				{
					if (Value[0] != '\n')
					{
						int Count = atoi(Value);
						Y = Count;
					}
				}
				else {
					if (X == 99)
					{
						if (Value[0] != '\n')
						{
							int Count = atoi(Value);
							X = Count;
							S_Level[LevelValue][Y][X].M_IceOn = true;
						}
					}
				}
			}
		}
	}
	fclose(FilePointer);
	
}
int Stage::LevelHoleSet()
{
	const char* FilePath = nullptr;
	switch (P_Game->GetLevel())
	{
	case LEVEL0:
		FilePath = "Assets/Level/Level0/Hole.txt";
		break;
	case LEVEL1:
		FilePath = "Assets/Level/Level1/Hole.txt";
		break;
	case LEVEL2:
		FilePath = "Assets/Level/Level2/Hole.txt";
		break;
	case LEVEL3:
		FilePath = "Assets/Level/Level3/Hole.txt";
		break;
	case LEVEL4:
		FilePath = "Assets/Level/Level4/Hole.txt";
		break;
	case LEVEL5:
		FilePath = "Assets/Level/Level5/Hole.txt";
		break;
	case LEVEL6:
		FilePath = "Assets/Level/Level6/Hole.txt";
		break;
	case LEVEL7:
		FilePath = "Assets/Level/Level7/Hole.txt";
		break;
	case LEVEL8:
		FilePath = "Assets/Level/Level8/Hole.txt";
		break;
	case LEVEL9:
		FilePath = "Assets/Level/Level9/Hole.txt";
		break;
	default:
		break;
	}
	FILE* FilePointer = nullptr;

	fopen_s(&FilePointer, FilePath, "r");

	if (FilePointer == NULL)
	{
		
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
		}
		else {
			if (LevelValue == 99)
			{
				if (Value[0] != '\n')
				{
					int Count = atoi(Value);
					LevelValue = Count;
				}
			}
			else {
				if (Y == 99)
				{
					if (Value[0] != '\n')
					{
						int Count = atoi(Value);
						Y = Count;
					}
				}
				else {
					if (X == 99)
					{
						if (Value[0] != '\n')
						{
							int Count = atoi(Value);
							X = Count;
							S_Level[LevelValue][Y][X].M_HoleOn = true;
						}
					}
				}
			}
		}
	}
	fclose(FilePointer);
	
}
int Stage::LevelBlockSet()
{
	const char* FilePath = nullptr;
	switch (P_Game->GetLevel())
	{
	case LEVEL0:
		FilePath = "Assets/Level/Level0/Block.txt";
		break;
	case LEVEL1:
		FilePath = "Assets/Level/Level1/Block.txt";
		break;
	case LEVEL2:
		FilePath = "Assets/Level/Level2/Block.txt";
		break;
	case LEVEL3:
		FilePath = "Assets/Level/Level3/Block.txt";
		break;
	case LEVEL4:
		FilePath = "Assets/Level/Level4/Block.txt";
		break;
	case LEVEL5:
		FilePath = "Assets/Level/Level5/Block.txt";
		break;
	case LEVEL6:
		FilePath = "Assets/Level/Level6/Block.txt";
		break;
	case LEVEL7:
		FilePath = "Assets/Level/Level7/Block.txt";
		break;
	case LEVEL8:
		FilePath = "Assets/Level/Level8/Block.txt";
		break;
	case LEVEL9:
		FilePath = "Assets/Level/Level9/Block.txt";
		break;
	default:
		break;
	}
	FILE* FilePointer = nullptr;

	fopen_s(&FilePointer, FilePath, "r");

	if (FilePointer == NULL)
	{
		
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
		}
		else {
			if (Value[0] == 'N')
			{
				S_Level[LevelValue][Y][X].M_NonBlockOn = true;
			}
			else {
				if (LevelValue == 99)
				{
					if (Value[0] != '\n')
					{
						int Count = atoi(Value);
						LevelValue = Count;
					}
				}
				else {
					if (Y == 99)
					{
						if (Value[0] != '\n')
						{
							int Count = atoi(Value);
							Y = Count;
						}
					}
					else {
						if (X == 99)
						{
							if (Value[0] != '\n')
							{
								int Count = atoi(Value);
								X = Count;
								S_Level[LevelValue][Y][X].M_BlockOn = true;
							}
						}
					}
				}
			}
		}
	}
	fclose(FilePointer);
	
}
int Stage::LevelKaidanSet()
{
	const char* FilePath = nullptr;
	switch (P_Game->GetLevel())
	{
	case LEVEL0:
		FilePath = "Assets/Level/Level0/Kaidan.txt";
		break;
	case LEVEL1:
		FilePath = "Assets/Level/Level1/Kaidan.txt";
		break;
	case LEVEL2:
		FilePath = "Assets/Level/Level2/Kaidan.txt";
		break;
	case LEVEL3:
		FilePath = "Assets/Level/Level3/Kaidan.txt";
		break;
	case LEVEL4:
		FilePath = "Assets/Level/Level4/Kaidan.txt";
		break;
	case LEVEL5:
		FilePath = "Assets/Level/Level5/Kaidan.txt";
		break;
	case LEVEL6:
		FilePath = "Assets/Level/Level6/Kaidan.txt";
		break;
	case LEVEL7:
		FilePath = "Assets/Level/Level7/Kaidan.txt";
		break;
	case LEVEL8:
		FilePath = "Assets/Level/Level8/Kaidan.txt";
		break;
	case LEVEL9:
		FilePath = "Assets/Level/Level9/Kaidan.txt";
		break;
	default:
		break;
	}
	FILE* FilePointer = nullptr;

	fopen_s(&FilePointer, FilePath, "r");

	if (FilePointer == NULL)
	{
		
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
		}
		else {
			if (LevelValue == 99)
			{
				if (Value[0] != '\n')
				{
					int Count = atoi(Value);
					LevelValue = Count;
				}
			}
			else {
				if (Y == 99)
				{
					if (Value[0] != '\n')
					{
						int Count = atoi(Value);
						Y = Count;
					}
				}
				else {
					if (X == 99)
					{
						if (Value[0] != '\n')
						{
							int Count = atoi(Value);
							X = Count;
							S_Level[LevelValue][Y][X].M_KaidanOn = true;
						}
					}
				}
			}
		}
	}
	fclose(FilePointer);
	
}
int Stage::LevelWeightBoardSet()
{
	const char* FilePath = nullptr;
	switch (P_Game->GetLevel())
	{
	case LEVEL0:
		FilePath = "Assets/Level/Level0/WeightBoard.txt";
		break;
	case LEVEL1:
		FilePath = "Assets/Level/Level1/WeightBoard.txt";
		break;
	case LEVEL2:
		FilePath = "Assets/Level/Level2/WeightBoard.txt";
		break;
	case LEVEL3:
		FilePath = "Assets/Level/Level3/WeightBoard.txt";
		break;
	case LEVEL4:
		FilePath = "Assets/Level/Level4/WeightBoard.txt";
		break;
	case LEVEL5:
		FilePath = "Assets/Level/Level5/WeightBoard.txt";
		break;
	case LEVEL6:
		FilePath = "Assets/Level/Level6/WeightBoard.txt";
		break;
	case LEVEL7:
		FilePath = "Assets/Level/Level7/WeightBoard.txt";
		break;
	case LEVEL8:
		FilePath = "Assets/Level/Level8/WeightBoard.txt";
		break;
	case LEVEL9:
		FilePath = "Assets/Level/Level9/WeightBoard.txt";
		break;
	default:
		break;
	}
	FILE* FilePointer = nullptr;

	fopen_s(&FilePointer, FilePath, "r");

	if (FilePointer == NULL)
	{
		
		return 0;
	}

	int LevelValue = 99, Y = 99, X = 99;
	int  Order = 99, Number10 = 99, Number1 = 99;
	int LinkObject = 99;
	int LinkCount = 0;
	bool Step1 = false, Step2 = false, Step3 = false;
	bool FullReset = false, MiddleReset = false;
	char Value[256];
	while (fgets(Value, 2, FilePointer) != NULL)
	{

		if (MiddleReset)
		{
			Order = 99;
			Number10 = 99;
			Number1 = 99;
			LinkObject = 99;
			MiddleReset = false;
		}
		else {
			if (FullReset)
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

		if (!Step1)
		{
			if (Value[0] == 'X')
			{
				Step1 = true;
			}
			else {
				if (LevelValue == 99)
				{
					if (Value[0] != '\n')
					{
						int Count = atoi(Value);
						LevelValue = Count;
					}
				}
				else {
					if (Y == 99)
					{
						if (Value[0] != '\n')
						{
							int Count = atoi(Value);
							Y = Count;
						}
					}
					else {
						if (X == 99)
						{
							if (Value[0] != '\n')
							{
								int Count = atoi(Value);
								X = Count;
								S_Level[LevelValue][Y][X].M_WeightBoardOn = true;
							}
						}
					}
				}
			}
		}
		else {
			if (Step1 && !Step2)
			{
				if (Value[0] == 'Y')
				{
					Step2 = true;
				}
				else {
					if (Order == 99)
					{
						if (Value[0] != '\n')
						{
							int Count = atoi(Value);
							Order = Count;
						}
					}
					else {
						if (Number10 == 99)
						{
							if (Value[0] != '\n')
							{
								int Count = atoi(Value);
								Number10 = Count;
							}
						}
						else {
							if (Number1 == 99)
							{
								if (Value[0] != '\n')
								{
									int Count = atoi(Value);
									Number1 = Count;
									S_Level[LevelValue][Y][X].M_WeightBoardLinkNumber[Order] = (Number10 * 10) + Number1;
								}
							}
						}
					}
				}
			}
			else {
				if (Step1 && Step2 && !Step3)
				{
					if (Value[0] == 'Z')
					{
						Step2 = false;
						MiddleReset = true;
					}
					else {
						if (Value[0] == 'F')
						{
							Step3 = true;
							FullReset = true;
						}
						else {
							if (LinkObject == 99)
							{
								if (Value[0] != '\n')
								{
									int Count = atoi(Value);
									LinkObject = Count;
									S_Level[LevelValue][Y][X].M_WeightBoardLinkObject[Order] = LinkObject;
									LinkCount++;
									S_Level[LevelValue][Y][X].M_WeightBoardLinkCount = LinkCount;
								}
							}
						}
					}
				}
			}
		}
	}
	fclose(FilePointer);
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
			if (S_MapData[Y][X].M_HoleOn)
			{
				GroundDataSet(Y, X, HOLE);
			}else {
				if (S_MapData[Y][X].M_IceOn)
				{
					S_Map.P_Ice->IceFloorOnTrue(Y, X);
					S_Map.P_Ice->IceFloorSetPosition(Y, X, M_MapPosition[Y][X]);
					GroundDataSet(Y, X, ICE);
				}else {
					S_Map.P_Ground->GroundOnTrue(Y, X);
					S_Map.P_Ground->GroundSetPosition(Y, X, M_MapPosition[Y][X]);
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
			if (S_MapData[Y][X].M_KaidanOn)
			{
				S_Map.P_Kaidan->MapSetPosition(M_MapPosition[Y][X]);
				SkyDataSet(Y, X, KAIDAN);
			}
			else {
				if (S_MapData[Y][X].M_WeightBoardOn)
				{
					for (int W = 1; W < S_Level[M_StageOrder[P_Game->GetLevel()]][Y][X].M_WeightBoardLinkCount + 1; W++)
					{
						S_Map.P_Weightboard->LinkNumberSet(Y, X, W, S_Level[M_StageOrder[P_Game->GetLevel()]][Y][X].M_WeightBoardLinkNumber[W]);
						S_Map.P_Weightboard->LinkObjectSet(Y, X, W, S_Level[M_StageOrder[P_Game->GetLevel()]][Y][X].M_WeightBoardLinkObject[W]);
					}
					S_Map.P_Weightboard->LinkCountSet(Y, X, S_Level[M_StageOrder[P_Game->GetLevel()]][Y][X].M_WeightBoardLinkCount);
					S_Map.P_Weightboard->WeightBoardOnTrue(Y, X);
					S_Map.P_Weightboard->WeightBoardSetPosition(Y, X, M_MapPosition[Y][X]);
					SkyDataSet(Y, X, WEIGHTBOARD);
				}
				else {
					if (S_MapData[Y][X].M_BlockOn)
					{
						if (S_MapData[Y][X].M_NonBlockOn) { S_Map.P_Block->BlockOn(Y, X); }
						S_Map.P_Block->BlockSetPosition(Y, X, M_MapPosition[Y][X]);
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
	case PLAYERDIRECTION_UP:
		return S_MapData[(Map / 10) - 1][(Map % 10)].M_GroundData;
		break;
	case PLAYERDIRECTION_DOWN:
		return S_MapData[(Map / 10) + 1][(Map % 10)].M_GroundData;
		break;
	case PLAYERDIRECTION_RIGHT:
		return S_MapData[(Map / 10)][(Map % 10) + 1].M_GroundData;
		break;
	case PLAYERDIRECTION_LEFT:
		return S_MapData[(Map / 10)][(Map % 10) - 1].M_GroundData;
		break;
	default:
		if (Map == 0)
		{
			return S_MapData[0][0].M_GroundData;
		}
		else {
			return S_MapData[(Map / 10)][(Map % 10)].M_GroundData;
		}
		break;
	}
}
int Stage::GetSkyData(int Map, int Direction)
{
	switch (Direction)
	{
	case PLAYERDIRECTION_UP:
		return S_MapData[(Map / 10) - 1][(Map % 10)].M_SkyData;
		break;
	case PLAYERDIRECTION_DOWN:
		return S_MapData[(Map / 10) + 1][(Map % 10)].M_SkyData;
		break;
	case PLAYERDIRECTION_RIGHT:
		return S_MapData[(Map / 10)][(Map % 10) + 1].M_SkyData;
		break;
	case PLAYERDIRECTION_LEFT:
		return S_MapData[(Map / 10)][(Map % 10) - 1].M_SkyData;
		break;
	default:
		return S_MapData[(Map / 10)][(Map % 10)].M_SkyData;
		break;
	}
}