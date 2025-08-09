#include "aepch.h"
#include "Application.h"

#include "TheArchiveEngine/Events/ApplicationEvent.h"
#include "TheArchiveEngine/Log.h"

namespace TheArchiveEngine {
	
	Application::Application() {

	}

	Application::~Application() {

	}
	
	void Application::Run() {

		WindowResizeEvent e(1280, 720);
		
		if (e.IsInCategory(EventCategoryApplication)) {
			AE_TRACE("{}", e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput)) {
			AE_TRACE("{}", e.ToString());
		}
		while (true);
	}
}
