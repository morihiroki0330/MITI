#pragma once
class Player;
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	void Update();

	//’‹“_
	Vector3 Target_P;

	//‹“_
	Vector3 Camera_P;

	Player* player;
};

