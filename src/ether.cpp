#include "../inc/ether.hpp"

// #include <sstream>

template<std::size_t SIZE>
std::string dump_data(const std::array<uint8_t, SIZE> &a) {
    std::string res;
    std::stringstream ss;

    for(auto i : a)
        ss << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(i) << ":";

    res = ss.str();
    res.pop_back();
    return res;
}
    
std::ostream &operator<<(std::ostream &os, const Ether &e) {
    os << "Source MAC: " << dump_data(e.get_mac_src()) << ", Dest MAC: " << dump_data(e.get_mac_dst()) << std::endl;
    return os;
}