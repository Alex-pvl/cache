#include "CacheProvider.h"

template <typename K, typename V>
class RANDProvider : public CacheProvider<K, V> {
public:
    RANDProvider();
    void put(K, V) override;
    V get(K) override;
    void evict() override;
    std::string to_string() override;
    ~RANDProvider() = default;
};