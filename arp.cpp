#include "inc/arp-core.hpp"
#include "inc/netdevice.h"

int main([[maybe_unused]]int argc, [[maybe_unused]] char *argv[]) {
    init_device();

    for(auto x : host_device_mac)
        std::cout << std::hex << unsigned(x) << ":";

    std::cout << "\n";

    auto p1 = std::make_unique<ARP>();

    // std::cout << p1;

    /* for(auto x : p1->source_mac())
        std::cout << unsigned(x) << ":";

    std::cout << "\n"; */

    /* for(auto x : host_device_ip)
        std::cout << unsigned(x) << std::endl; */

    return 0;
}

/* 
    #include <array>
    #include <iostream>

    template<std::size_t SIZE>
    void mulArray(std::array<int, SIZE>& arr) {
        for(auto& e : arr) {
            e *= 14;
        }
    }

    int main()
    {
        std::array<int, 1> arr1 = {1};
        std::array<int, 2> arr2 = {1, 2};
        std::array<int, 3> arr3 = {1, 2, 3};

        mulArray(arr1);
        for (auto x : arr1) { std::cout << x << " "; }
        std::cout << std::endl;

        mulArray(arr2);
        for (auto x : arr2) { std::cout << x << " "; }
        std::cout << std::endl;

        mulArray(arr3);
        for (auto x : arr3) { std::cout << x << " "; }
        std::cout << std::endl;
    }
 */