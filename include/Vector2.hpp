#pragma once 
#include <iostream>

struct Vector2
{
    int x, y;
    Vector2(int x, int y);
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

