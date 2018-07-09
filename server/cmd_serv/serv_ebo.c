/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** serv_ebo
*/

#include "server.h"

int	serv_ebo(int cli_fd, UNUSED t_serv *serv, char **tab)
{
	char	str[512];

	sprintf(str, "ebo %s\n", tab[1]);
	send(cli_fd, str, strlen(str), 0);
	return (0);
}