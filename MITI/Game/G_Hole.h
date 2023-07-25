#pragma once
class G_Hole : public IGameObject
{
public:
	G_Hole();
	void InitModel();
	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender M_HoleModel;
	Vector3 M_HolePosition = { 0.0f ,-300.0f,0.0f };
	AllLight M_HoleLight;
};


