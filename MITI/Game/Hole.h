#pragma once
class Hole : public IGameObject
{
public:
	Hole();
	~Hole();
	void Update();
	void Render(RenderContext& rc);
};

