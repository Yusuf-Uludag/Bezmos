#pragma once

#include "Layer.h"
#include "Window.h"
#include <SFML/Window/Event.hpp>
#include <memory>
#include <string>

namespace Core
{
    struct AppConfig
    {
        std::string name = "App";
        WindowConfig windowSpec;
    };

    class App
    {
      public:
        App(const AppConfig& config);
        ~App();

        void Run();
        void Stop();

        void PushLayer(std::unique_ptr<Layer> layer);

        void RaiseEvent(const sf::Event& event);

      private:
        AppConfig m_config;
        std::unique_ptr<Window> m_window;
        bool m_running = false;
        std::vector<std::unique_ptr<Layer>> m_layerStack;
    };
} // namespace Core