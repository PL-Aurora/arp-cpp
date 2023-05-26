#include "inc/ether.hpp"
#include "inc/arp.hpp"
#include "inc/receive_socket.h"
#include "inc/packet.hpp"

#include <cstdlib>
#include <vector>
#include <string_view>

#include <arpa/inet.h>

static std::array<uint8_t, IPALEN> ip_dst;

namespace input_args {
    void parse_args(int argc, char *argv[]);
    bool valid_ip(char *ip);

}; //input_args

void input_args::parse_args(int argc, char *argv[]) {
    if(argc != 2) {
        std::string err_str = "Nie podano adresu IP. Uzycie programu:\n";
        err_str += "<nazwa-programu> <docelowy-adres-IP>, przykl: <<  " + 
                static_cast<std::string>(argv[0]) 
                + " 192.168.0.2  >>\n";
        std::cout << err_str;
        std::exit(EXIT_FAILURE);
    }

    if(!input_args::valid_ip(argv[1])) {
        std::cerr << "Invalid IP address, exiting..." << std::endl;
        std::exit(EXIT_FAILURE);
    }
};
bool input_args::valid_ip(char *ip) {
    int cnt = 0;
    struct in_addr addr;
    if(inet_aton(ip, &addr) == 0) return false;

    for(auto it = ip_dst.begin(); it != ip_dst.end(); ++it, ++cnt)
        *it = static_cast<uint8_t>((addr.s_addr >> (8 * cnt)) & 0xff);

    return true;
}

int main(int argc, char *argv[]) {
    std::array<uint8_t, MAX_PACKET_SIZE> buff;
    Packet p; 
    input_args::parse_args(argc, argv);

    init_device();
    int sock = create_recv_socket();

    while(1) {
        int packet_size = recvfrom(sock, buff.data(), MAX_PACKET_SIZE, 0, NULL, NULL);
        if (packet_size < 0) {
            perror("Failed to receive packets");
            return 1;
        }
        p.extract_ethertype(buff.data());
        
    }

    std::unique_ptr<ARP> a1 = std::make_unique<ARP>(1);

    std::cout << *a1;

    free(host_device_if_name);
    close(sock);
    return 0;
}
