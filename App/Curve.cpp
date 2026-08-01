#include "Curve.h"
#include <vector>

unsigned int factorial(unsigned int x)
{
    int product = 1;
    for (int i = 1; i <= x; i++) product *= i;
    return product;
}

unsigned int combination(unsigned int x, unsigned int y)
{
    return factorial(x) / (factorial(x - y) * factorial(y));
}

Curve::Curve(sf::VertexArray points)
    : points(points),
      m_samples(sf::PrimitiveType::LineStrip, sf::VertexBuffer::Usage::Stream)
{
    SetStepSize(0.01);
}

float Curve::GetStepSize()
{
    return m_stepSize + 0;
}

void Curve::SetStepSize(float stepSize)
{
    if (stepSize <= 0) return;
    m_stepSize = stepSize;
    size = 1 / stepSize + 2;
    (void)m_samples.create(size - 1);
}

void Curve::SetAllSamples()
{
    std::vector<sf::Vertex> temp;
    temp.reserve(size);

    temp.emplace_back(points[0]);
    for (float t = m_stepSize; t < 1.0; t += m_stepSize)
    {
        temp.emplace_back(CalculateSample(t));
    }
    temp.emplace_back(points[points.getVertexCount() - 1]);

    (void)m_samples.update(temp.data());
}

sf::Vertex Curve::CalculateSample(float t)
{
    size_t n = points.getVertexCount();

    sf::Vector2f posSum;
    for (int i = 0; i < n; i++)
    {
        posSum += points[i].position * (float)(combination(n - 1, i) * pow(1 - t, n - i - 1) * pow(t, i));
        // std::cout << "i = " << i << " : " << posSum.x << ", " << posSum.y << " = {" << points[i].position.x << ", " << points[i].position.y << "} * " << combination(n - 1, i) << " * " << 1 - t << "^" << n - i - 1 << " * " << t << "^" << i << "\n";
    }
    // std::cout << "\n";
    return sf::Vertex(posSum);
}

Curve::operator sf::VertexBuffer() { return m_samples; }