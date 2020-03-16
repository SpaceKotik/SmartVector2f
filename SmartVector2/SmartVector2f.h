#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class eVector2f : public sf::Vector2f {
public:
    eVector2f();
    eVector2f(float, float);
    ~eVector2f();
    eVector2f operator+(const Vector2i&) const;
    eVector2f& operator+=(const Vector2i&);
    eVector2f operator-(const Vector2i&) const;
    eVector2f& operator-=(const Vector2i&);

    eVector2f& operator=(const Vector2f&);
    bool operator==(const Vector2i&) const;
    bool operator!=(const Vector2i&) const;

    eVector2f operator-() const;

    float operator*(const eVector2f&) const;
    float operator^(const eVector2f&) const;
    float operator*(const Vector2i&) const;
    float operator^(const Vector2i&) const;
    float operator*(const Vector2f&) const;
    float operator^(const Vector2f&) const;

    eVector2f operator*(float k);
    eVector2f& operator*=(float k);
    eVector2f operator/(float k);
    eVector2f& operator/=(float k);

    float len() const;
    float squareLen() const;
    eVector2f norm();
    eVector2f perp() const;
    eVector2f& rotate(float);
    eVector2f getRotate(float) const;
};

std::ostream& operator<<(std::ostream&, const eVector2f&);
std::istream& operator>>(std::istream&, eVector2f&);
