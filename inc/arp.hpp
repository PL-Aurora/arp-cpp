#ifndef _ARP_HPP_
#define _ARP_HPP_

#include "ether.hpp"
#include "core.hpp"

#define IPALEN 4

class ARP {
public:
    ARP(uint16_t op) :
        eth(std::move(std::make_unique<Ether>(IP_P_TYPE))), 
        htype(htons(1)),
        ptype(htons(IP_P_TYPE)),
        hsize(htons(HWALEN)),
        psize(htons(IPALEN)),
        opcode(htons(op)),       //op = 2 - response, 1 - request
        src_mac_a(this->eth->get_mac_src()),
        dst_mac_a(this->eth->get_mac_dst())
        {}

    // ARP(uint16_t op, )

    ~ARP() {};

    auto &get_mac_arp_src() const { return src_mac_a; };
    auto &get_mac_arp_dst() const { return dst_mac_a; };


    template<std::size_t SIZE>
    std::string dump_data_arp(const std::array<uint8_t, SIZE> &a);

    friend std::ostream &operator<<(std::ostream &os, const ARP &e);
    
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