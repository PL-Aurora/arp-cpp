#include "../inc/netdevice.h"

char *host_device_if_name = NULL;
uint8_t host_device_ip[4] = {0};
uint8_t host_device_mac[6] = {0};

void init_device() {
    struct ifaddrs *ifaddr = NULL, *ifa = NULL;
    char tmp_ip[14];
    struct sockaddr_in an;

    if(getifaddrs(&ifaddr) == -1) {
        exit(EXIT_FAILURE);
    } else {
        for ( ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next ) {
            //sa_family = AF_PACKET umozliwia dostep adresu MAC
            if ( (ifa->ifa_addr) && (ifa->ifa_addr->sa_family == AF_PACKET) ) 
            {
                // jesli nazwa zaczyna sie na 'e' -> to mamy do czynienia z interfejsem ethernetowym
                // jesli zaczyna sie na 'w' -> wtedy z wireless
                if (ifa->ifa_name[0] == 'e' || ifa->ifa_name[0] == 'w') {
                    struct sockaddr_ll *s = (struct sockaddr_ll*)ifa->ifa_addr;
                    
                    host_device_if_name = (char *) malloc(strlen(ifa->ifa_name) + 1);
                    strcpy(host_device_if_name, ifa->ifa_name);

                    for (int i = 0; i < s->sll_halen; i++) {
                        host_device_mac[i] = s->sll_addr[i];
                    }
                }
            }
            //sprawdzenie czy dany interfejs posiada rowniez adres IP
            if ( (ifa->ifa_addr) && (ifa->ifa_addr->sa_family == AF_INET) ) { 
                if (ifa->ifa_name[0] == 'e' || ifa->ifa_name[0] == 'w') {
                    if(strcmp(host_device_if_name, ifa->ifa_name) == 0) {
                        getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), tmp_ip, sizeof(tmp_ip), 
                                    NULL, 0, NI_NUMERICHOST);
                        inet_aton(tmp_ip, &an.sin_addr);
                        transform_ip(host_device_ip, an.sin_addr.s_addr);
                    }
                }
            }
        }
    }
    free(ifaddr);
}

void transform_ip(uint8_t *ip, uint32_t ip_decimal) {
    ip[0] = ip_decimal & 0xff;
    ip[1] = (ip_decimal >> 8) & 0xff;
    ip[2] = (ip_decimal >> 16) & 0xff;
    ip[3] = (ip_decimal >> 24) & 0xff;
}