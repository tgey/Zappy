/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** serv_pex
*/

#include "server.h"

int	serv_pex(int cli_fd, UNUSED t_serv *serv, char **tab)
{
	char	str[512];

	sprintf(str, "pex %s\n", tab[1]);
	send(cli_fd, str, strlen(str), 0);
	return (0);
}