#include "stdafx.h"
#include "G_Tekyu.h"

G_Tekyu::G_Tekyu()
{
	srand((unsigned int)time(NULL));
	//modelRender.SetRaytracingWorld(false);
	//ballState = rand() % 2;

	//�J���p���W
	Tpos = (Vector3(50.565, 35.0, 230.0));

	modelRender.Init("Assets/modelData/tekyu/tekyu9.tkm");
	
	//���̋K��T�C�Y��35.0�Ƃ���B
	m_physicsSphereObject.CreateCylinder(35.0f,
		Tpos, rotation, 0.0f, 1000.0f);
	m_physicsSphereObject.SetFriction(10.0f);
}

G_Tekyu::~G_Tekyu()
{
	DeleteGO(this);
}

//�X�V�����B
void G_Tekyu::Update()
{

	if (Tpos.y <= -300.0f && Tpos.y >= -315.0f) {
		DeleteGO(this);
		MessageBoxA(nullptr, "�{�[�����������܂�", "�m�F", MB_OK);
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