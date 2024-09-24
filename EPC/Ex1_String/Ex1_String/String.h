#pragma once
#ifndef STRING_H
#define STRING_H
#include <iostream>

class String
{
    private:
        char* data;     // Pointer auf den String
        size_t len;     // Länge des Strings
        size_t cap;     // Kapazität des internen Speichers

        // Hilfsmethode, um Speicher zu reservieren
        void allocate(size_t new_capacity);

        // Length of C-Strings without '\0'
        size_t stringLength(const char* str) const;

        // replace data with copy of C-String
        void copyString(const char* src, size_t srcLen = -1, size_t srcCap = 0);

        // free all and reset
        void freeAll();

    public:
        // Konstruktor: empty
        String();

        // Konstruktor: const char*
        String(const char* str);

        // Destruktor: Freigeben des Speichers ???
        ~String();

        // Copy-Konstruktor
        String(const String& other);

        // Move-Konstruktor
        String(String&& other) noexcept;

        // Copy-Assignment-Operator
        String& operator=(const String& other);

        // Move-Assignment-Operator
        String& operator=(String&& other) noexcept;

        // Overloaded = const char*
        String& operator=(const char* str);

        // Overloaded += String
        String& operator+=(const String& other);

        // Overloaded += const char*
        String& operator+=(const char* str);

        // append-Methode: const char*
        String& append(const char* str, int strLen = -1);

        // append-Methode: String
        String& append(const String& other);

        // c_str(): get data as const char*
        const char* c_str() const;

        // length(): get len
        size_t length() const;

        // size(): get length()
        size_t size() const;

        // reserve(): Speicher für den String reservieren
        void reserve(size_t new_capacity = -1);

        // capacity(): get cap
        size_t capacity() const;
};

#endif // STRING_H
