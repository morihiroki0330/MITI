#pragma once
//画像の縦幅
struct TextureHeight
{
	const float M_ScreenHeight = 1080.0;
	const float M_ButtonHeight = 150.0;
	const float M_ControllerHeight = 256.0;
	const float M_IronBallHeight = 512.0;
};

//画像の横幅
struct TextureWide
{
	const float M_ScreenWide = 1920.0;
	const float M_ButtonWide = 150.0;
	const float M_ControllerWide = 256.0;
	const float M_IronBallWide = 128.0;
};

//カラー
struct Color
{
	const float	M_Red = 1.0;
	const float	M_HalfRed = 0.5;
	const float	M_Green = 1.0;
	const float	M_HalfGreen = 0.5;
	const float	M_Blue = 1.0;
	const float	M_HalfBlue = 0.5;
	const float M_ResetAlpha = 1.0f;
	const float M_NonAlpha = 0.0f;
};

//フェードの速さ
struct FadeInformation
{
	const float M_FadeHighSpeed = 10.0f;
	const float M_FadeLowSpeed = 1.0f;
};

//範囲外の座標
struct GridPosition
{
	const float M_GridExemptPositionX = -2000.0;
	const float	M_GridExemptPositionY = -2000.0;
	const float	M_GridExemptPositionZ = -2000.0;
};

//サウンド設定
struct SoundSetting
{
	const float M_BgmVolume = 0.5;

	const bool M_Loop = true;
	const bool M_LoopNot = false;
};

//プレイヤー情報
struct PlayerInformation
{
	const float M_CharacterControllerWide = 40.0;
	const float M_CharacterControllerHeight = 120.0;
	const float M_MinMoveSpeed = 0.0f;
};

//ブロックの情報
struct BlockInformation
{
	const float M_BlockHalfX = 96.0;
	const float M_BlockHalfZ = 96.0;
};

//世界の情報
struct WorldInformation
{
	const float M_Gravity = -5.0;
	const float M_UnderHalfLimit = -30.0;
	const float M_UnderLimit = -250.0;
};

struct IronBallInformation
{
	const float IronBallRange = 96.0;
};

const int M_Ymas = 10;
const int M_Xmas = 10;
const int M_IronBallCount = 5;