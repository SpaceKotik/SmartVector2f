#include "SmartVector2/SmartVector2f.h"
#include "cmath"
#include <SFML/Graphics.hpp>

eVector2f::eVector2f() {
    x = 0;
    y = 0;
}

eVector2f::eVector2f(float x1, float y1) {
    x = x1;
    y = y1;
}

eVector2f::~eVector2f() {
    x = 0;
    y = 0;
}

eVector2f& eVector2f::operator=(const Vector2f& other) {
    x = other.x;
    y = other.y;
    return *this;
}

bool eVector2f::operator==(const Vector2i & other) const {
    return x == other.x && y == other.y;
}

bool eVector2f::operator!=(const Vector2i & other) const {
    return !(x == other.x && y == other.y);
}

eVector2f eVector2f::operator-(const Vector2i& other) const {
    return {x - other.x, y - other.y};
}

eVector2f eVector2f::operator+(const Vector2i& other) const {
    return {x + other.x, y + other.y};
}


eVector2f& eVector2f::operator+=(const Vector2i& other) {
    x += other.x;
    y += other.y;
    return *this;
}

eVector2f& eVector2f::operator-=(const Vector2i& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}


float eVector2f::operator*(const eVector2f& other) const {
    return (x * other.x + y * other.y);
}

float eVector2f::operator^(const eVector2f& other) const {
    return (x * other.y - y * other.x);
}

float eVector2f::operator*(const Vector2i &other) const {
    return (x * other.x + y * other.y);
}

float eVector2f::operator^(const Vector2i &other) const {
    return (x * other.y - y * other.x);
}

float eVector2f::operator*(const Vector2f &other) const {
    return (x * other.x + y * other.y);
}

float eVector2f::operator^(const Vector2f &other) const {
    return (x * other.y - y * other.x);
}


eVector2f eVector2f::operator*(float k) {
    return {x*k, y*k};
}

eVector2f &eVector2f::operator*=(float k) {
    x *= k;
    y *= k;
    return *this;
}

eVector2f eVector2f::operator/(float k) {
    return {x/k, y/k};
}

eVector2f &eVector2f::operator/=(float k) {
    x /= k;
    y /= k;
    return *this;
}


float eVector2f::len() const {
    return sqrt(x*x + y*y);
}

float eVector2f::squareLen() const {
    return (x*x + y*y);
}

eVector2f eVector2f::norm() {
    float len = this->len();
    if (len == 0)
        return {0, 0};
    return {this->x / len, this->y / len};
}

eVector2f eVector2f::perp() const {
    return {y, -x};
}

eVector2f eVector2f::operator-() const {
    return {-x, -y};
}

eVector2f& eVector2f::rotate(float angle) {
    float currLen = this->len();
    float s = sin(angle);
    float c = cos(angle);
    x = x*c - y*s;
    y = x*s + y*c;
    eVector2f temp = this->norm()*currLen;
    x = temp.x;
    y = temp.y;
    return *this;
}

eVector2f eVector2f::getRotate(float angle) const {
    float s = sin(angle);
    float c = cos(angle);
    return {x*c - y*s, x*s + y*c};
}


std::ostream& operator<<(std::ostream& stream, const eVector2f& v) {
    stream << v.x << " " << v.y;
    return stream;
}

std::istream& operator>>(std::istream& stream, eVector2f& v) {
    stream >> v.x >> v.y;
    return stream;
}






