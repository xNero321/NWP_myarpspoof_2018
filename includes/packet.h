/*
** EPITECH PROJECT, 2018
** NWP
** File description:
** NWP_arpspoofing_2018 packet.h
*/

#ifndef PACKET_H_
    #define PACKET_H_
    #include <stdint.h>
    #include <sys/socket.h>
    #include <linux/if_packet.h>
    #include <net/ethernet.h>
// *********************** CONSTANT ************************
    #define ERROR_EXIT 84
    #define BROADCAST(uint8_t[6]){0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}
// ******************** ERROR MESSAGES ******************
    #define ERROR_ARGS "Error: There must be at least 4 arguments.\n"
    #define ERROR_SOCKET "Error: Socket canno't be created.\n"
    #define ERROR_IOCTLT "Error: IOCTL couldn't resolve the mac address.\n"
// ********************* STRUCTURES ***********************
    typedef struct ethernet_header_s
    {
        uint8_t dest_mac_addr[6];
        uint8_t src_mac_addr[6];
        uint16_t type;
    }ethernet_header_t;

    typedef struct arp_header_s
    {
        uint16_t hardware_type;
        uint16_t protocol_type;
        uint8_t hardware_len;
        uint8_t protocol_len;
        uint16_t opcode;
        uint8_t sender_mac_addr[6];
        uint8_t sender_ip_addr[4];
        uint8_t target_mac_addr[6];
        uint8_t target_ip_addr[4];
    }arp_header_t;

    typedef struct core_s
    {
        char *target_ip;
        char *new_sender_ip;
        char *interface;
        uint8_t *my_mac_addr;
        uint8_t *victim_mac_addr;
        struct sockaddr_ll cin;
        int socket;
    }core_t;
// ******************** FUNCTION PROTOTYPES ***************
// ********************** error.c *************************
    void error(char const *error);
// ********************** check_args.c *************************
    void check_args(int ac, char **av);
    void init_core(core_t *core, char **av);
// ********************** socket.c *************************
    void init_socket_and_get_my_mac_addr(core_t *core);
    void get_my_mac_addr(core_t *core);
// ********************** header.c *************************
    arp_header_t *create_arp_header(core_t *core,
        const uint8_t *dest_mac_addr);
    ethernet_header_t *create_ethernet_header(core_t *core,
        const uint8_t *dest_mac_addr, arp_header_t *arp);
// ********************** send_phase.c *************************
    void my_arpspoof(core_t *core, struct sockaddr_ll *sine);
    void send_to_broadcast(core_t *core, struct sockaddr_ll *sine);
    void get_victim_mac_address(core_t *core, struct sockaddr_ll *sine,
        char victim_mac_addr_str[16], char buf[65535]);
    void spoof_victim(struct sockaddr_ll *sine, uint8_t *victim_mac_addr,
        core_t *core);
#endif /* !PACKET_H_ */
