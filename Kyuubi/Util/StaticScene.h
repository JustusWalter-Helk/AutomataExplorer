#pragma once

#include <iostream>

#include "Base.h"
#include "Scene.h"

namespace Kyuubi {
    class StaticScene : public Scene {
        void addObject(Object&) override {KYEngine("void addObject(Object&) is not available in a static scene!")};
        void addObject(std::vector<Object> newObjects) override { KYEngine("void addObject(std::vector<Object>) is not available in a static scene!") };

        virtual void draw(Scope<Window> window, SDL_Renderer* renderer);
    };
}

