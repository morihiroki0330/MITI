#pragma once
namespace nsK2EngineLow {
	class IRender : public Noncopyable {
	public:
		virtual void OnRenderShadowMap(
			RenderContext& rc,
			int ligNo,
			int shadowMapNo,
			const Matrix& lvpMatrix
		)
		{

		}

		virtual void OnComputeVertex(RenderContext& rc)
		{

		}

		virtual void OnZPrepass(RenderContext& rc)
		{

		}

		virtual void OnRenderToGBuffer(RenderContext& rc)
		{

		}

		virtual void OnForwardRender(RenderContext& rc)
		{

		}

		virtual void OnTlanslucentRender(RenderContext& rc)
		{

		}

		virtual void OnRender2D(RenderContext& rc)
		{

		}

		virtual void OnRender(RenderContext& rc)
		{

		}

		virtual void GetAABB(Vector3& vMax, Vector3& vMin, bool& isGet)
		{
			vMax.Set(-FLT_MAX, -FLT_MAX, -FLT_MAX);
			vMin.Set(FLT_MAX, FLT_MAX, FLT_MAX);
			isGet = false;
		}

		virtual bool IsShadowCaster() const
		{
			return false;
		}
	};
}

