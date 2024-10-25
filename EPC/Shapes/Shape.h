#pragma once
#include <iostream>
#include <functional>
#include <string>

class Shape
{
public:
    Shape() {}
    Shape(const Shape& other)
    {
        std::cout << "Shape copy ctor" << std::endl;
    }

    virtual Shape* clone() = 0;
};

template<typename T>
class ShapeCRTP : public Shape
{
    Shape* clone()
    {
        return new T(*static_cast<T*>(this));
    }
};

class Circle : public ShapeCRTP<Circle>
{
private:
    int _radius;
    
public:
    Circle(int radius) : _radius(radius) {}
    Circle(const Circle& other)
    {
        std::cout << "Circle copy ctor" << std::endl;
        _radius = other._radius;
    }

    int GetRadius() const
    {
        return _radius;
    }

    /*virtual Shape* clone()
    {
        return new Circle(*this);
    }*/
};

class Rectangle : public ShapeCRTP<Rectangle>
{
private:
    bool SomeDataBool;
    
public:
    Rectangle(bool b) : SomeDataBool(b) {}
    Rectangle(const Rectangle& other)
    {
        std::cout << "Rectangle copy ctor" << std::endl;
        SomeDataBool = other.SomeDataBool;
    }

    /*virtual Shape* clone()
    {
        return new Rectangle(*this);
    }*/
};