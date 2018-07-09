/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** pdi
*/

#include "graph.h"


void	pdi_recv_g(UNUSED graph_t *graph, UNUSED char **args)
{
	t_player *player = get_player_by_id(graph->players, atoi(args[1]));

	player->died = true;
	graph->player_died = true;
}
