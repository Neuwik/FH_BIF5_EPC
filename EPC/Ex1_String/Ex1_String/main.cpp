#include <cassert>  // for assert
#include <iostream>
#include "String.h"

// Test Default Constructor: Empty string
void testDefaultConstructor()
{
    String str;
    assert(str.length() == 0);
    assert(str.capacity() == 0);
    assert(str.c_str() == nullptr);
    std::cout << "testDefaultConstructor passed." << std::endl;
}

// Test Constructor from const char*
void testConstructorFromCString()
{
    String str("Hello");
    assert(str.length() == 5);
    assert(str.capacity() >= 6);  // Capacity should be at least length + 1 (for '\0')
    assert(std::string(str.c_str()) == "Hello");
    std::cout << "testConstructorFromCString passed." << std::endl;
}

// Test Copy Constructor
void testCopyConstructor()
{
    String str1("Copy this");
    String str2(str1);  // Copy constructor
    assert(str2.length() == str1.length());
    assert(std::string(str2.c_str()) == "Copy this");
    assert(str1.c_str() != str2.c_str());  // Ensure deep copy
    std::cout << "testCopyConstructor passed." << std::endl;
}

// Test Move Constructor
void testMoveConstructor()
{
    String str1("Move this");
    String str2(std::move(str1));  // Move constructor
    assert(str2.length() == 9);
    assert(std::string(str2.c_str()) == "Move this");
    assert(str1.c_str() == nullptr);  // Ensure moved from
    assert(str1.length() == 0);
    std::cout << "testMoveConstructor passed." << std::endl;
}

// Test Copy Assignment Operator
void testCopyAssignmentOperator()
{
    String str1("Copy assignment");
    String str2 = str1;  // Copy assignment
    assert(str2.length() == str1.length());
    assert(std::string(str2.c_str()) == "Copy assignment");
    assert(str1.c_str() != str2.c_str());  // Ensure deep copy
    std::cout << "testCopyAssignmentOperator passed." << std::endl;
}

// Test Move Assignment Operator
void testMoveAssignmentOperator()
{
    String str1("Move assignment");
    String str2;
    str2 = std::move(str1);  // Move assignment
    assert(str2.length() == 15);
    assert(std::string(str2.c_str()) == "Move assignment");
    assert(str1.c_str() == nullptr);  // Ensure moved from
    assert(str1.length() == 0);
    std::cout << "testMoveAssignmentOperator passed." << std::endl;
}

// Test Overloaded = const char*
void testAssignmentFromCString()
{
    String str;
    str = "Assign const char*";
    assert(str.length() == 18);
    assert(std::string(str.c_str()) == "Assign const char*");
    std::cout << "testAssignmentFromCString passed." << std::endl;
}

// Test Overloaded += String
void testPlusEqualsString()
{
    String str1("Hello");
    String str2(" World");
    str1 += str2;
    assert(str1.length() == 11);
    assert(std::string(str1.c_str()) == "Hello World");
    std::cout << "testPlusEqualsString passed." << std::endl;
}

// Test Overloaded += const char*
void testPlusEqualsCString()
{
    String str("Hello");
    str += " World!";
    assert(str.length() == 12);
    assert(std::string(str.c_str()) == "Hello World!");
    std::cout << "testPlusEqualsCString passed." << std::endl;
}

// Test append() const char*
void testAppendCString()
{
    String str("Append");
    str.append(" this");
    assert(str.length() == 11);
    assert(std::string(str.c_str()) == "Append this");
    std::cout << "testAppendCString passed." << std::endl;
}

// Test append() String
void testAppendString()
{
    String str1("Append");
    String str2(" this");
    str1.append(str2);
    assert(str1.length() == 11);
    assert(std::string(str1.c_str()) == "Append this");
    std::cout << "testAppendString passed." << std::endl;
}

// Test reserve() (increase capacity)
void testReserve()
{
    String str("Reserve test");
    size_t old_capacity = str.capacity();
    str.reserve(old_capacity + 1);  // Reserve more than needed
    assert(str.capacity() > old_capacity);  // Capacity should be updated
    assert(std::string(str.c_str()) == "Reserve test");
    std::cout << "testReserve passed." << std::endl;
}

// Test capacity()
void testCapacity()
{
    String str("Capacity test");
    size_t capacity = str.capacity();
    assert(capacity >= str.length() + 1);  // Capacity should be at least length + 1
    std::cout << "testCapacity passed." << std::endl;
}

// Test edge case: Appending nullptr or empty string
void testEdgeCasesAppendingNullOrEmpty()
{
    String str("Base");
    str += nullptr;  // Should handle gracefully without crashing
    assert(std::string(str.c_str()) == "Base");  // No change

    str.append(nullptr);
    assert(std::string(str.c_str()) == "Base");  // No change

    str.append("", 0);  // Appending empty string should work
    assert(std::string(str.c_str()) == "Base");  // No change

    std::cout << "testEdgeCasesAppendingNullOrEmpty passed." << std::endl;
}

// Test edge case: Constructing with nullptr
void testEdgeCaseConstructorWithNullptr()
{
    String str(nullptr);  // Should handle gracefully
    assert(str.length() == 0);
    assert(str.c_str() == nullptr);
    std::cout << "testEdgeCaseConstructorWithNullptr passed." << std::endl;
}

// Test edge case: Negative values
void testEdgeCaseNegativeValues()
{
    String str("Negative test");
    str.append(" still works", -1);  // appends all
    assert(std::string(str.c_str()) == "Negative test still works");
    std::cout << "testEdgeCaseNegativeValues passed." << std::endl;
}

// Test edge case: append part of string
void testEdgeCaseAppendPartly()
{
    String str("append");
    str.append(" partly", 5);  // appends all
    assert(std::string(str.c_str()) == "append part");
    std::cout << "testEdgeCaseAppendPartly passed." << std::endl;
}

// Test append chain
void testAppendChain()
{
    String str("start");
    str.append(" middle").append(" end");
    assert(std::string(str.c_str()) == "start middle end");
    std::cout << "testAppendChain passed." << std::endl;
}

// Test edge case: Reserve with smaller value
void testEdgeCaseReserveSmallerValue()
{
    String str("Small reserve test");
    size_t old_capacity = str.capacity();
    str.reserve(5);  // Should not reduce capacity
    assert(str.capacity() == old_capacity);
    std::cout << "testEdgeCaseReserveSmallerValue passed." << std::endl;
}

void runStringTests()
{
    testDefaultConstructor();
    testConstructorFromCString();
    testCopyConstructor();
    testMoveConstructor();
    testCopyAssignmentOperator();
    testMoveAssignmentOperator();
    testAssignmentFromCString();
    testPlusEqualsString();
    testPlusEqualsCString();
    testAppendCString();
    testAppendString();
    testReserve();
    testCapacity();
    testEdgeCasesAppendingNullOrEmpty();
    testEdgeCaseConstructorWithNullptr();
    testEdgeCaseNegativeValues();
    testEdgeCaseAppendPartly();
    testAppendChain();
    testEdgeCaseReserveSmallerValue();

    std::cout << "All tests passed!" << std::endl;
}

int main()
{
    runStringTests();
    return 0;
}
