#include <iostream>
#include "provider/CacheProvider.cpp"
#include "provider/FIFOProvider.cpp"

using namespace std;

int main() {

    CacheProvider<int, int> *p = CacheProvider<int, int>::set_policy(EvictPolicy::FIFO);

    cout << p->toString();

    return 0;
}