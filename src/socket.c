/*
** EPITECH PROJECT, 2018
** NWP_myarpspoof_2018
** File description:
** myarpspoof socket.c
*/
#include <stdlib.h>
#include <stdio.h>
#include <linux/if_ether.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <string.h>
#include "packet.h"

void init_socket_and_get_my_mac_addr(core_t *core)
{
    if ((core->socket = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP))) == -1)
        error(ERROR_SOCKET);
    get_my_mac_addr(core);
}

void get_my_mac_addr(core_t *core)
{
    struct ifreq ifr;

    core->my_mac_addr = malloc(sizeof(uint8_t) * 6);
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, core->interface, IFNAMSIZ);
    if (ioctl(core->socket, SIOCGIFHWADDR, &ifr) == -1)
        error(ERROR_IOCTLT);
    memcpy(core->my_mac_addr, ifr.ifr_hwaddr.sa_data, sizeof(uint8_t) * 6);
}
