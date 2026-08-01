#include "Core/Layer.h"
#include "Curve.h"

class CanvasLayer : public Core::Layer
{
  public:
    CanvasLayer();
    virtual ~CanvasLayer();

    void OnAttach() override;
    bool OnEvent(const sf::Event& event) override;
    void OnUpdate(float timeStep) override;
    void OnRender(Core::Window& window) override;

  private:
    sf::VertexArray m_points;
    Curve m_curve;
};