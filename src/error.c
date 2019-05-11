/*
** EPITECH PROJECT, 2018
** NWP_myarpspoof_2018
** File description:
** NWP_myarpspoof_2018 error.c
*/
#include "packet.h"
#include <stdlib.h>
#include <stdio.h>

void error(char const *error)
{
	fprintf(stderr, "%s", error);
	exit(ERROR_EXIT);
}
