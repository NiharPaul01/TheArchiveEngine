#pragma once


#include "Core.h"
#include "Window.h"
#include "TheArchiveEngine/LayerStack.h"
#include "TheArchiveEngine/Events/Event.h"
#include "TheArchiveEngine/Events/ApplicationEvent.h"



namespace TheArchiveEngine {
	class THEARCHIVEENGINE_API Application {
		  

	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:

		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To be Defined in CLIENT
	Application* CreateApplication();

}

