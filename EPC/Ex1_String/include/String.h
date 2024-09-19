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
        void allocate(size_t new_capacity)
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

        void copyString(char* dest, const char* src, size_t n) {
            for (size_t i = 0; i < n; ++i) {
                dest[i] = src[i];
            }
            dest[n] = '\0';  // Nullterminator hinzufügen
        }

        // Length of C-Strings without '\0'
        size_t stringLength(const char* str) const
        {
            size_t length = 0;
            while (str[length] != '\0')
            {
                ++length;
            }
            return length;
        }

        // replace data with copy of C-String
        void copyString(const char* src, size_t srcLen, size_t srcCap = 0)
        {
            if (src != nullptr)
            {
                if (srcCap <= srcLen)
                {
                    allocate(srcLen + 1);
                }
                else
                {
                    allocate(srcCap);
                }

                for (size_t i = 0; i < srcLen; ++i)
                {
                    data[i] = src[i];
                }

                len = srcLen;
            }

            data[len] = '\0';  // Nullterminator hinzufügen
        }

    public:
        // Konstruktor: const char*
        String(const char* str = "") : data(nullptr), len(stringLength(str)), cap(len + 1)
        {
            copyString(str, stringLength(str));
        }

        // Destruktor: Freigeben des Speichers ???
        ~String()
        {
            delete[] data;
        }

        // Copy-Konstruktor
        String(const String& other) : data(nullptr), len(other.len), cap(other.cap)
        {
            copyString(other.data, other.len, other.cap);
        }

        // Move-Konstruktor
        String(String&& other) noexcept : data(other.data), len(other.len), cap(other.cap)
        {
            other.data = nullptr;
            other.len = 0;
            other.cap = 0;
        }

        // Copy-Assignment-Operator
        String& operator=(const String& other)
        {
            if (this != &other)
            {
                copyString(other.data, other.len, other.cap);
            }
            return *this;
        }

        // Move-Assignment-Operator
        String& operator=(String&& other) noexcept
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
        void append(const String& other)
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
        const char* c_str() const
        {
            return data;
        }

        // length(): get len
        size_t length() const
        {
            return len;
        }

        // size(): get length()
        size_t size() const
        {
            return length();
        }

        // reserve(): Speicher für den String reservieren
        void reserve(size_t new_capacity = 0)
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
        size_t capacity() const
        {
            return cap;
        }
};

#endif // STRING_H
