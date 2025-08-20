#include<aepch.h>
#include <TheArchiveEngine.h>


class ExampleLayer : public TheArchiveEngine::Layer {
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override {
		AE_INFO("ExampleLayer::Update");
	}

	void OnEvent(TheArchiveEngine::Event& event) override {
		
		AE_TRACE("{}", event.ToString());
	}
};









class Sandbox : public TheArchiveEngine::Application {


public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new TheArchiveEngine::ImGuiLayer());

	}

	~Sandbox() {

	}
};

TheArchiveEngine::Application* TheArchiveEngine::CreateApplication() {
	return new Sandbox();
}