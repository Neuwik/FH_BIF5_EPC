#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

struct BA 
{
	char a;
	int b;
};

TEST_CASE("Basic Test 4B1") 
{
    CHECK_EQ(sizeof(BA), 8);
}

struct BB 
{
	char a;
	char a2;
	char a3;
	//char a4;
	long b;
};

struct AB 
{
	char a;
	char a2;
	char a3;
};

class B
{
public:
	// virtual ~B(); //8
	//int getA() const { return a; }

private:
    char c; //1
    AB ab; //3 -> 3*1
    char c2; //1
    //3
	int a; //4
    char d; //1
    //3
    BB b; //16 -> 2*8
    bool ba[9]; //9 -> 9*1
    //7
};

TEST_CASE("Basic Test 4C1") 
{
    CHECK_EQ(sizeof(B), 0);
}

struct ST
{
    std::string str; // 32 -> 4*8
    char c;
};

TEST_CASE("Basic Test string") 
{
    CHECK_EQ(sizeof(std::string), 32);
    CHECK_EQ(sizeof(ST), 0);
}

TEST_CASE("Basic Size Test") 
{
    CHECK_EQ(sizeof(bool), 1);
    CHECK_EQ(sizeof(char), 1);
    CHECK_EQ(sizeof(long), 8);
    CHECK_EQ(sizeof(std::string), 32);
}