#include <iostream>
#include "Vector2.hpp"

Vector2::Vector2(){}

Vector2::Vector2(float x, float y): x(x), y(y) 
    {
        std::cout << "Vector struct initialized\n";
    }

Vector2 Vector2::operator*(Vector2 other)
{
    Vector2 newVector2 = Vector2(this->x*other.x, this->y*other.y);
    return newVector2;
}

Vector2 Vector2::operator/(Vector2 other)
{
    Vector2 newVector2 = Vector2(this->x/other.x, this->y/other.y);
    return newVector2;
}

Vector2 Vector2::operator+(Vector2 other)
{
    Vector2 newVector2 = Vector2(this->x+other.x, this->y+other.y);
    return newVector2;
}

Vector2 Vector2::operator-(Vector2 other)
{
    Vector2 newVector2 = Vector2(this->x-other.x, this->y-other.y);
    return newVector2;
}

void Vector2::operator-=(Vector2 other)
{
    this->x -= other.x;
    this->y -= other.y;
}

void Vector2::operator+=(Vector2 other)
{
    this->x += other.x;
    this->y += other.y;
}

