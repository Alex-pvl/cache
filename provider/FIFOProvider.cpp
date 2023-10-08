#include "lib/FIFOProvider.h"

template <typename K, typename V>
FIFOProvider<K, V>::FIFOProvider() {
    this->policy = EvictPolicy::FIFO;
}

template <typename K, typename V>
std::string FIFOProvider<K, V>::toString() {
    return "FIFO";
}

template <typename K, typename V>
FIFOProvider<K, V>::~FIFOProvider() {}
