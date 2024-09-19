#include <iostream>
#include "String.h"

using namespace std;

int main()
{
    // Test des Konstruktors
    String s1("Hallo");
    std::cout << "String 1: " << s1.c_str() << " (L�nge: " << s1.length() << ")\n";

    // Test der Append-Methode
    String s2(" Welt!");
    s1.append(s2);
    std::cout << "Nach Append: " << s1.c_str() << " (L�nge: " << s1.length() << ")\n";

    // Test der Copy- und Move-Konstruktoren
    String s3 = s1;
    std::cout << "String 3 (Kopie von String 1): " << s3.c_str() << " (L�nge: " << s3.length() << ")\n";

    String s4 = std::move(s2);
    std::cout << "String 4 (Move von String 2): " << s4.c_str() << " (L�nge: " << s4.length() << ")\n";

    // Test von reserve() und capacity()
    s1.reserve(50);
    std::cout << "Kapazit�t von String 1 nach Reserve: " << s1.capacity() << "\n";

    return 0;
}
