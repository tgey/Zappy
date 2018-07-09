/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** incantation
*/

#include "server.h"

int	check_players_on_cell(t_player *pl, t_serv *srv)
{
	int		i = 0;
	t_chained	*list = srv->map->map[pl->y][pl->x]->players->first;
	int		lvl = ((t_player *)list->data)->lvl;

	while (!list->last) {
		if (((t_player *)list->data)->lvl != lvl)
			return (0);
		list = list->next;
		i++;
	}
	return (i);
}

int	check_level_stone(t_player *players, t_serv *srv, int *req, int nb)
{
	if (srv->map->map[players->y][players->x]->stones->linemate != req[0]
	|| srv->map->map[players->y][players->x]->stones->deraumere != req[1]
	|| srv->map->map[players->y][players->x]->stones->sibur != req[2] ||
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
	return (0);
}

int	switch_case_inc(t_player *players, int cli_fd,
				int *req, t_serv *serv)
{
	switch (players->lvl) {
	case (1):
		return (req_case_1(players, serv, cli_fd, req));
	case (2):
		return (req_case_2(players, serv, cli_fd, req));
	case (3):
		return (req_case_3(players, serv, cli_fd, req));
	case (4):
		return (req_case_4(players, serv, cli_fd, req));
	case (5):
		return (req_case_5(players, serv, cli_fd, req));
	case (6):
		return (req_case_6(players, serv, cli_fd, req));
	case (7):
		return (req_case_7(players, serv, cli_fd, req));
	}
	return (my_send_err(cli_fd, "ko\n"));
}

int	serv_incantation(int cli_fd, UNUSED t_serv *serv, UNUSED char **tab)
{
	int		*req = malloc(sizeof(int *) * 6);
	t_player	*players = get_player_by_fd(serv->players, cli_fd);

	if (tab_len(tab) != 1)
		return (my_send_err(cli_fd, "ko\n"));
	return (switch_case_inc(players, cli_fd, req, serv));
}