#include <iostream>
#include "CachingService.cpp"

using namespace std;

int main() {
    auto *service = new CachingService<string, int>();
    service->set_evict_policy(EvictPolicy::RAND);
    service->set_max_capacity(64);
    return 0;
}