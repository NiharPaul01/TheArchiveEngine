#pragma once


#include "Core.h"
#include "Events/Event.h"

namespace TheArchiveEngine {
	class THEARCHIVEENGINE_API Application {
		  

	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be Defined in CLIENT
	Application* CreateApplication();

}

