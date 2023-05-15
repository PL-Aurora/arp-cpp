#include "inc/ether.hpp"
#include "inc/arp.hpp"

#include <vector>
#include <string_view>

namespace input_args {
    void parse_args(int argc, char *argv[]);

}; //input_args

void input_args::parse_args(int argc, char *argv[]) {
    const std::vector<std::string_view> args(argv + 1, argv + argc);
};

int main([[maybe_unused]]int argc, [[maybe_unused]] char *argv[]) {
    input_args::parse_args(argc, argv);

    init_device();

    std::unique_ptr<ARP> a1 = std::make_unique<ARP>(1);

    std::cout << *a1;

    free(host_device_if_name);
    return 0;
}
