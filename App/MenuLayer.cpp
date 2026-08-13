#include "MenuLayer.h"
#include <imgui.h>

MenuLayer::MenuLayer() {}
MenuLayer::~MenuLayer() {}
void MenuLayer::OnAttach() {}
bool MenuLayer::OnEvent(const sf::Event& event) 
{
    bool wantCaptureMouse = ImGui::GetIO().WantCaptureMouse;

    if (wantCaptureMouse && (event.is<sf::Event::MouseButtonPressed>() || event.is<sf::Event::MouseButtonReleased>())) {
        return true;
    }
    return false;
}
void MenuLayer::OnUpdate(float timeStep)
{
    if (m_isAnimating)
    {
        m_tValue += timeStep * 0.5f;
        if (m_tValue > 1.0f)
            m_tValue = 0.0f;
    }
}
void MenuLayer::OnRender(Core::Window& window)
{
    ImGui::Begin("Bezmos Control Panel");

    ImGui::SliderFloat("t Parameter", &m_tValue, 0.0f, 1.0f);
    ImGui::Checkbox("Show Vertices", &m_showVertices);

    if (m_isAnimating)
    {
        if (ImGui::Button("Pause Animation"))
            m_isAnimating = false;
    }
    else
    {
        if (ImGui::Button("Start Animation"))
            m_isAnimating = true;
    }

    ImGui::End();
}