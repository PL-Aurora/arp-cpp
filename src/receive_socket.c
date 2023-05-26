#include "../inc/receive_socket.h"
#include "../inc/netdevice.h"

int create_recv_socket() {
    int sock_raw;
    struct sockaddr_ll sa;

    // Utworzenie gniazda
    sock_raw = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock_raw < 0) {
        fprintf(stderr, "Blad przy tworzeniu gniazda!\n");
        return -1;
    }

/* 
    za pomocą zdefiniowanej na etapie uruchamiania programu zmiennej
    host_device_ifindex przechowujacej index interfejsu mozemy zbindowac
    utworzone wczesniej gniazdo do sockaddr_ll
 */
    sa.sll_family = AF_PACKET;
    sa.sll_protocol = htons(ETH_P_ALL);
    sa.sll_ifindex = host_device_ifindex;
    if (bind(sock_raw, (struct sockaddr *)&sa, sizeof(sa)) == -1) {
        fprintf(stderr, "Wystapil blad przy bindowaniu gniazda");
        return -1;
    }

    return sock_raw;
}