#include "../inc/arp-core.hpp"

#include <arpa/inet.h>

ARP::ARP() {
    arp_hdr.eth.h_type = htons(HW_ARP_TYPE);
}

ARP::ARP(const std::array<uint8_t, 6> &sender_mac, const std::array<uint8_t, 6> &dest_mac, 
        const std::array<uint8_t, 4> &sender_ip, const std::array<uint8_t, 4> &dest_ip) {
    std::copy(std::begin(sender_mac), std::end(sender_mac), std::begin(arp_hdr.src_mac));
}

uint8_t *ARP::raw_bytes() {
    std::memcpy(*this->raw_bytes, arp_hdr, sizeof(arp_hdr));

    return 
}