#include <iostream>
#include "CachingService.cpp"

using namespace std;

int main() {
    auto *service = new CachingService<string, int>();
    service->set_max_capacity(16);
    service->show_provider_type();
    cout << service->run_dp_task("test_file.txt");
    return 0;
}