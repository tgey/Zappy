/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** pnw
*/

#include "graph.h"

void pnw_recv_g(graph_t *graph, char **args)
{
	t_player	*new_player;

	new_player = empty_player();
	new_player->id = atoi(&args[1][args[1][0] == '#' ? 1 : 0]);
	new_player->x = atoi(args[2]);
	new_player->y = atoi(args[3]);
	new_player->dir = atoi(args[4]);
	new_player->lvl = atoi(args[5]);
	new_player->team = malloc(sizeof(t_team));
	new_player->team->name = strdup(args[6]);
	new_player->new_one = true;
	new_player->died = false;
	graph->new_player = true;
	insert_chained_list(graph->players, new_player);
}