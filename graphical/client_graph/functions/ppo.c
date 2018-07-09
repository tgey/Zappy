/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** ppo
*/

#include "graph.h"

void	ppo_send_g(graph_t *graph, char **args)
{
	char	str[512];

	if (tab_len(args) > 1) {
		sprintf(str, "ppo %s\n", args[1]);
		send(graph->serv_fd, str, strlen(str), 0);
	} else
		printf("ppo: missing arguments\n");
}

void	ppo_recv_g(UNUSED graph_t *graph, char **args)
{
	t_player *player = get_player_by_id(graph->players, atoi(args[1]));
	int x = atoi(args[2]);
	int y = atoi(args[3]);
	int dir = atoi(args[4]);

	if (dir != (int)player->dir) {
		player->changed = true;
		if (dir - 1 == (int)player->dir % 4)
			player->anim = 2;
		if (dir - 1 == (4 + (int)player->dir - 2) % 4)
			player->anim = 1;
	}
	if (x != player->x || y != player->y) {
		player->changed = true;
		player->anim = 3;
	}
	delete_player_fd(graph->map->map[player->y][player->x]->players,
		&player->fd);
	player->x = atoi(args[2]);
	player->y = atoi(args[3]);
	player->dir = atoi(args[4]);
	insert_chained_list(graph->map->map[player->y][player->x]->players,
		player);
}