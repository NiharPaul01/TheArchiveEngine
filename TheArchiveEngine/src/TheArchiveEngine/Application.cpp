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
		AE_TRACE("{}", e.ToString());

		while (true);
	}
}
