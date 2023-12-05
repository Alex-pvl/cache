#include <iostream>
#include "CachingService.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    int max_capacity = argc == 3 ? atoi(argv[2]) : 128;
    auto *service = new CachingService<string, int>();
    service->set_max_capacity(max_capacity);
    service->show_provider_type();
    cout << "Cache hit rate: " << service->run_dp_task(argv[1]) << "%\n";
    return 0;
}