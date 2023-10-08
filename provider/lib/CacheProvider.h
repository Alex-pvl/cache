#pragma once
#include <string>

enum class EvictPolicy {
    FIFO,
    LRU,
    RAND,
};

template <typename K, typename V>
class CacheProvider {
public:
    CacheProvider() {}
    virtual std::string toString() = 0;
    static CacheProvider<K, V>* set_policy(EvictPolicy policy);
    ~CacheProvider() {}
protected:
    int capacity = 0;
    EvictPolicy policy;
};
