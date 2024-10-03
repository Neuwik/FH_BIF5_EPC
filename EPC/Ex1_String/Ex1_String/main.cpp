#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "String.h"

TEST_CASE("Default Constructor: Empty string") {
    String str;
    CHECK(str.length() == 0);
    CHECK(str.capacity() == 0);
    CHECK(str.c_str() == nullptr);
}

TEST_CASE("Constructor from const char*") {
    String str("Hello");
    CHECK(str.length() == 5);
    CHECK(str.capacity() >= 6);  // Capacity should be at least length + 1 (for '\0')
    CHECK(std::string(str.c_str()) == "Hello");
}

TEST_CASE("Copy Constructor") {
    String str1("Copy this");
    String str2(str1);  // Copy constructor
    CHECK(str2.length() == str1.length());
    CHECK(std::string(str2.c_str()) == "Copy this");
    CHECK(str1.c_str() != str2.c_str());  // Ensure deep copy
}

TEST_CASE("Move Constructor") {
    String str1("Move this");
    String str2(std::move(str1));  // Move constructor
    CHECK(str2.length() == 9);
    CHECK(std::string(str2.c_str()) == "Move this");
    CHECK(str1.c_str() == nullptr);  // Ensure moved from
    CHECK(str1.length() == 0);
}

TEST_CASE("Copy Assignment Operator") {
    String str1("Copy assignment");
    String str2 = str1;  // Copy assignment
    CHECK(str2.length() == str1.length());
    CHECK(std::string(str2.c_str()) == "Copy assignment");
    CHECK(str1.c_str() != str2.c_str());  // Ensure deep copy
}

TEST_CASE("Move Assignment Operator") {
    String str1("Move assignment");
    String str2;
    str2 = std::move(str1);  // Move assignment
    CHECK(str2.length() == 15);
    CHECK(std::string(str2.c_str()) == "Move assignment");
    CHECK(str1.c_str() == nullptr);  // Ensure moved from
    CHECK(str1.length() == 0);
}

TEST_CASE("Assignment from const char*") {
    String str;
    str = "Assign const char*";
    CHECK(str.length() == 18);
    CHECK(std::string(str.c_str()) == "Assign const char*");
}

TEST_CASE("Overloaded += String") {
    String str1("Hello");
    String str2(" World");
    str1 += str2;
    CHECK(str1.length() == 11);
    CHECK(std::string(str1.c_str()) == "Hello World");
}

TEST_CASE("Overloaded += const char*") {
    String str("Hello");
    str += " World!";
    CHECK(str.length() == 12);
    CHECK(std::string(str.c_str()) == "Hello World!");
}
TEST_CASE("Test der Konvertierung zu const char*") {
    String s("Hallo");
    const char* cstr = s;  
    
    CHECK(cstr != nullptr); 
    CHECK(std::strcmp(cstr, "Hallo") == 0);  
}

TEST_CASE("Test des += Operators mit String") {
    String s1("Hallo");
    String s2(" Welt");
    
    s1 += s2;  
    
    CHECK(s1.length() == 10); 
    CHECK(std::strcmp(s1.c_str(), "Hallo Welt") == 0);  
}

TEST_CASE("Test des += Operators mit const char*") {
    String s("Hallo");
    
    s += " Welt";  
    
    CHECK(s.length() == 10);  
    CHECK(std::strcmp(s.c_str(), "Hallo Welt") == 0);  
}

TEST_CASE("append() const char*") {
    String str("Append");
    str.append(" this");
    CHECK(str.length() == 11);
    CHECK(std::string(str.c_str()) == "Append this");
}

TEST_CASE("append() String") {
    String str1("Append");
    String str2(" this");
    str1.append(str2);
    CHECK(str1.length() == 11);
    CHECK(std::string(str1.c_str()) == "Append this");
}

TEST_CASE("reserve()") {
    String str("Reserve test");
    size_t old_capacity = str.capacity();
    str.reserve(old_capacity + 1);  // Reserve more than needed
    CHECK(str.capacity() > old_capacity);  // Capacity should be updated
    CHECK(std::string(str.c_str()) == "Reserve test");
}

TEST_CASE("capacity()") {
    String str("Capacity test");
    size_t capacity = str.capacity();
    CHECK(capacity >= str.length() + 1);  // Capacity should be at least length + 1
}

TEST_CASE("Concatenation of two String objects") {
    String s1("First");
    String s2(" Second");

    String s3 = s1 + s2;
    CHECK(s3.length() == (s1.length() + s2.length()));
    CHECK(std::string(s3.c_str()) == "First Second");
}

TEST_CASE("Concatenation of String object and const char*") {
    String s3("First SecondHello");
    const String s4 = s3 + "World";
    CHECK(s4.length() == 22);  // "First SecondHello" + "World"
    CHECK(std::string(s4.c_str()) == "First SecondHelloWorld");
}

TEST_CASE("Edge cases: Appending nullptr or empty string") {
    String str("Base");
    str += nullptr;  // Should handle gracefully without crashing
    CHECK(std::string(str.c_str()) == "Base");  // No change

    str.append(nullptr);
    CHECK(std::string(str.c_str()) == "Base");  // No change

    str.append("", 0);  // Appending empty string should work
    CHECK(std::string(str.c_str()) == "Base");  // No change
}

TEST_CASE("Edge case: Constructor with nullptr") {
    String str(nullptr);  // Should handle gracefully
    CHECK(str.length() == 0);
    CHECK(str.c_str() == nullptr);
}

TEST_CASE("Edge case: Negative values") {
    String str("Negative test");
    str.append(" still works", -1);  // appends all
    CHECK(std::string(str.c_str()) == "Negative test still works");
}

TEST_CASE("Edge case: Append part of string") {
    String str("append");
    str.append(" partly", 5);  // appends part
    CHECK(std::string(str.c_str()) == "append part");
}

TEST_CASE("append() chain") {
    String str("start");
    str.append(" middle").append(" end");
    CHECK(std::string(str.c_str()) == "start middle end");
}

TEST_CASE("Edge case: Reserve with smaller value") {
    String str("Small reserve test");
    size_t old_capacity = str.capacity();
    str.reserve(5);  // Should not reduce capacity
    CHECK(str.capacity() == old_capacity);
}

TEST_CASE("Concatenation with empty String using + operator") {
    String empty;
    String str("Non-empty");

    String result1 = empty + str;
    CHECK(result1.length() == str.length());
    CHECK(std::string(result1.c_str()) == "Non-empty");

    String result2 = str + empty;
    CHECK(result2.length() == str.length());
    CHECK(std::string(result2.c_str()) == "Non-empty");

    String result3 = empty + "";  
    CHECK(result3.length() == 0);  
    CHECK(std::strcmp(result3.c_str(), "") == 0);  
}

TEST_CASE("Concatenation with empty String using += operator") {
    String str("Non-empty");
    String empty;

    str += empty;
    CHECK(str.length() == 9); 
    CHECK(std::string(str.c_str()) == "Non-empty");

    empty += str;
    CHECK(empty.length() == str.length());
    CHECK(std::string(empty.c_str()) == "Non-empty");
}

TEST_CASE("Concatenation of large Strings") {
    String large1("LargeString1");
    String large2("LargeString2");
    
    for (int i = 0; i < 1000; ++i) {
        large1 += "x";  // Wiederholt Zeichen anhängen
        large2 += "y";
    }

    String result = large1 + large2;
    CHECK(result.length() == large1.length() + large2.length());
    CHECK(result.capacity() >= result.length() + 1);
}

TEST_CASE("Chained concatenation using + operator") {
    String str1("First");
    String str2(" Second");
    String str3(" Third");

    String result = str1 + str2 + str3;
    CHECK(result.length() == (str1.length() + str2.length() + str3.length()));
    CHECK(std::string(result.c_str()) == "First Second Third");
}

TEST_CASE("Chained concatenation using += operator") {
    String str("Start");
    str += " middle";
    str += " end";

    CHECK(str.length() == 16);
    CHECK(std::string(str.c_str()) == "Start middle end");
}

TEST_CASE("Concatenation with nullptr using + operator") {
    String str("Valid String");

    String result = str + nullptr;  
    CHECK(std::string(result.c_str()) == "Valid String");
}

TEST_CASE("Self-concatenation with += operator") {
    String str("Repeat");
    str += str;  

    CHECK(str.length() == 12);  
    CHECK(std::string(str.c_str()) == "RepeatRepeat");  
}

TEST_CASE("Self-concatenation with + operator") {
    String str("Repeat");

    String result = str + str;
    CHECK(result.length() == 12);  
    CHECK(std::string(result.c_str()) == "RepeatRepeat");
}

TEST_CASE("Repeated concatenation using += operator (performance)") {
    String str("x");
    for (int i = 0; i < 10000; ++i) {
        str += "x";
    }
    CHECK(str.length() == 10001);
}
