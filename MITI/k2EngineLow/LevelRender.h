#pragma once

#include "level3D/TklFile.h"

namespace nsK2EngineLow
{
	class MapChipRender;

	struct LevelObjectData
	{
		//座標
		Vector3 position;

		//回転
		Quaternion rotation;

		//拡大
		Vector3 scale;

		//オブジェクトの名前　(L"文字列")
		const wchar_t* name;

		//番号
		int number = 0;

		//文字列が同じか？
		bool EquaiObjectName(const wchar_t* objName)
		{
			//文字列の比較
			return wcscmp(objName, name) == 0;
		}

		//数値分の前方一致か？
		bool ForwardMatchName(const wchar_t* n)
		{
			//wcslen()は文字列の数を求める
			auto len = wcslen(n);
			auto namelen = wcslen(name);

			//文字列の長さを比較
			if (len > namelen)
			{
				return false;
			}
			
			//文字列の比較　
			//引数：（文字列１）,（文字列２）,（調べる文字数）
			return wcsncmp(n, name, len) == 0;

		}
	};

	class LevelRender : public Noncopyable
	{
	private:

		using MapChipRenderPtr = std::shared_ptr<MapChipRender>;

	public:
	//コンストラクタ・デストラクタ・更新・初期化・描画
		//デストラクタ
		~LevelRender();

		//初期化
		//引数：（ファイルのパス）,（オブジェクトを作成する時の処理を行なう関数）
		void Init(const char* filePath, std::function<bool(LevelObjectData& objData)> hookFunc);

		//更新処理
		void Update();

		//モデルを描画
		void Draw(RenderContext& rc);

	private:

		//マップチップの作成
		void CreateMapChipRender(const LevelObjectData& objData, const char* filePath);

		//Tklファイルの行列変換
		void MatrixTklToLevel();

	private:
		using BonePtr = std::unique_ptr<Bone>;								//ボーンPtr。
		std::vector<BonePtr> m_bonelist;									//ボーンのリスト。
		std::unique_ptr<Matrix[]> m_matrixlist;								//行列のリスト。
		std::map<std::string, MapChipRenderPtr> m_mapChipRenderPtrs;		//マップチップの可変長配列。
		TklFile m_tklFile;													//Tklファイル。
	};
}
