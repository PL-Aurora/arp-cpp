#include "inc/ether.hpp"
#include "inc/arp.hpp"

#include "inc/netdevice.h"

int main([[maybe_unused]]int argc, [[maybe_unused]] char *argv[]) {
    init_device();

    free(host_device_if_name);
    return 0;
}
