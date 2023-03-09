#pragma once
class UNITY : public IGameObject
{
public:
	UNITY();
	~UNITY();
	void Update();
	void Render(RenderContext& rc);

	ModelRender Unity_M;
	SpriteRender Unity_S;
	Vector3 Unity_P;
};

