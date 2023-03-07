#pragma once
namespace nsK2EngineLow
{
	class ModelRender;
	class RenderContext;

	class RenderingEngine : public Noncopyable
	{
	public:
		RenderingEngine();
		~RenderingEngine();

		void Update();

		enum EnEvent
		{
			enEventReInitIBLTexture,
		};

		void AddEventListener
		(
			void* pListenerObj,
			std::function<void(EnEvent enEvent)> listenerFunc
		)
		{
			m_eventListeners.push_back({ pListenerObj, listenerFunc });
		}

		void RemoveEventListener(void* pListenerObj)
		{
			auto it = std::find_if
			(
				m_eventListeners.begin(),
				m_eventListeners.end(),
				[&](const SEventListenerData& listenerData) {return listenerData.pListenerObj == pListenerObj; }
			);
			if (it != m_eventListeners.end())
			{
				m_eventListeners.erase(it);
			}
		}


		void InRenderObject(ModelRender* renderObject)
		{
			m_renderObjects.push_back(renderObject);
		}

		void AddRenderObject(RenderContext& rc);

		void Execute(RenderContext& rc);

	private:

		std::vector<ModelRender*> m_renderObjects;

		struct SEventListenerData
		{
			void* pListenerObj;
			std::function<void(EnEvent enEvent)> listenerFunc;
		};

		std::list<SEventListenerData> m_eventListeners;
	};
}

