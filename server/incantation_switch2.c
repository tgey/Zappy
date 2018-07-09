/*
** EPITECH PROJECT, 2018
** incantation switch case 2
** File description:
** zappy
*/

#include "server.h"

char	*my_asprintf_xy(t_chained *list)
{
	char	*res;

	asprintf(&res, "pic %i %i %i %i", ((t_player *)list->data)->x,
		((t_player *)list->data)->y,
		((t_player *)list->data)->lvl,
		((t_player *)list->data)->id);
	return (res);
}

char	*my_asprintf_id(t_chained *list, char *tmp)
{
	char	*msg;

	asprintf(&msg, "%i\n", ((t_player *)list->data)->id);
	tmp = my_strcat2(tmp, " ");
	tmp = my_strcat2(tmp, msg);
	free(msg);
	return (tmp);
}

int	send_all_cell(t_serv *serv, t_player *players, char *msg)
{
	t_chained	*list = serv->map->map[players->y][players->x]->
			players->first;
	char		*res;

	res = my_asprintf_xy(list);
	while (!list->last) {
		my_send(((t_player *)list->data)->fd, msg);
		list = list->next;
		if (!list->last)
			res = my_asprintf_id(list, res);
	}
	res = my_strcat2(res, "\n");
	if (serv->graph_fd != -1)
		send(serv->graph_fd, res, strlen(res), 0);
	free(res);
	return (0);
}

int	req_case_6(t_player *players, t_serv *serv, int cli_fd, int *req)
{
	req[0] = 1;
	req[1] = 2;
	req[2] = 3;
	req[3] = 0;
	req[4] = 1;
	req[5] = 0;
	if (check_level_stone(players, serv, req, 6) == 1)
		return (my_send_err(cli_fd, "ko\n"));
	return (send_all_cell(serv, players, "Elevation underway\n"));
}

int	req_case_7(t_player *players, t_serv *serv, int cli_fd, int *req)
{
	req[0] = 2;
	req[1] = 2;
	req[2] = 2;
	req[3] = 2;
	req[4] = 2;
	req[5] = 1;
	if (check_level_stone(players, serv, req, 6) == 1)
		return (my_send_err(cli_fd, "ko\n"));
	return (send_all_cell(serv, players, "Elevation underway\n"));
}