#pragma once
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
	ModelRender KaidanModel;
	Vector3 KaidanPosition = { 0.0f,0.0f,0.0f };
	Vector3 KaidanScale = { 1.0f,1.0f,2.0f };
	Quaternion KaidanRotation;
	AllLight KaidanLight;

	Box* box = nullptr;
};

