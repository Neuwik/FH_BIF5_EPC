#include <iostream>
#include "String.h"

void testDefaultConstructor() 
{
    String s;
    std::cout << "Default constructor:\n";
    std::cout << "Length: " << s.length() << "\n";
    std::cout << "Capacity: " << s.capacity() << "\n";
    std::cout << "C-String: [" << s.c_str() << "]\n";
}

void testConstructorWithString() 
{
    String s("Hello");
    std::cout << "\nConstructor with string:\n";
    std::cout << "Length: " << s.length() << "\n";
    std::cout << "Capacity: " << s.capacity() << "\n";
    std::cout << "C-String: [" << s.c_str() << "]\n";
}

void testAppend() 
{
    String s1("Hello");
    String s2(" World");
    s1.append(s2);
    std::cout << "\nAppend operation:\n";
    std::cout << "Length: " << s1.length() << "\n";
    std::cout << "Capacity: " << s1.capacity() << "\n";
    std::cout << "C-String: [" << s1.c_str() << "]\n";
}

void testReserve() 
{
    String s("Test");
    s.reserve(20);
    std::cout << "\nReserve operation:\n";
    std::cout << "Length: " << s.length() << "\n";
    std::cout << "Capacity: " << s.capacity() << "\n";
    std::cout << "C-String: [" << s.c_str() << "]\n";
}

void testEdgeCases() 
{
    // Test empty string
    String empty("");
    std::cout << "\nEmpty string:\n";
    std::cout << "Length: " << empty.length() << "\n";
    std::cout << "Capacity: " << empty.capacity() << "\n";
    std::cout << "C-String: [" << empty.c_str() << "]\n";

    // Test append empty string
    String s1("Hello");
    s1.append(empty);
    std::cout << "\nAppend empty string:\n";
    std::cout << "Length: " << s1.length() << "\n";
    std::cout << "Capacity: " << s1.capacity() << "\n";
    std::cout << "C-String: [" << s1.c_str() << "]\n";

    // Test self-assignment
    String s2("Self-Assign");
    s2 = s2;
    std::cout << "\nSelf-assignment:\n";
    std::cout << "Length: " << s2.length() << "\n";
    std::cout << "Capacity: " << s2.capacity() << "\n";
    std::cout << "C-String: [" << s2.c_str() << "]\n";

    // Test move constructor
    String moved = String("Moved");
    std::cout << "\nMove constructor:\n";
    std::cout << "Length: " << moved.length() << "\n";
    std::cout << "Capacity: " << moved.capacity() << "\n";
    std::cout << "C-String: [" << moved.c_str() << "]\n";

    // Test move assignment
    String moveAssigned;
    moveAssigned = String("Move Assigned");
    std::cout << "\nMove assignment:\n";
    std::cout << "Length: " << moveAssigned.length() << "\n";
    std::cout << "Capacity: " << moveAssigned.capacity() << "\n";
    std::cout << "C-String: [" << moveAssigned.c_str() << "]\n";
}

int main() 
{
    testDefaultConstructor();
    testConstructorWithString();
    testAppend();
    testReserve();
    testEdgeCases();

    return 0;
}
