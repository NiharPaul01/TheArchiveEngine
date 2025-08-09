#include<aepch.h>
#include <TheArchiveEngine.h>

class Sandbox : public TheArchiveEngine::Application {


public:
	Sandbox() {


	}

	~Sandbox() {

	}
};

TheArchiveEngine::Application* TheArchiveEngine::CreateApplication() {
	return new Sandbox();
}