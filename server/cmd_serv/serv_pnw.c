/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** serv_pnw
*/

#include "server.h"

int	serv_pnw(int cli_fd, t_serv *serv, UNUSED char **tab)
{
	t_player	*player = get_player_by_fd(serv->players, cli_fd);
	char		str[512];

	sprintf(str, "pnw #%i %i %i %i %i %s\n",
		player->id,
		player->x,
		player->y,
		player->dir,
		player->lvl,
		player->team->name);
	send(serv->graph_fd, str, strlen(str), 0);
	return (0);
}