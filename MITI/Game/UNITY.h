#pragma once
class UNITY : public IGameObject
{
public:
	UNITY();
	~UNITY();
	void Update();
	void Render(RenderContext& rc);

	ModelRender Unity_M1;
	ModelRender Unity_M2;
	Vector3 Unity_P1;
	Vector3 Unity_P2;
	Quaternion Unity_R1;
	Quaternion Unity_R2;

	AllLight Unity_L1;
	AllLight Unity_L2;
};

