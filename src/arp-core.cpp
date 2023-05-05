#include "../inc/arp-core.hpp"
#include "../inc/netdevice.h"

#include <iomanip>
#include <arpa/inet.h>

ARP::ARP() {
    std::copy(arp_hdr.eth.src_mac.begin(), arp_hdr.eth.src_mac.end(), host_device_mac);

    std::ranges::fill(arp_hdr.eth.dest_mac, 0xff);
    arp_hdr.eth.h_type = htons(HW_ARP_TYPE);
}

ARP::ARP(const std::array<uint8_t, HWALEN> &sender_mac, const std::array<uint8_t, HWALEN> &dest_mac, 
        const std::array<uint8_t, IPALEN> &sender_ip, const std::array<uint8_t, IPALEN> &dest_ip) {

    std::copy(std::begin(sender_mac), std::end(sender_mac), std::begin(arp_hdr.src_mac));
    std::copy(std::begin(dest_mac), std::end(dest_mac), std::begin(arp_hdr.dst_mac));
    std::copy(std::begin(sender_ip), std::end(sender_ip), std::begin(arp_hdr.src_ip));
    std::copy(std::begin(dest_ip), std::end(dest_ip), std::begin(arp_hdr.dst_ip));
    // std::copy(std::begin)
}

uint8_t *ARP::ret_raw_bytes() {
    // if(arp_hdr)
    std::memcpy(&raw_arp, &arp_hdr, sizeof(arp_hdr));

    return raw_arp.data();
}

ARP::~ARP() {
    free(host_device_if_name);
}

template<std::size_t SIZE> 
std::string dump_packet_members(std::array<uint8_t, SIZE> &arr) {
    std::string data;
    for(auto i : arr)
        std::cout << std::setw(2) << std::setfill('0') << std::hex << unsigned(i) << ":";

    return data;
}

/* std::ostream& operator<<(std::ostream &os, ARP &arp) {
    // os << "Source IP: " << dump_packet_members(arp.source_mac());
    
    os << "Source IP: " << dump_packet_members(arp.source_mac());

    return os;
} */