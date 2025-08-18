#pragma once

#include "TheArchiveEngine/Core.h"
#include "Layer.h"

#include <vector>

namespace TheArchiveEngine {
	class THEARCHIVEENGINE_API LayerStack {
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* Overlayer);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* Overlayer);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;

	};
}