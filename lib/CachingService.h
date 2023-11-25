#include "CacheProvider.h"

template <typename K, typename V>
class CachingService {
public:
    CachingService();
    void put(K, V);
    void set_max_capacity(int);
    void set_evict_policy(EvictPolicy);
    double run_dp_task(const std::string&);
    void show_provider_type();
    ~CachingService() = default;
private:
    CacheProvider<K, V>* provider;
};