#include "CanvasLayer.h"

CanvasLayer::CanvasLayer()
{
    m_points = sf::VertexArray(sf::PrimitiveType::LineStrip, 5);
    m_points[0].position = sf::Vector2f(100, 500);
    m_points[1].position = sf::Vector2f(200, 100);
    m_points[2].position = sf::Vector2f(500, 300);
    m_points[3].position = sf::Vector2f(750, 600);
    m_points[4].position = sf::Vector2f(900, 100);
    m_curve = Curve(m_points);
}

CanvasLayer::~CanvasLayer() {}

void CanvasLayer::OnAttach()
{}

bool CanvasLayer::OnEvent(const sf::Event& event) { return false; }

void CanvasLayer::OnUpdate(float timeStep)
{
    // m_curve.SetStepSize(m_curve.GetStepSize() - 0.001);
    m_curve.SetAllSamples();
}

void CanvasLayer::OnRender(Core::Window& window)
{
    for (int i = 0; i < m_points.getVertexCount(); i++)
    {
        sf::CircleShape temp(2);
        temp.setPosition(m_points[i].position - sf::Vector2f(temp.getRadius(), temp.getRadius()));
        window.GetRenderWindow().draw(temp);
    }
    window.GetRenderWindow().draw(m_curve);
}