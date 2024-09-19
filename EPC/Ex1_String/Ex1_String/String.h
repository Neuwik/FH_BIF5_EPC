#pragma once
#ifndef STRING_H
#define STRING_H
#include <iostream>

class String
{
    private:
        char* data;     // Pointer auf den String
        size_t len;     // L�nge des Strings
        size_t cap;     // Kapazit�t des internen Speichers

        // Hilfsmethode, um Speicher zu reservieren
        void allocate(size_t new_capacity);

        // Length of C-Strings without '\0'
        size_t stringLength(const char* str) const;

        // replace data with copy of C-String
        void copyString(const char* src, size_t srcLen, size_t srcCap = 0);

    public:
        // Konstruktor: const char*
        String(const char* str = "");

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

        // append-Methode
        void append(const String& other);

        // c_str(): get data as const char*
        const char* c_str() const;

        // length(): get len
        size_t length() const;

        // size(): get length()
        size_t size() const;

        // reserve(): Speicher f�r den String reservieren
        void reserve(size_t new_capacity = 0);

        // capacity(): get cap
        size_t capacity() const;
};

#endif // STRING_H
