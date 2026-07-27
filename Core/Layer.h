#pragma once

#include "Window.h"
#include <SFML/Graphics.hpp>

namespace Core
{
    class Layer
    {
      public:
        virtual ~Layer() = default;

        virtual void OnAttach() = 0;
        virtual bool OnEvent(const sf::Event& event) = 0;
        virtual void OnUpdate(float timeStep) = 0;
        virtual void OnRender(Core::Window& window) = 0;

      private:
    };
} // namespace Core
