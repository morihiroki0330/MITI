#pragma once

#include "level3D/TklFile.h"

namespace nsK2EngineLow
{
	class MapChipRender;

	struct LevelObjectData
	{
		//���W
		Vector3 position;

		//��]
		Quaternion rotation;

		//�g��
		Vector3 scale;

		//�I�u�W�F�N�g�̖��O�@(L"������")
		const wchar_t* name;

		//�ԍ�
		int number = 0;

		//�����񂪓������H
		bool EquaiObjectName(const wchar_t* objName)
		{
			//������̔�r
			return wcscmp(objName, name) == 0;
		}

		//���l���̑O����v���H
		bool ForwardMatchName(const wchar_t* n)
		{
			//wcslen()�͕�����̐������߂�
			auto len = wcslen(n);
			auto namelen = wcslen(name);

			//������̒������r
			if (len > namelen)
			{
				return false;
			}
			
			//������̔�r�@
			//�����F�i������P�j,�i������Q�j,�i���ׂ镶�����j
			return wcsncmp(n, name, len) == 0;

		}
	};

	class LevelRender : public Noncopyable
	{
	private:

		using MapChipRenderPtr = std::shared_ptr<MapChipRender>;

	public:
	//�R���X�g���N�^�E�f�X�g���N�^�E�X�V�E�������E�`��
		//�f�X�g���N�^
		~LevelRender();

		//������
		//�����F�i�t�@�C���̃p�X�j,�i�I�u�W�F�N�g���쐬���鎞�̏������s�Ȃ��֐��j
		void Init(const char* filePath, std::function<bool(LevelObjectData& objData)> hookFunc);

		//�X�V����
		void Update();

		//���f����`��
		void Draw(RenderContext& rc);

	private:

		//�}�b�v�`�b�v�̍쐬
		void CreateMapChipRender(const LevelObjectData& objData, const char* filePath);

		//Tkl�t�@�C���̍s��ϊ�
		void MatrixTklToLevel();

	private:
		using BonePtr = std::unique_ptr<Bone>;								//�{�[��Ptr�B
		std::vector<BonePtr> m_bonelist;									//�{�[���̃��X�g�B
		std::unique_ptr<Matrix[]> m_matrixlist;								//�s��̃��X�g�B
		std::map<std::string, MapChipRenderPtr> m_mapChipRenderPtrs;		//�}�b�v�`�b�v�̉ϒ��z��B
		TklFile m_tklFile;													//Tkl�t�@�C���B
	};
}
