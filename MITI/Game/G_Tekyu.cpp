#include "stdafx.h"
#include "G_Tekyu.h"

G_Tekyu::G_Tekyu()
{
	srand((unsigned int)time(NULL));
	//modelRender.SetRaytracingWorld(false);
	//ballState = rand() % 2;

	//�J���p���W
	Tpos = (Vector3(0.565, 5.0, 230.0));

	modelRender.Init("Assets/modelData/tekyu/tekyu8.tkm");
	
	m_physicsSphereObject.CreateCylinder(48.0f,
		Tpos, rotation, 0.0f, 1.0f);
	m_physicsSphereObject.SetFriction(10.0f);
}

G_Tekyu::~G_Tekyu()
{
	DeleteGO(this);
}

//�X�V�����B
void G_Tekyu::Update()
{

	if (Tpos.y <= -400.0f && Tpos.y >= -415.0f) {
		DeleteGO(this);
		//MessageBoxA(nullptr, "�{�[�����������܂�", "�m�F", MB_OK);
	}

	m_physicsSphereObject.GetRigidBody()->GetPositionAndRotation(Tpos, rotation);
	modelRender.SetPosition(Tpos);
	modelRender.SetRotation(rotation);

	//�G�`������̍X�V�����B
	modelRender.Update();
}

void G_Tekyu::PlayMusic()
{

}

//�`�揈���B
void G_Tekyu::Render(RenderContext& rc)
{
	//���f����`�悷��B
	modelRender.Draw(rc);
}