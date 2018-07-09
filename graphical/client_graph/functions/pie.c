/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** pie
*/

#include "graph.h"

void	pie_recv_g(graph_t *graph, char **args)
{
	cell_t *cell = graph->map->map[atoi(args[2])][atoi(args[1])];
	t_chained *current = ((t_chained_list *)cell->players)->first;
	t_player *player = NULL;

	while (current && !current->last) {
		player = ((t_player *)current->data);
		player->changed = true;
		player->anim = 0;
		player->incantation = 0;
		if (atoi(args[3]) == 0)
			player->lvl++;
		current = current->next;
	}
}
