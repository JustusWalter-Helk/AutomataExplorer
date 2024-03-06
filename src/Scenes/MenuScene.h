#pragma once

#include "StaticScene.h"
#include "DearImGui.h"

using namespace Kyuubi;

namespace AutomataExplorer {
	class MenuScene : public StaticScene{
	public:
		void draw(SDL_Renderer* renderer) override;
	};
}