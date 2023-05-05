#ifndef _ARP_CORE_H_
#define _ARP_CORE_H_

#include <iostream>
#include <cstdint>
#include <cstring>
#include <array>

#include <memory>
#include <algorithm>
#include <ranges>
#include <string>

#define HWALEN 6
#define IPALEN 4

#define HW_ARP_TYPE 0x0806

struct _eth_hdr {
    std::array<uint8_t, HWALEN> dest_mac;
    std::array<uint8_t, HWALEN> src_mac;
    uint16_t h_type;
};

struct _arp_hdr {
        struct _eth_hdr eth;

        uint16_t htype;
        uint16_t ptype;

        uint8_t hsize;
        uint8_t psize;

        uint16_t opcode;

        std::array<uint8_t, HWALEN> src_mac;
        std::array<uint8_t, IPALEN> src_ip;
        
        std::array<uint8_t, HWALEN> dst_mac;
        std::array<uint8_t, IPALEN> dst_ip;
};

class ARP {
public:
    using arp_pkt = std::unique_ptr<ARP>;

    ARP();
    ARP(const std::array<uint8_t, 6> &sender_mac, const std::array<uint8_t, 6> &dest_mac, 
        const std::array<uint8_t, 4> &sender_ip, const std::array<uint8_t, 4> &dest_ip);

    ~ARP();

    auto &source_mac() { return arp_hdr.src_mac; }

    // const std::array<uint8_t, 6> &test_source_mac() const { return test_mac_arr; }

    // std::array<uint8_t, sizeof(struct _arp_hdr)> arp_bytes { return }

    uint8_t *ret_raw_bytes();

    friend std::ostream& operator<<(std::ostream &os, const ARP &arp);

private:
    struct _arp_hdr arp_hdr;
    std::array<uint8_t, 42> raw_arp; 

    std::array<uint8_t, 6> test_mac_arr;
};

template<std::size_t SIZE> 
std::string dump_packet_members(std::array<uint8_t, SIZE> &arr);

#endif //_ARP_CORE_H_