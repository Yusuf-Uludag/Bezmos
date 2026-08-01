#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/VertexBuffer.hpp>
// #include <iostream>

class Curve
{
  public:
    size_t size;
    sf::VertexArray points;

    Curve() = default;
    Curve(sf::VertexArray points);

    float GetStepSize();
    void SetStepSize(float stepSize);
    void SetAllSamples();
    sf::Vertex CalculateSample(float t);

    operator sf::VertexBuffer();

  private:
    float m_stepSize;
    sf::VertexBuffer m_samples;
};