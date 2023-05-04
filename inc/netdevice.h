#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <stdint.h>
#include <sys/socket.h>
#include <netpacket/packet.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <arpa/inet.h>

#define NI_NUMERICHOST 1

extern uint8_t host_device_mac[6];
extern uint8_t host_device_ip[4];
extern char *host_device_if_name;

void init_device();
void transform_ip(uint8_t *ip, uint32_t ip_decimal);

#ifdef __cplusplus
}
#endif