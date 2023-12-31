#include "../lib/FIFOProvider.h"

template <typename K, typename V>
FIFOProvider<K, V>::FIFOProvider() {
    this->policy = EvictPolicy::FIFO;
}

template <typename K, typename V>
void FIFOProvider<K, V>::put(K key, V value) {
    if (this->cache.size() >= this->max_capacity) {
        evict();
    }
    this->cache[key] = value;
}

template <typename K, typename V>
V FIFOProvider<K, V>::get(K key) {
    auto it = this->cache.find(key);
    if (it != this->cache.end()) {
        return it->second;
    }
    return V();
}

template <typename K, typename V>
void FIFOProvider<K, V>::evict() {
    if (!this->cache.empty()) {
        auto it = this->cache.begin();
        this->cache.erase(it);
    }
}

template <typename K, typename V>
std::string FIFOProvider<K, V>::to_string() {
    return "FIFO";
}

