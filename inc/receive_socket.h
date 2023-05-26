#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include <sys/socket.h>
#include <netpacket/packet.h>
#include <net/if.h>
#include <netdb.h>
#include <arpa/inet.h>

#define NI_NUMERICHOST 1
#define ETH_P_ALL 0x0003

#define MAX_PACKET_SIZE 4096

int create_recv_socket();

/* void init_device();
void transform_ip(uint8_t *ip, uint32_t ip_decimal); */

#ifdef __cplusplus
}
#endif