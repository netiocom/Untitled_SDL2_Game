#include <iostream>
#include "Vector2.hpp"

Vector2::Vector2(){}

Vector2::Vector2(int x, int y)//: x(x), y(y) 
{
   this->x = x; 
   this->y = y;
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

std::ostream& operator<<(std::ostream& output, Vector2 me)
{
    output << me.x << ", " << me.y;
    return output;
}