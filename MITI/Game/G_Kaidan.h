#pragma once
#include "Number_Storage.h"
class Box;
class Game;
class Stage;
enum
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
class G_Kaidan : public IGameObject
{
public:
	bool Start();
	void LevelSet();
	void Map_SetPosition(Vector3 Position);
	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender Kaidan;
	Vector3 Kaidan_Position = { NON,NON,NON };
	Vector3 Kaidan_Scale = { 1.0f,1.0f,2.0f };
	Quaternion Kaidan_Rotation;
	AllLight Light;

	Box* box = nullptr;
	Game* game = nullptr;
	Stage* stage = nullptr;
};

