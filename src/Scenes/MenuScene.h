#pragma once

#include "StaticScene.h"
#include "DearImGui.h"
#include "Window.h"

using namespace Kyuubi;

namespace AutomataExplorer {
	class MenuScene : public StaticScene{
	public:
		void draw(Scope<Window> window, SDL_Renderer* renderer) override;
	};
}