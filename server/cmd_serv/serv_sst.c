/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** serv_sst
*/

#include "server.h"

int	serv_sst(int cli_fd, t_serv *serv, char **tab)
{
	char	str[512];

	serv->freq = atoi(tab[1]);
	sprintf(str, "sst %i\n", serv->freq);
	send(cli_fd, str, strlen(str), 0);
	return (0);
}