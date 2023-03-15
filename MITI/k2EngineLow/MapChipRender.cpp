#include "k2EngineLowPreCompile.h"
#include "MapChipRender.h"
#include "LevelRender.h"

namespace nsK2EngineLow
{
	MapChipRender::MapChipRender(const LevelObjectData& objData, const char* filePath)
	{
		//���f���̃t�@�C���p�X���擾
		m_filePath = std::make_unique<const char*>(filePath);

		//�}�b�v�`�b�v�f�[�^�̒ǉ�
		AddMapChipData(objData);
	}

	MapChipRender::~MapChipRender()
	{

	}

	//���f���̏�����
	void MapChipRender::Init()
	{
		//�f�[�^�̐����A�}�b�v�`�b�v�f�[�^�̕ϐ��𑝂₷
		//��F�f�[�^�̐���4�Ȃ�,�ϐ��̒l��4�ɂ���
		m_mapChipDataNum = static_cast<int>(m_mapChipDataVector.size());

		//�f�[�^�̐�����Ȃ��
		if (m_mapChipDataNum == 1)
		{
			//Tkl�t�@�C���̃f�[�^�ŏ���������
			m_modelRender.Init(*m_filePath.get());

			//�}�b�v�`�b�v�̃f�[�^���\���̂ɑ������
			auto& mapChipData = m_mapChipDataVector[0];

			//���W�E��]�E�g���ݒ肷��
			m_modelRender.SetTRS(mapChipData.position, mapChipData.rotation, mapChipData.scale);
			
			//���f���̍X�V
			m_modelRender.Update();

			//�ÓI�����I�u�W�F�N�g���쐬�B
			auto p = std::make_unique<PhysicsStaticObject>();
			p->CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
			m_physicsStaticObjectPtrVector.push_back(std::move(p));
			return;
		}


		for (auto& mapChipData : m_mapChipDataVector)
		{
			//���[���h�s����v�Z����B
			Matrix worldMatrix = m_modelRender.GetModel().CalcWorldMatrix(mapChipData.position, mapChipData.rotation, mapChipData.scale);
			auto p = std::make_unique<PhysicsStaticObject>();
			//�ÓI�����I�u�W�F�N�g���쐬�B
			p->CreateFromModel(m_modelRender.GetModel(), worldMatrix);
			m_physicsStaticObjectPtrVector.push_back(std::move(p));
		}

	}

	//�X�V
	void MapChipRender::Update()
	{
		//�}�b�v�`�b�v�Ƀf�[�^������ꍇ
		//���f�������_�[�̍X�V
		if (m_mapChipDataNum == 1)
		{
			m_modelRender.Update();
		}
	}

	//�`��
	void MapChipRender::Draw(RenderContext& rc)
	{
		
		m_modelRender.Draw(rc);
	}

	void MapChipRender::AddMapChipData(const LevelObjectData& objData)
	{
		MapChipData mapChipData;
		mapChipData.position = objData.position;
		mapChipData.rotation = objData.rotation;
		mapChipData.scale = objData.scale;
		m_mapChipDataVector.push_back(mapChipData);
	}
}