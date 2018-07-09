/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** serv_ppo
*/

#include "server.h"

int	serv_ppo(int cli_fd, UNUSED t_serv *serv, UNUSED char **tab)
{
	char		str[512];
	t_player	*player = get_player_by_fd(serv->players, atoi(tab[1]));
	int		x = player->x;
	int		y = player->y;
	int		ori = (int)player->dir;

	sprintf(str, "ppo %i %i %i %i\n", player->fd, x, y, ori);
	send(cli_fd, str, strlen(str), 0);
	return (0);
}