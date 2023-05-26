/* klasa odpowiedzalna za interpretowanie przychodzacych ramek na interfejs sieciowy
oraz przekazywanie danych w zaleznosci od wplywajacych pakietow */
#ifndef _PACKET_HPP_
#define _PACKET_HPP_

#include <map>
#include <utility>  //dla std::pair
#include <string>
#include <algorithm>

class Packet {
public:
    void extract_ethertype(uint8_t *bytes);
private:
    std::map<int, std::string> ether_types = {
        {0x0800, "IPv4"}, {0x0806, "ARP"}, {0x86DD, "IPv6"}
    };
};

#endif //_PACKET_HPP_