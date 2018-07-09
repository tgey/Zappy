/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** serv_sgt
*/

#include "server.h"

int	serv_sgt(int cli_fd, t_serv *serv, UNUSED char **tab)
{
	char	str[512];

	sprintf(str, "sgt %i\n", serv->freq);
	send(cli_fd, str, strlen(str), 0);
	return (0);
}