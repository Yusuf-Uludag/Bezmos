#include "CanvasLayer.h"

CanvasLayer::CanvasLayer() {}
CanvasLayer::~CanvasLayer() {}
void CanvasLayer::OnAttach() {}
bool CanvasLayer::OnEvent(const sf::Event& event) { return false; }
void CanvasLayer::OnUpdate(float timeStep) {}
void CanvasLayer::OnRender(Core::Window& window) {}