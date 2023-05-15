#include "inc/ether.hpp"
#include "inc/arp.hpp"

#include <cstdlib>
#include <vector>
#include <string_view>

#include <arpa/inet.h>

namespace input_args {
    void parse_args(int argc, char *argv[]);
    bool valid_ip(const std::string &ip);

}; //input_args

void input_args::parse_args([[maybe_unused]]int argc, [[maybe_unused]] char *argv[]) {
    if(argc != 2) {
        std::string err_str = "Nie podano adresu IP. Uzycie programu:\n";
        err_str += "<nazwa-programu> <docelowy-adres-IP>, przykl: <<  " + 
                static_cast<std::string>(argv[0]) 
                + " 192.168.0.2  >>\n";
        std::cout << err_str;
        std::exit(EXIT_FAILURE);
    }
        
    const std::vector<std::string> args(argv + 1, argv + argc);
    for(const auto &arg : args) {
        if(input_args::valid_ip(arg)){
            std::cout << "valid IP\n";
            // args.push_back(arg);
        }
    }
};

bool input_args::valid_ip(const std::string &ip) {
    struct sockaddr_in6 sa;
    return inet_pton(AF_INET, ip.c_str(), &(sa.sin6_addr)) != 0;
}

int main([[maybe_unused]]int argc, [[maybe_unused]] char *argv[]) {
    input_args::parse_args(argc, argv);

    init_device();

    std::unique_ptr<ARP> a1 = std::make_unique<ARP>(1);

    std::cout << *a1;

    free(host_device_if_name);
    return 0;
}
