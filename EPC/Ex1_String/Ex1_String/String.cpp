#include "String.h"

// reserve new memory space and move string data there
void String::allocate(size_t new_capacity)
{
    char* new_data = new char[new_capacity];

    if (data)
    {
        for (size_t i = 0; i < len; ++i)
        {
            new_data[i] = data[i];
        }
        new_data[len] = '\0';

        delete[] data;
    }

    data = new_data;
    cap = new_capacity;
}

// Length of C-Strings without '\0'
size_t String::stringLength(const char* str) const
{
    size_t length = 0;
    //forgot to implement before assigment submition
    if (str != nullptr)
    {
        while (str[length] != '\0')
        {
            ++length;
        }
    }
    return length;
}

// replace data with copy of C-String
void String::copyString(const char* src, size_t srcLen, size_t srcCap)
{
    if (srcCap <= srcLen)
    {
        allocate(srcLen + 1);
    }
    else
    {
        allocate(srcCap);
    }

    if (src != nullptr)
    {
        for (size_t i = 0; i < srcLen; ++i)
        {
            data[i] = src[i];
        }

        len = srcLen;
    }

    data[len] = '\0';  // Nullterminator hinzuf�gen
}

// Konstruktor: const char*
String::String(const char* str) : data(nullptr), len(stringLength(str)), cap(len + 1)
{
    copyString(str, stringLength(str));
}

// Destruktor: Freigeben des Speichers ???
String::~String()
{
    delete[] data;
}

// Copy-Konstruktor
String::String(const String& other) : data(nullptr), len(other.len), cap(other.cap)
{
    copyString(other.data, other.len, other.cap);
}

// Move-Konstruktor
String::String(String&& other) noexcept : data(other.data), len(other.len), cap(other.cap)
{
    other.data = nullptr;
    other.len = 0;
    other.cap = 0;
}

// Copy-Assignment-Operator
String& String::operator=(const String& other)
{
    if (this != &other)
    {
        copyString(other.data, other.len, other.cap);
    }
    return *this;
}

// Move-Assignment-Operator
String& String::operator=(String&& other) noexcept
{
    if (this != &other)
    {
        delete[] data;
        data = other.data;
        len = other.len;
        cap = other.cap;
        other.data = nullptr;
        other.len = 0;
        other.cap = 0;
    }
    return *this;
}

// append-Methode
void String::append(const String& other)
{
    size_t new_len = len + other.len;

    reserve(new_len + 1);

    for (size_t i = 0; i < other.len; ++i)
    {
        data[len + i] = other.data[i];
    }
    data[len + other.len] = '\0';

    len = new_len;
}

// c_str(): get data as const char*
const char* String::c_str() const
{
    return data;
}

// length(): get len
size_t String::length() const
{
    return len;
}

// size(): get length()
size_t String::size() const
{
    return length();
}

// reserve(): Speicher f�r den String reservieren
void String::reserve(size_t new_capacity)
{
    if (new_capacity == cap)
    {
        return;
    }

    if (new_capacity > len)
    {
        allocate(new_capacity);
    }
    else
    {
        allocate(len + 1);
    }
}

// capacity(): get cap
size_t String::capacity() const
{
    return cap;
}
