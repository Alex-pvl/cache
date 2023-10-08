#pragma once
#include "CacheProvider.h"

template <typename K, typename V>
class FIFOProvider : public CacheProvider<K, V> {
public:
    FIFOProvider();
    std::string toString();
    ~FIFOProvider();
};
