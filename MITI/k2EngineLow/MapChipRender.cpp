#include "k2EngineLowPreCompile.h"
#include "MapChipRender.h"
#include "LevelRender.h"

namespace nsK2EngineLow
{
	MapChipRender::MapChipRender(const LevelObjectData& objData, const char* filePath)
	{
		//モデルのファイルパスを取得
		m_filePath = std::make_unique<const char*>(filePath);

		//マップチップデータの追加
		AddMapChipData(objData);
	}

	MapChipRender::~MapChipRender()
	{

	}

	//モデルの初期化
	void MapChipRender::Init()
	{
		//データの数分、マップチップデータの変数を増やす
		//例：データの数が4なら,変数の値を4にする
		m_mapChipDataNum = static_cast<int>(m_mapChipDataVector.size());

		//データの数が一個ならば
		if (m_mapChipDataNum == 1)
		{
			//Tklファイルのデータで初期化する
			m_modelRender.Init(*m_filePath.get());

			//マップチップのデータを構造体に代入する
			auto& mapChipData = m_mapChipDataVector[0];

			//座標・回転・拡大を設定する
			m_modelRender.SetTRS(mapChipData.position, mapChipData.rotation, mapChipData.scale);
			
			//モデルの更新
			m_modelRender.Update();

			//静的物理オブジェクトを作成。
			auto p = std::make_unique<PhysicsStaticObject>();
			p->CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
			m_physicsStaticObjectPtrVector.push_back(std::move(p));
			return;
		}


		for (auto& mapChipData : m_mapChipDataVector)
		{
			//ワールド行列を計算する。
			Matrix worldMatrix = m_modelRender.GetModel().CalcWorldMatrix(mapChipData.position, mapChipData.rotation, mapChipData.scale);
			auto p = std::make_unique<PhysicsStaticObject>();
			//静的物理オブジェクトを作成。
			p->CreateFromModel(m_modelRender.GetModel(), worldMatrix);
			m_physicsStaticObjectPtrVector.push_back(std::move(p));
		}

	}

	//更新
	void MapChipRender::Update()
	{
		//マップチップにデータがある場合
		//モデルレンダーの更新
		if (m_mapChipDataNum == 1)
		{
			m_modelRender.Update();
		}
	}

	//描画
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