#include "lib/CachingService.h"
#include "provider/FIFOProvider.cpp"
#include "provider/LRUProvider.cpp"
#include "provider/RANDProvider.cpp"

template <typename K, typename V>
CachingService<K, V>::CachingService() {
    // default
    this->provider = new FIFOProvider<K, V>();
}

template <typename K, typename V>
void CachingService<K, V>::set_max_capacity(int max_capacity) {
    this->provider->set_max_capacity(max_capacity);
}

template <typename K, typename V>
void CachingService<K, V>::put(K key, V value) {
    this->provider->put(key, value);
}

template <typename K, typename V>
double CachingService<K, V>::run_dp_task(const std::string& filename) {
    // TODO
    return 0.0;
}

template <typename K, typename V>
void CachingService<K, V>::set_evict_policy(EvictPolicy policy) {
    switch (policy) {
        case EvictPolicy::FIFO:
            this->provider = new FIFOProvider<K, V>();
            break;
        case EvictPolicy::LRU:
            this->provider = new LRUProvider<K, V>();
            break;
        case EvictPolicy::RAND:
            this->provider = new RANDProvider<K, V>();
            break;
    }
}