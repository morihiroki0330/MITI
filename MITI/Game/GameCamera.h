#pragma once
class Player;
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	void Update();

	Vector3 Target_P;
	Vector3 Camera_P;

	Player* player;
};

