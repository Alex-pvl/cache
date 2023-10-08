#include "../lib/LRUProvider.h"

template <typename K, typename V>
LRUProvider<K, V>::LRUProvider() {
    this->policy = EvictPolicy::LRU;
}

template <typename K, typename V>
void LRUProvider<K, V>::put(K key, V value) {
    if (this->cache.size() >= this->max_capacity) {
        evict();
    }
    this->cache[key] = value;
    access_order.push_front(key);
}

template <typename K, typename V>
V LRUProvider<K, V>::get(K key) {
    auto it = this->cache.find(key);
    if (it != this->cache.end()) {
        access_order.remove(key);
        access_order.push_front(key);
        return it->second;
    }
    return V();
}

template <typename K, typename V>
void LRUProvider<K, V>::evict() {
    if (!this->access_order.empty()) {
        K oldest_key = access_order.back();
        access_order.pop_back();
        this->cache.erase(oldest_key);
    }
}

template <typename K, typename V>
std::string LRUProvider<K, V>::to_string() {
    return "LRU";
}

