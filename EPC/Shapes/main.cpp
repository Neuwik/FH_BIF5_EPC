#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Shape.h"

Shape* copyShape(Shape* s)
{
    //return new Shape(*s);
    return s->clone();
}

TEST_CASE("Shape copy test")
{
    Shape* c =  new Circle(5);
    Shape* s = copyShape(c);

    CHECK(s != nullptr);
}

