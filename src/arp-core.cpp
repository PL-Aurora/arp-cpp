#include "../inc/arp-core.hpp"

#include <arpa/inet.h>

ARP::ARP() {
    std::ranges::fill(arp_hdr.eth.dest_mac, 0xff);
    arp_hdr.eth.h_type = htons(HW_ARP_TYPE);
}

ARP::ARP(const std::array<uint8_t, 6> &sender_mac, const std::array<uint8_t, 6> &dest_mac, 
        const std::array<uint8_t, 4> &sender_ip, const std::array<uint8_t, 4> &dest_ip) {

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