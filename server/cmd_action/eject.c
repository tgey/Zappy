/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** eject
*/

#include "server.h"

t_chained	*get_map_cell(t_chained_list *list)
{
	if (list && !((t_chained *)list)->last)
		return (list->first);
	return (NULL);
}

t_chained	*select_list_players(t_player *player, t_serv *serv)
{
	switch (player->dir) {
		case (4):
			return (get_map_cell(
			((t_chained_list *)serv->map->map[player->y]
			[(player->x - 1) % serv->map->width]->players)));
		case (3):
			return (get_map_cell(
			(t_chained_list *)serv->map->map[(player->y + 1)
			% serv->map->height][player->x]->players));
		case (2):
			return (get_map_cell(
			((t_chained_list *)serv->map->map[player->y]
			[(player->x + 1) % serv->map->width]->players)));
		case (1):
			return (get_map_cell(
			((t_chained_list *)serv->map->map[(player->y - 1)
			% serv->map->height][player->x]->players)));
	}
	return (NULL);
}

void	send_eject(int dir, t_player *current, t_serv *serv)
{
	char message[60];

	sprintf(message, "eject: %i\n", dir);
	send(current->fd, message, strlen(message), 0);
	sprintf(message, "ppo %i %i %i %i\n",
	current->id, current->x,
	current->y, current->dir);
	send(serv->graph_fd, message, strlen(message), 0);
}

void eject_fct(t_player *player, t_player *current, t_serv *serv)
{
	if (current->fd != player->fd)
	{
		switch (player->dir)
		{
		case (1):
			forward_north(current, serv);
			break;
		case (2):
			forward_est(current, serv);
			break;
		case (3):
			forward_south(current, serv);
			break;
		case (4):
			forward_west(current, serv);
			break;
		}
		send_eject(player->dir, current, serv);
	}
}

int serv_eject(int cli_fd, t_serv *serv, UNUSED char **tab)
{
	t_player *player = get_player_by_fd(serv->players, cli_fd);
	t_chained *current = select_list_players(player, serv);
	char message[60];

	if (current->last) {
		send(cli_fd, "ko\n", 3, 0);
		return (0);
	}
	while (!current->last) {
		eject_fct(player, ((t_player *)current->data), serv);
		current = current->next;
	}
	send(cli_fd, "ok\n", 3, 0);
	sprintf(message, "pex %i\n", player->id);
	if (serv->graph_fd != -1)
		send(serv->graph_fd, message, strlen(message), 0);
	return (0);
}