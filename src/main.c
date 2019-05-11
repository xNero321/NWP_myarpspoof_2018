/*
** EPITECH PROJECT, 2018
** NWP_myarpspoof_2018
** File description:
** myarpspoof main.c
*/
#include <stdlib.h>
#include <stdio.h>
#include "packet.h"

int main(int ac, char **av)
{
	core_t *core = malloc(sizeof(core_t));

	check_args(ac, av);
	init_core(core, av);
	
	printf("%s, %s, %s\n", core->new_sender_ip, core->target_ip, core->interface);
	return (EXIT_SUCCESS);
}
