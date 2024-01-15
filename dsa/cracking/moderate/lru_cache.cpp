// 25. **LRU Cache:** Design and build a "least recently used" cache, which evicts the least recently used item. The cache should map from keys to values (allowing you to insert and retrieve a value associated with a particular key) and be initialized with a max-size. When it is full, it should evict the least recently used item.
#include <iostream>
#include <unordered_map>
#include <list>
class LRUCache
{
private:
    int capacity;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
    std::list<int> lruList;

public:
    LRUCache(int capacity) : capacity(capacity) {}
    int get(int key)
    {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;

        lruList.erase(it->second.second);
        lruList.push_front(key);

        it->second.second = lruList.begin();
        return it->second.first;
    }
    void put(int key, int value)
    {
        auto it = cache.find(key);
        if (it != cache.end())
            lruList.erase(it->second.second);
        if (cache.size() == capacity)
        {
            int lruKey = lruList.back();
            lruList.pop_back();
            cache.erase(lruKey);
        }

        lruList.push_front(key);
        cache[key] = {value, lruList.begin()};
    }
};
int main()
{
    LRUCache cache(2); // Initialize with capacity 2

    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << std::endl; // Output: 1
    cache.put(3, 3);                        // evicts key 2
    std::cout << cache.get(2) << std::endl; // Output: -1 (not found)
    cache.put(4, 4);                        // evicts key 1
    std::cout << cache.get(1) << std::endl; // Output: -1 (not found)
    std::cout << cache.get(3) << std::endl; // Output: 3
    std::cout << cache.get(4) << std::endl; // Output: 4
    return 0;
}