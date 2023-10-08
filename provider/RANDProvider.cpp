#include <random>
#include <ctime>
#include "../lib/RANDProvider.h"

template <typename K, typename V>
RANDProvider<K, V>::RANDProvider() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    this->policy = EvictPolicy::RAND;
}

template <typename K, typename V>
void RANDProvider<K, V>::put(K key, V value) {
    if (this->cache.size() >= this->max_capacity) {
        evict();
    }
    this->cache[key] = value;
}

template <typename K, typename V>
V RANDProvider<K, V>::get(K key) {
    auto it = this->cache.find(key);
    if (it != this->cache.end()) {
        return it->second;
    }
    return V();
}

template <typename K, typename V>
void RANDProvider<K, V>::evict() {
    if (!this->cache.empty()) {
        auto it = this->cache.begin();
        std::advance(it, std::rand() % this->cache.size());
        this->cache.erase(it);
    }
}

template <typename K, typename V>
std::string RANDProvider<K, V>::to_string() {
    return "RAND";
}

