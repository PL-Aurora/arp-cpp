#include <iostream>

#include "inc/arp-core.hpp"
#include "inc/netdevice.h"

int main(int argc, char *argv[]) {
    init_device();

    for(auto x : host_device_ip)
        std::cout << unsigned(x) << std::endl;

    return 0;
}
