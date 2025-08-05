#pragma once

#ifdef AE_PLATFORM_WINDOWS


extern TheArchiveEngine::Application* TheArchiveEngine::CreateApplication();

int main(int argc, char** argv) {
	
	
	auto app = TheArchiveEngine::CreateApplication();

	
	app->Run();
	delete app;
}

#endif