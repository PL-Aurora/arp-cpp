#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>
#include <stdlib.h>

#include <stdint.h>
#include <sys/socket.h>
#include <netpacket/packet.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <arpa/inet.h>

#define NI_NUMERICHOST 1

extern int recv_sock;



/* void init_device();
void transform_ip(uint8_t *ip, uint32_t ip_decimal); */

#ifdef __cplusplus
}
#endif