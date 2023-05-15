#ifndef _ETHER_HPP_
#define _ETHER_HPP_

#include "core.hpp"

#define HWALEN 6

#define ARP_P_TYPE 0x0806
#define IP_P_TYPE 0x0800

class PacketBuilder {
public:
    virtual PacketBuilder &buildEthernetHeader(uint16_t p) = 0;


private:
    std::string type;
};


class Ether {
public:
    using EthHdr = std::unique_ptr<Ether>;

    Ether(uint16_t p) : proto(htons(p)) {
        std::memcpy(eth_mac_src.data(), host_device_mac, HWALEN);
        std::ranges::fill(eth_mac_dst, 0xc6);
    };

    Ether(uint16_t p, uint8_t *src, uint8_t *dst) : proto(htons(p)) {
        std::memcpy(eth_mac_src.data(), src, HWALEN);
        std::memcpy(eth_mac_dst.data(), dst, HWALEN);
    };

    auto &get_mac_src() const { return eth_mac_src; };
    auto &get_mac_dst() const { return eth_mac_dst; };

    void set_mac(std::array<uint8_t, HWALEN> &mac, void *src) { std::memcpy(mac.data(), src, HWALEN); };


    template<std::size_t SIZE>
    std::string dump_data(const std::array<uint8_t, SIZE> &a);

    friend std::ostream &operator<<(std::ostream &os, const Ether &e);
    ~Ether() {};

private:
    std::array<uint8_t, HWALEN> eth_mac_src;
    std::array<uint8_t, HWALEN> eth_mac_dst;
    uint16_t proto;
};

#endif // _ETHER_HPP_