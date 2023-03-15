#pragma once

namespace nsK2EngineLow
{
	class LevelObjectData;

	struct MapChipData
	{
		//���W
		Vector3 position;

		//��]
		Quaternion rotation;

		//�傫��
		Vector3 scale;
	};

	class MapChipRender : public Noncopyable
	{ 
	public:
		//�R���X�g���N�^
		//Level�֐��ELevelRender�֐��ŌĂяo�����
		MapChipRender(const LevelObjectData& objData,const char* filePath);

		//�f�X�g���N�^
		~MapChipRender();

		//�}�b�v�`�b�v�f�[�^�̒ǉ�
		void AddMapChipData(const LevelObjectData& objData);

		//������
		void Init();

		//�X�V
		void Update();

		//�`��
		void Draw(RenderContext& rc);

		//���f�������_���[�̎擾
		ModelRender& GetSkinModelRender()
		{
			return m_modelRender;
		}

	private:
		ModelRender m_modelRender; //���f�������_�[
		std::vector<MapChipData> m_mapChipDataVector;//�}�b�v�`�[�v�̃f�[�^
		std::unique_ptr<const char*> m_filePath;//Tkl�t�@�C���p�X
		std::vector<std::unique_ptr<PhysicsStaticObject>> m_physicsStaticObjectPtrVector;//PhysicsStaticObject�̃X�}�[�g�|�C���^�̔z��B
		int m_mapChipDataNum;//�}�b�v�`�b�v�f�[�^�̐��B
	};
}


