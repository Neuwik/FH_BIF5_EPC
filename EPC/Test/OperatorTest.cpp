#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "OperatorClass.h"

TEST_CASE("ctr") 
{
    char* c = new char('a');
    OperatorClass o1(1, c);
    delete c;
    OperatorClass o2;

    CHECK_EQ(o1.getChar(), 'a');
    CHECK_EQ(o1.getInt(), 1);
    CHECK_EQ(o2.getChar(), '\0');
    CHECK_EQ(o2.getInt(), 0);

    // copy
    OperatorClass o3(o1);
    o3++;

    CHECK_EQ(o1.getChar(), 'a');
    CHECK_EQ(o1.getInt(), 1);
    CHECK_EQ(o3.getChar(), 'a');
    CHECK_EQ(o3.getInt(), 2);

    //move
    OperatorClass o4(std::move(o3));

    CHECK_EQ(o3.getChar(), '\0');
    CHECK_EQ(o3.getInt(), 0);
    CHECK_EQ(o4.getChar(), 'a');
    CHECK_EQ(o4.getInt(), 2);
}

TEST_CASE("op=") 
{
    char* c = new char('a');
    OperatorClass o1(1, c);
    delete c;

    //copy
    OperatorClass o2 = o1;
    o2++;

    CHECK_EQ(o1.getChar(), 'a');
    CHECK_EQ(o1.getInt(), 1);
    CHECK_EQ(o2.getChar(), 'a');
    CHECK_EQ(o2.getInt(), 2);

    //move
    OperatorClass o3 = std::move(o2);

    CHECK_EQ(o2.getChar(), '\0');
    CHECK_EQ(o2.getInt(), 0);
    CHECK_EQ(o3.getChar(), 'a');
    CHECK_EQ(o3.getInt(), 2);
}

TEST_CASE("op+-") 
{
    char* c1 = new char('a');
    char* c2 = new char('b');

    OperatorClass o1(1, c1);
    OperatorClass o2(2, c2);

    delete c1;
    delete c2;

    CHECK_EQ(o1.getInt(), 1);
    CHECK_EQ((++o1).getInt(), 2);
    CHECK_EQ((o1++).getInt(), 2);
    CHECK_EQ(o1.getInt(), 3);

    CHECK_EQ((--o1).getInt(), 2);
    CHECK_EQ((o1--).getInt(), 2);
    CHECK_EQ(o1.getInt(), 1);

    
    CHECK_EQ((o1+o2).getInt(), 3);
    CHECK_EQ(o1.getInt(), 1);
    CHECK_EQ(o2.getInt(), 2);

    CHECK_EQ((o2-o1).getInt(), 1);
    CHECK_EQ(o1.getInt(), 1);
    CHECK_EQ(o2.getInt(), 2);
    
    CHECK_EQ((o1+=o2).getInt(), 3);
    CHECK_EQ(o1.getInt(), 3);
    CHECK_EQ(o2.getInt(), 2);

    CHECK_EQ((o1-=o2).getInt(), 1);
    CHECK_EQ(o1.getInt(), 1);
    CHECK_EQ(o2.getInt(), 2);
}

TEST_CASE("op bool") 
{
    char* c = new char('a');
    OperatorClass o1(1, c);
    delete c;

    CHECK((bool)(o1--));
    CHECK_FALSE((bool)(--o1));
}