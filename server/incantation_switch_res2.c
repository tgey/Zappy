/*
** EPITECH PROJECT, 2018
** incantation switch case res2
** File description:
** zappy
*/

#include "server.h"

int	send_all_cell2(t_serv *serv, t_player *players, char *msg)
{
	t_chained	*list = serv->map->map[players->y][players->x]->
			players->first;
	char		*res;

	asprintf(&res, "pie %i %i 0\n", ((t_player *)list->data)->x,
		((t_player *)list->data)->y);
	while (!list->last) {
		my_send(((t_player *)list->data)->fd, msg);
		list = list->next;
	}
	if (serv->graph_fd != -1)
		send(serv->graph_fd, res, strlen(res), 0);
	free(res);
	return (0);
}

int	req_case_6_res(t_player *players, t_serv *serv, int cli_fd, int *req)
{
	__attribute__ (( cleanup(p_free) )) char	*msg;

	asprintf(&msg, "Current level: %i\n", players->lvl + 1);
	req[0] = 1;
	req[1] = 2;
	req[2] = 3;
	req[3] = 0;
	req[4] = 1;
	req[5] = 0;
	if (check_level_stone_end(players, serv, req, 6) == 1)
		return (my_send_err(cli_fd, "ko\n"));
	return (send_all_cell2(serv, players, msg));
}

int	req_case_7_res(t_player *players, t_serv *serv, int cli_fd, int *req)
{
	__attribute__ (( cleanup(p_free) )) char	*msg;

	asprintf(&msg, "Current level: %i\n", players->lvl + 1);
	req[0] = 2;
	req[1] = 2;
	req[2] = 2;
	req[3] = 2;
	req[4] = 2;
	req[5] = 1;
	if (check_level_stone_end(players, serv, req, 6) == 1)
		return (my_send_err(cli_fd, "ko\n"));
	serv->running = false;
	return (send_all_cell(serv, players, msg));
}