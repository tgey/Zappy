/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** serv_enw
*/

#include "server.h"

int	serv_enw(int cli_fd, UNUSED t_serv *serv, UNUSED char **tab)
{
	char	str[512];

	sprintf(str, "enw e n X Y\n");
	send(cli_fd, str, strlen(str), 0);
	return (0);
}