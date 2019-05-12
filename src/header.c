/*
** EPITECH PROJECT, 2018
** NWP_myarpspoof_2018
** File description:
** NWP_myarpspoof_2018 headers.c
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

arp_header_t *create_arp_header(core_t *core, const uint8_t *dest_mac_addr)
{
    arp_header_t *arp = malloc(sizeof(arp_header_t));

    arp->hardware_type = htons(1);
    arp->protocol_type = htons(ETH_P_IP);
    arp->hardware_len = 6;
    arp->protocol_len = 4;
    arp->opcode = htons(1);
    memcpy(&arp->sender_mac_addr, core->my_mac_addr, sizeof(uint8_t) * 6);
    memcpy(&arp->target_mac_addr, dest_mac_addr, sizeof(uint8_t) * 6);
    inet_pton(AF_INET, core->new_sender_ip, arp->sender_ip_addr);
    inet_pton(AF_INET, core->target_ip, arp->target_ip_addr);
    return (arp);
}

ethernet_header_t *create_ethernet_header(core_t *core,
    const uint8_t *dest_mac_addr, arp_header_t *arp)
{
    ethernet_header_t *eth = malloc(sizeof(uint8_t) * 65535);
    memcpy(&eth->dest_mac_addr, dest_mac_addr, sizeof(uint8_t) * 6);
    memcpy(&eth->src_mac_addr, core->my_mac_addr, sizeof(uint8_t) * 6);
    memcpy(&eth->type, (uint8_t[2]){ETH_P_ARP / 256, ETH_P_ARP % 256},
    sizeof(uint8_t) * 2);
    memcpy((uint8_t *)eth + 14, arp, sizeof(uint8_t) * 28);
    return (eth);

}
