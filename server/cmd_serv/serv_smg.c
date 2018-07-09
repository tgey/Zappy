/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** serv_smg
*/

#include "server.h"

int	serv_smg(int cli_fd, UNUSED t_serv *serv, char **tab)
{
	char	str[512];

	sprintf(str, "smg %s\n", tab[1]);
	send(cli_fd, str, strlen(str), 0);
	return (0);
}