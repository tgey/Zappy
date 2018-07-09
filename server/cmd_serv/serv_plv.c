/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** serv_plv
*/

#include "server.h"

int	serv_plv(int cli_fd, UNUSED t_serv *serv, UNUSED char **tab)
{
	char		str[512];
	t_player	*player = get_player_by_fd(serv->players, atoi(tab[1]));
	int		lvl = player->lvl;

	sprintf(str, "plv %i %i\n", player->fd, lvl);
	send(cli_fd, str, strlen(str), 0);
	return (0);
}