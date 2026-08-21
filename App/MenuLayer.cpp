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
    if (!ImGui::GetCurrentContext()) return;

    ImGuiWindowFlags staticFlags = ImGuiWindowFlags_NoMove | 
                                   ImGuiWindowFlags_NoResize | 
                                   ImGuiWindowFlags_NoCollapse;

    float padding = 20.0f;

    ImGui::SetNextWindowPos(ImVec2(padding, padding), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(360.0f, 680.0f), ImGuiCond_Always);

    ImGui::Begin("LeftPanel", nullptr, staticFlags | ImGuiWindowFlags_NoTitleBar);
    {
        ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.7f, 0.2f, 0.9f, 1.0f)); // Purple border
        ImGui::BeginChild("Curve1Card", ImVec2(0, 180.0f), true);
        {
            ImGui::TextColored(ImVec4(0.8f, 0.4f, 1.0f, 1.0f), "Curve 1");
            ImGui::Spacing();

            if (ImGui::Button("AddPoint", ImVec2(140.0f, 35.0f)))
            {

            }
            ImGui::SameLine();
            if (ImGui::Button("RemovePoint", ImVec2(140.0f, 35.0f)))
            {

            }

            ImGui::Spacing();
            ImGui::Separator();
            ImGui::Spacing();

            for (int i = 0; i < 5; ++i)
            {
                ImGui::PushID(i);
                ImGui::Button("##PointBox", ImVec2(45.0f, 30.0f));
                if (i < 4) ImGui::SameLine();
                ImGui::PopID();
            }
        }
        ImGui::EndChild();
        ImGui::PopStyleColor();
    }
    ImGui::End();

    ImGui::SetNextWindowPos(ImVec2(400.0f, padding), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(860.0f, 50.0f), ImGuiCond_Always);

    ImGui::Begin("TitlePanel", nullptr, staticFlags | ImGuiWindowFlags_NoTitleBar);
    {
        float windowWidth = ImGui::GetWindowSize().x;
        float textWidth = ImGui::CalcTextSize("Bezmos").x;
        ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
        ImGui::Text("Bezmos");
    }

    ImGui::End();

    ImGui::SetNextWindowPos(ImVec2(400.0f, 590.0f), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(860.0f, 110.0f), ImGuiCond_Always);

    ImGui::Begin("BottomPanel", nullptr, staticFlags | ImGuiWindowFlags_NoTitleBar);
    {
        ImGui::AlignTextToFramePadding();
        ImGui::Button("tSlider", ImVec2(100.0f, 40.0f));
        
        ImGui::SameLine();
        ImGui::SetNextItemWidth(710.0f);
        ImGui::SliderFloat("##tValue", &m_tValue, 0.0f, 1.0f);
    }
    ImGui::End();
}