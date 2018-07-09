/*
** EPITECH PROJECT, 2018
** incantation function
** File description:
** zappy project
*/

#include "server.h"

int	my_send(int fd, char *s)
{
	send(fd, s, strlen(s), 0);
	return (0);
}

int	my_send_err(int fd, char *s)
{
	send(fd, s, strlen(s), 0);
	return (84);
}

int	up_all_player_on_cell(t_player *pl, t_serv *srv)
{
	int		i = 0;
	t_chained	*list = srv->map->map[pl->y][pl->x]->players->first;

	while (!list->last) {
		((t_player *)list->data)->lvl++;
		list = list->next;
		i++;
	}
	return (i);
}

int	check_level_stone_end(t_player *players, t_serv *srv,
					int *req, int nb)
{
	if (
	srv->map->map[players->y][players->x]->stones->linemate != req[0] ||
	srv->map->map[players->y][players->x]->stones->deraumere != req[1] ||
	srv->map->map[players->y][players->x]->stones->sibur != req[2] ||
	srv->map->map[players->y][players->x]->stones->mendiane != req[3] ||
	srv->map->map[players->y][players->x]->stones->phiras != req[4] ||
	srv->map->map[players->y][players->x]->stones->thystame != req[5]) {
		free(req);
		return (1);
	}
	if (check_players_on_cell(players, srv) < nb) {
		free(req);
		return (1);
	}
	free(req);
	up_all_player_on_cell(players, srv);
	return (0);
}

void	p_free(char **ptr)
{
	if (*ptr != NULL)
		free(*ptr);
}