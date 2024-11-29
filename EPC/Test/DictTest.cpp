#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Dict.h"


TEST_CASE("test") 
{
    Dict<int, char> dict;

    CHECK(dict.tryAddPair(1,'A'));
    CHECK(dict.tryAddPair(2,'B'));
    CHECK_FALSE(dict.tryAddPair(2,'B'));

    CHECK_EQ(dict[1], 'A');
    CHECK_EQ(dict[2], 'B');
    CHECK_THROWS(dict[3]);

    CHECK(dict.tryAddPair(5,'E'));
    CHECK_EQ(dict[5], 'E');

    CHECK(dict.tryDeletePair(2));

    CHECK_EQ(dict[1], 'A');
    CHECK_EQ(dict[5], 'E');
    CHECK_THROWS(dict[2]);
}

TEST_CASE("test2") 
{
    Dict<char, int> dict;

    CHECK(dict.tryAddPair('A',1));
    CHECK(dict.tryAddPair('B',2));
    CHECK_FALSE(dict.tryAddPair('B',15));

    CHECK_EQ(dict['A'], 1);
    CHECK_EQ(dict['B'], 2);
    CHECK_THROWS(dict['C']);
}

template <typename T>
struct Struct
{
    T value;
};

//template struct Struct<int>;

template <>
struct Struct<int> { 
    int value;
};

TEST_CASE("test3")
{
    Struct<int> s1;
    Struct<int> s2;

    CHECK_EQ(s1.value,0);
    CHECK_EQ(++s2.value,1);
}