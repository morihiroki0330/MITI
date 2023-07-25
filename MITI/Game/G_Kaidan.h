#pragma once
#include "NumberStorage.h"
class Box;
class G_Kaidan : public IGameObject
{
public:
	G_Kaidan();
	bool Start();

	void InitModel();

	void Map_SetPosition(Vector3 Position);

	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender M_KaidanModel;
	Vector3 M_KaidanPosition = { 0.0f,0.0f,0.0f };
	Vector3 M_KaidanScale = { 1.0f,1.0f,2.0f };
	AllLight M_KaidanLight;

	Box* P_Box = nullptr;

	GridPosition S_GridPosition;
};

