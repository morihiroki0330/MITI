#pragma once
namespace nsK2EngineLow
{
	class Geometry
	{
	public:
		bool IsInViewFrustum() const
		{
			return m_isInViewFrustum;
		}
		bool m_isInViewFrustum = false;
	};
}
