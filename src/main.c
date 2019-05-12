/*
** EPITECH PROJECT, 2018
** NWP_myarpspoof_2018
** File description:
** myarpspoof main.c
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "packet.h"

int main(int ac, char **av)
{
    core_t *core = malloc(sizeof(core_t));
    struct sockaddr_ll sine;

    memset(&sine, 0, sizeof(sine));
    check_args(ac, av);
    init_core(core, av);
    init_socket_and_get_my_mac_addr(core);
    my_arpspoof(core, &sine);
    return (EXIT_SUCCESS);
}
