#include <fstream>
#include <algorithm>

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
    std::ifstream file(filename);
    if (!file.is_open()) {
        return 0.0;
    }

    std::string word;
    double cache_hits = 0.0;
    double words_count = 0.0;

    auto is_special_symbol = [](char c) {
        return !std::isalnum(c);
    };

    while (file >> word) {
        word.erase(std::remove_if(word.begin(), word.end(), is_special_symbol), word.end());
        words_count++;
        auto it = this->provider->get_cache();
        if (it.find(word) != it.end()) {
            cache_hits++;
        } else {
            this->provider->put(word, 0);
        }
    }
    
    return cache_hits / words_count;
}

template <typename K, typename V>
void CachingService<K, V>::show_provider_type() {
    std::cout << this->provider->to_string() << std::endl;
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