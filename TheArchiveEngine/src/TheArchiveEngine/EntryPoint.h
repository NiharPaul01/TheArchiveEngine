#pragma once

#ifdef AE_PLATFORM_WINDOWS


extern TheArchiveEngine::Application* TheArchiveEngine::CreateApplication();

int main(int argc, char** argv) {
	
	TheArchiveEngine::Log::Init();
	AE_CORE_WARN("Initial setup of Log CoreLogger");
	int a = 5;
	AE_INFO("Hello Var={0}" , a);

	auto app = TheArchiveEngine::CreateApplication();

	
	app->Run();
	delete app;
}

#endif