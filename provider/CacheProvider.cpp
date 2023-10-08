#include "lib/CacheProvider.h"
#include "lib/FIFOProvider.h"

template <typename K, typename V>
CacheProvider<K, V>* CacheProvider<K, V>::set_policy(EvictPolicy policy) {
    switch (policy) {
        case EvictPolicy::FIFO:
            return new FIFOProvider<K, V>();
        default:
            return nullptr;
    }
}