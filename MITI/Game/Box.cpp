#include "stdafx.h"
#include "Box.h"

Box::Box()
{
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			/*Box_P[L][R].x = (L * 192.0f) + -865.0f;
			Box_P[L][R].y = 100.0f;
			Box_P[L][R].z = (R * 192.0f) + -865.0f;
			box[L][R].CreateBox(Box_P[L][R], Quaternion::Identity, Vector3::One * 300.0f);*/
			box[L][R].CreateBox(Vector3(-2000.0f,-2000.0f,-2000.0f), Quaternion::Identity, Vector3::One * 270.0f);
		}
	}
	//ã
	box_soto[0].CreateBox(Vector3(-1057.0f, 0.0, 0.0f), Quaternion(0.0f, 0.0f, 0.0f, 1.0f), Vector3(270.0f, 270.0f, 1920.0f));
	//‰º
	box_soto[1].CreateBox(Vector3(1057.0f, 0.0, 0.0f), Quaternion(0.0f, 0.0f, 0.0f, 1.0f), Vector3(270.0f, 270.0f, 1920.0f));
	//‰E
	box_soto[2].CreateBox(Vector3(0.0f, 0.0, 1057.0f), Quaternion(0.0f, 90.0f, 0.0f, 1.0f), Vector3(1920.0f, 270.0f, 270.0f));
	//¶
	box_soto[3].CreateBox(Vector3(0.0f, 0.0, -1057.0f), Quaternion(0.0f, 90.0f, 0.0f, 1.0f), Vector3(1920.0f, 270.0f, 270.0f));
}