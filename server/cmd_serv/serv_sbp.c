/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** serv_sbp
*/

#include "server.h"

int	serv_sbp(int cli_fd, UNUSED t_serv *serv, UNUSED char **tab)
{
	send(cli_fd, "sbp\n", 4, 0);
	return (0);
}