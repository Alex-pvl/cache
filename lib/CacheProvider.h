#pragma once
#include <string>
#include <algorithm>
#include <unordered_map>

enum class EvictPolicy {
    FIFO,
    LRU,
    RAND,
};

template <typename K, typename V>
class CacheProvider {
public:
    CacheProvider() {}
    virtual void put(K, V) = 0;
    virtual V get(K) = 0;
    virtual void evict() = 0;
    virtual std::string to_string() = 0;

    void set_max_capacity(int max_capacity) {
        if (max_capacity <= 0) return;
        this->max_capacity = max_capacity;
    }
protected:
    int max_capacity = 16;
    EvictPolicy policy;
    std::unordered_map<K, V> cache;
};
