/*
** EPITECH PROJECT, 2018
** NWP_myarpspoof_2018
** File description:
** myarpspoof check_args.c file
*/
#include "packet.h"
#include <stdlib.h>
#include <string.h>

void check_args(int ac, char **av)
{
	if (ac != 4)
		error(ERROR_ARGS);
}

void init_core(core_t *core, char **av)
{
	core->new_sender_ip = strdup(av[1]);
	core->target_ip = strdup(av[2]);
	core->interface = strdup(av[3]);
}
