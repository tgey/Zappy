/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** serv_pdr
*/

#include "server.h"

int	serv_pdr(int cli_fd, UNUSED t_serv *serv, UNUSED char **tab)
{
	char	str[512];

	sprintf(str, "pdr n i\n");
	send(cli_fd, str, strlen(str), 0);
	return (0);
}