#include <array>
#include <string>
#include <memory>
#include <cstdint>
#include <ranges>
#include <iomanip>

#include <cstring>

#include <arpa/inet.h>

#include "netdevice.h"

class PacketBuilder {
public:
    virtual PacketBuilder &buildEthernetHeader(uint16_t p) = 0;


private:
    std::string type;
};


class Ether {
public:
    using EthHdr = std::unique_ptr<Ether>;

    Ether() : proto(htons(2048)) {
        std::memcpy(eth_mac_src.data(), host_device_mac, 6);
        std::ranges::fill(eth_mac_dst, 0xc6);
    };

    Ether(uint16_t p, uint8_t *src, uint8_t *dst) : proto(htons(p)) {
        std::memcpy(eth_mac_src.data(), src, 6);
        std::memcpy(eth_mac_dst.data(), dst, 6);
    };

    auto &get_mac_src() const { return eth_mac_src; };
    auto &get_mac_dst() const { return eth_mac_dst; };

    // const uint8_t raw_ether_hdr();

    template<std::size_t SIZE>
    std::string dump_data(const std::array<uint8_t, SIZE> &a);

    friend std::ostream &operator<<(std::ostream &os, const Ether &e);

private:
    std::array<uint8_t, 6> eth_mac_src;
    std::array<uint8_t, 6> eth_mac_dst;
    uint16_t proto;
};