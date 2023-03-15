#pragma once

namespace nsK2EngineLow
{
	class LevelObjectData;

	struct MapChipData
	{
		//座標
		Vector3 position;

		//回転
		Quaternion rotation;

		//大きさ
		Vector3 scale;
	};

	class MapChipRender : public Noncopyable
	{ 
	public:
		//コンストラクタ
		//Level関数・LevelRender関数で呼び出される
		MapChipRender(const LevelObjectData& objData,const char* filePath);

		//デストラクタ
		~MapChipRender();

		//マップチップデータの追加
		void AddMapChipData(const LevelObjectData& objData);

		//初期化
		void Init();

		//更新
		void Update();

		//描画
		void Draw(RenderContext& rc);

		//モデルレンダラーの取得
		ModelRender& GetSkinModelRender()
		{
			return m_modelRender;
		}

	private:
		ModelRender m_modelRender; //モデルレンダー
		std::vector<MapChipData> m_mapChipDataVector;//マップチープのデータ
		std::unique_ptr<const char*> m_filePath;//Tklファイルパス
		std::vector<std::unique_ptr<PhysicsStaticObject>> m_physicsStaticObjectPtrVector;//PhysicsStaticObjectのスマートポインタの配列。
		int m_mapChipDataNum;//マップチップデータの数。
	};
}


