#pragma once
#include "CacheProvider.h"

template <typename K, typename V>
class FIFOProvider : public CacheProvider<K, V> {
public:
    FIFOProvider();
    void put(K, V) override;
    V get(K) override;
    void evict() override;
    std::string to_string() override;
    ~FIFOProvider() = default;
};
