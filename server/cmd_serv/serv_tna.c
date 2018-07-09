/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** serv_tna
*/

#include "server.h"

int	serv_tna(int cli_fd, t_serv *serv, UNUSED char **tab)
{
	char	str[512];
	t_chained	*current = serv->teams->first;
	while (!current->last)
	{
		sprintf(str, "tna %s\n", ((t_team *)current->data)->name);
		send(cli_fd, str, strlen(str), 0);
		current = current->next;
	}
	return (0);
}