#include <list>
#include "CacheProvider.h"

template <typename K, typename V>
class LRUProvider : public CacheProvider<K, V> {
public:
    LRUProvider();
    void put(K, V) override;
    V get(K) override;
    void evict() override;
    std::string to_string() override;
    ~LRUProvider() = default;
private:
    std::list<K> access_order;
};