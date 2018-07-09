/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** serv_msz
*/

#include "server.h"

int	serv_msz(int cli_fd, t_serv *serv, UNUSED char **tab)
{
	char	str[512];

	int	x = serv->map->width;
	int	y = serv->map->height;

	sprintf(str, "msz %i %i\n", x, y);
	send(cli_fd, str, strlen(str), 0);
	return (0);
}