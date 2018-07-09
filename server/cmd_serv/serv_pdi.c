/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** serv_pdi
*/

#include "server.h"

int	serv_pdi(int cli_fd, UNUSED t_serv *serv, char **tab)
{
	char	str[512];

	sprintf(str, "pdi %s\n", tab[1]);
	send(cli_fd, str, strlen(str), 0);
	return (0);
}