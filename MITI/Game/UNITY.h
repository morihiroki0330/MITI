#pragma once
class UNITY : public IGameObject
{
public:
	UNITY();
	~UNITY();
	void Update();
	void Render(RenderContext& rc);

	ModelRender Unity;
};

