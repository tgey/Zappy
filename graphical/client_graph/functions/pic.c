/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** pic
*/

#include "graph.h"

void	pic_recv_g(graph_t *graph, char **args)
{
	t_player *player = NULL;
	int	x = 0;

	while (x < tab_len(args) - 4)
	{
		player = get_player_by_id(graph->players, atoi(args[x + 4]));
		player->changed = true;
		player->anim = 4;
		player->incantation = 1;
		x++;
	}
}