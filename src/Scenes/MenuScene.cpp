#include "MenuScene.h"

void AutomataExplorer::MenuScene::draw(Scope<Window> window, SDL_Renderer* renderer) {
	DearImGui::Initialize(static_cast<SDL_Window*>(window->GetNativeWindow()), renderer);

	ImGui::Begin("Hallo");

	ImGui::Text("Hi");

	ImGui::End();
}
