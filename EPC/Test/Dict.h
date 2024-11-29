template <typename K, typename V>
class Dict
{
private:
    std::vector<std::pair<K,V>>* map;

    int getPairIndexWithKey(const K key) const
    {
        for(int i = 0; i < (int)map->size(); ++i)
        {
            if (map->at(i).first == key)
            {
                return i;
            }
        }

        throw std::runtime_error("Key not found");
    }

public:
    Dict()
    {
        map = new std::vector<std::pair<K,V>>();
    }

    ~Dict()
    {
        delete map;
    }

    V operator[](const K key) const
    {
        return getValueWithKey(key);
    }
    
    V getValueWithKey(const K key) const
    {
        try
        {
            return map->at(getPairIndexWithKey(key)).second;
        }
        catch(const std::exception& e)
        {
            throw e;
        }
    }

    bool tryAddPair(const K key, const V value)
    {
        try
        {
            getValueWithKey(key);
            return false;
        }
        catch(const std::exception& e)
        {
            map->push_back(std::pair(key,value));
            return true;
        }
        
        return false;
    }

    bool tryDeletePair(const K key)
    {
        try
        {
            map->erase(map->begin()+getPairIndexWithKey(key));
            return true;
        }
        catch(const std::exception& e)
        {
            return false;
        }
    }
    
    std::vector<std::pair<K,V>>& operator*() const
    {
        return *map;
    }
    
    std::vector<std::pair<K,V>>* operator->() const
    {
        return map;
    }
};

template class Dict<int, char>;
template class Dict<char, int>;