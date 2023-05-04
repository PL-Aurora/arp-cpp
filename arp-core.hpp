#ifndef _ARP_CORE_H_
#define _ARP_CORE_H_

#include <cstdint>
#include <cstring>
#include <array>

#include <memory>
#include <algorithm>
#include <ranges>

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

    // std::array<uint8_t, sizeof(struct _arp_hdr)> arp_bytes { return }

    uint8_t *raw_bytes();

    ~ARP();
private:
    struct _arp_hdr arp_hdr;
    std::array<uint8_t, 42> raw_arp; 
};


#endif //_ARP_CORE_H_