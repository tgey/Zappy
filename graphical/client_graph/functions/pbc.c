/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** pbc
*/

#include "graph.h"

void	pbc_recv_g(graph_t *graph, char **args)
{
	t_player *player = get_player_by_id(graph->players, atoi(args[1]));

	player->broadcast = malloc(sizeof(char) * (strlen(args[2]) + 1));
	player->broadcast = strdup(args[2]);
}