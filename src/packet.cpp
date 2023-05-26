#include "../inc/packet.hpp"
#include <iostream>

/* 
    funkcja okreslajaca czy wplywajaca ramka zawiera obslugiwane typy pakietow
    wykorzystuje fakt ze 12 i 13 bajt ramki ethernet okreslaja typ pakietu    
 */

void Packet::extract_ethertype(uint8_t *bytes) {
    uint16_t incoming_eth_type = ((bytes[12] << 8) | bytes[13]) & 0xffff;

    auto element = std::find_if(this->ether_types.begin(), this->ether_types.end(), 
        [incoming_eth_type](const std::pair<int, std::string> &p) {
            return p.first == incoming_eth_type;
        });
        std::cout << element->second << std::endl;
}