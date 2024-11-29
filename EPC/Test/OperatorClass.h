class OperatorClass
{

private:
    int _intData;
    char* _strData;

    void CopyStr(char* str)
    {
        _strData = new char(*str);
    }

    void DeleteStr()
    {
        if (_strData != nullptr)
        {
            delete _strData;
            _strData = nullptr;
        }
    }

public:
    OperatorClass()
    {
        _strData = nullptr;
        _intData = 0;
    }

    OperatorClass(int intData, char* strData)
    {
        _intData = intData;
        CopyStr(strData);
    }

    ~OperatorClass()
    {
        DeleteStr();
    }

    // copy ctr
    OperatorClass(const OperatorClass& other)
    {
        _intData = other._intData;
        CopyStr(other._strData);
    }
    
    // move ctr
    OperatorClass(OperatorClass&& other) noexcept
    {
        _intData = other._intData;
        _strData = other._strData;
        
        other._strData = nullptr;
        other._intData = 0;
    }

    // copy =
    OperatorClass& operator=(const OperatorClass& other)
    {
        if (this != &other)
        {
            DeleteStr();

            _intData = other._intData;
            CopyStr(other._strData);
        }

        return *this;
    }

    // move =
    OperatorClass& operator=(OperatorClass&& other) noexcept
    {
        if (this != &other)
        {
            DeleteStr();

            _intData = other._intData;
            _strData = other._strData;

            other._strData = nullptr;
            other._intData = 0;
        }

        return *this;
    }

    // ++o
    OperatorClass& operator++()
    {
        ++_intData;
        return *this;
    }

    // o++
    OperatorClass operator++(int)
    {
        OperatorClass temp = *this;
        ++(*this);
        return temp;
    }

    // --o
    OperatorClass& operator--()
    {
        --_intData;
        return *this;
    }
    
    // o--
    OperatorClass operator--(int)
    {
        OperatorClass temp = *this;
        --(*this);
        return temp;
    }

    // +=
    OperatorClass& operator+=(const OperatorClass& other)
    {
        _intData += other._intData;
        return *this;
    }

    // -=
    OperatorClass& operator-=(const OperatorClass& other)
    {
        _intData -= other._intData;
        return *this;
    }

    // +
    OperatorClass operator+(const OperatorClass& other) const
    {
        OperatorClass temp = *this;
        temp += other;
        return temp;
    }

    // -
    OperatorClass operator-(const OperatorClass& other) const
    {
        OperatorClass temp = *this;
        temp -= other;
        return temp;
    }

    operator bool() const
    {
        return _intData > 0;
    }

    int getInt()
    {
        return _intData;
    }

    char getChar()
    {
        if (_strData != nullptr)
        {
            return *_strData;
        }
        
        return '\0';
    }
};
