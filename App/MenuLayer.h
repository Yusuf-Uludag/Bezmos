#include "Core/Layer.h"

class MenuLayer : public Core::Layer
{
  public:
    MenuLayer();
    virtual ~MenuLayer();

    void OnAttach() override;
    bool OnEvent(const sf::Event& event) override;
    void OnUpdate(float timeStep) override;
    void OnRender(Core::Window& window) override;

  private:
};