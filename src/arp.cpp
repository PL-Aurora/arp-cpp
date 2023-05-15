#include "../inc/arp.hpp"

template<std::size_t SIZE>
std::string dump_data_arp(const std::array<uint8_t, SIZE> &a) {
    std::string res;
    std::stringstream ss;

    for(auto i : a)
        ss << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(i) << ":";

    res = ss.str();
    res.pop_back();
    return res;
}

std::ostream &operator<<(std::ostream &os, const ARP &a) {
    os << "Source MAC in ARP: " << dump_data_arp(a.get_mac_arp_src()) << ", Dest MAC in ARP: " << dump_data_arp(a.get_mac_arp_dst()) << std::endl;
    return os;
}