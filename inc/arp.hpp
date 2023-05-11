#ifndef _ARP_HPP_
#define _ARP_HPP_

#include "ether.hpp"

#define IPALEN 4

class ARP {
public:
    ARP(uint16_t op) :
        eth(std::move(std::make_unique<Ether>(IP_P_TYPE))),
        htype(htons(1)),
        ptype(htons(IP_P_TYPE)),
        hsize(htons(6)),
        psize(htons(4)),
        opcode(htons(op))
        {}

    ~ARP();

    
private:
    Ether::EthHdr eth;

    uint16_t htype;
    uint16_t ptype;
    uint8_t hsize;
    uint8_t psize;
    uint16_t opcode;

    std::array<uint8_t, HWALEN> src_mac_a;
    std::array<uint8_t, IPALEN> src_ip_a;
    
    std::array<uint8_t, HWALEN> dst_mac_a;
    std::array<uint8_t, IPALEN> dst_ip_a;
};


#endif //_ARP_HPP_