#include "Window.h"
#include "App.h"
#include <memory>
#include <optional>
#include <imgui-SFML.h>

namespace Core
{
    Window::Window(const WindowConfig& config)
        : config(config)
    {}

    void Window::Create()
    {
        renderWindow = std::make_unique<sf::RenderWindow>(
            sf::VideoMode({config.width, config.height}), config.title,
            config.fullScreen ? sf::State::Fullscreen : sf::State::Windowed);

        renderWindow->setVerticalSyncEnabled(config.vsyncEnabled);
        renderWindow->setFramerateLimit(config.fpsLimit);
        renderWindow->setKeyRepeatEnabled(config.keyRepeat);

        // INITIALIZE IMGUI HERE!
        if (!ImGui::SFML::Init(*renderWindow))
        {
            // Failed to initialize ImGui
        }
    }

    void Window::Close()
    {
        if (renderWindow) 
        { 
            // SHUTDOWN IMGUI CLEANLY
            ImGui::SFML::Shutdown(*renderWindow);
            renderWindow->close(); 
        }
    }

    bool Window::ShouldClose() const { return !renderWindow->isOpen(); }

    void Window::PollEvents(App * app)
    {
        while (const std::optional event = renderWindow->pollEvent())
        {
            if (event.has_value()) { app->RaiseEvent(event.value()); }
        }
    }

    void Window::Clear() { renderWindow->clear(); }

    void Window::Display() { renderWindow->display(); }

    /* Do not call before Create() or after Destroy() */
    sf::RenderWindow& Window::GetRenderWindow() { return *renderWindow; }

} // namespace Core