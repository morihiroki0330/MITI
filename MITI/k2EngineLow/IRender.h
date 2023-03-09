#pragma once
namespace nsK2EngineLow {
	/// レンダーラーの基底クラス。
	class IRender : public Noncopyable {
	public:
		/// シャドウマップへの描画パスから呼ばれる処理。
		virtual void OnRenderShadowMap(
			RenderContext& rc,
			int ligNo,
			int shadowMapNo,
			const Matrix& lvpMatrix
		)
		{

		}

		/// 頂点計算パスから呼ばれる処理。
		virtual void OnComputeVertex(RenderContext& rc)
		{

		}

		/// ZPrepassから呼ばれる処理。
		virtual void OnZPrepass(RenderContext& rc)
		{

		}

		/// G-Buffer描画パスから呼ばれる処理。
		virtual void OnRenderToGBuffer(RenderContext& rc)
		{

		}

		/// フォワードレンダーパスから呼ばれる処理。
		virtual void OnForwardRender(RenderContext& rc)
		{

		}

		/// 半透明オブジェクト描画パスから呼ばれる処理。
		virtual void OnTlanslucentRender(RenderContext& rc)
		{

		}

		/// 2D描画パスから呼ばれる処理。
		virtual void OnRender2D(RenderContext& rc)
		{

		}

		//通常描画パスから呼び出される処理
		virtual void OnRender(RenderContext& rc)
		{

		}

		/// レンダラーが描画するオブジェクトの最大座標と最小座標を取得。
		virtual void GetAABB(Vector3& vMax, Vector3& vMin, bool& isGet)
		{
			vMax.Set(-FLT_MAX, -FLT_MAX, -FLT_MAX);
			vMin.Set(FLT_MAX, FLT_MAX, FLT_MAX);
			isGet = false;
		}



		/// シャドウキャスター？
		virtual bool IsShadowCaster() const
		{
			return false;
		}
	};
}

