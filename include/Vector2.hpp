#pragma once
#include <iostream>

struct Vector2
{
    float x, y;
    Vector2(float x, float y);
    Vector2();
    Vector2 operator+(Vector2 other);
    Vector2 operator-(Vector2 other);
    Vector2 operator*(Vector2 other);
    Vector2 operator/(Vector2 other);
    void operator+=(Vector2 other);
    void operator-=(Vector2 other);
    friend std::ostream& operator<<(std::ostream& output, Vector2 me);
};

std::ostream& operator<<(std::ostream& output, Vector2 me);
