#include "stdafx.h"
#include "G_Tekyu.h"

G_Tekyu::G_Tekyu()
{
	srand((unsigned int)time(NULL));
	//modelRender.SetRaytracingWorld(false);
	//ballState = rand() % 2;

	//開発用座標
	Tpos = (Vector3(50.565, 35.0, 230.0));

	modelRender.Init("Assets/modelData/tekyu/tekyu9.tkm");
	
	//球の規定サイズは35.0とする。
	m_physicsSphereObject.CreateCylinder(35.0f,
		Tpos, rotation, 0.0f, 1000.0f);
	m_physicsSphereObject.SetFriction(10.0f);
}

G_Tekyu::~G_Tekyu()
{
	DeleteGO(this);
}

//更新処理。
void G_Tekyu::Update()
{

	if (Tpos.y <= -300.0f && Tpos.y >= -315.0f) {
		DeleteGO(this);
		MessageBoxA(nullptr, "ボールを消去します", "確認", MB_OK);
	}

	m_physicsSphereObject.GetRigidBody()->GetPositionAndRotation(Tpos, rotation);
	modelRender.SetPosition(Tpos);
	modelRender.SetRotation(rotation);

	//絵描きさんの更新処理。
	modelRender.Update();
}

void G_Tekyu::PlayMusic()
{

}

//描画処理。
void G_Tekyu::Render(RenderContext& rc)
{
	//モデルを描画する。
	modelRender.Draw(rc);
}