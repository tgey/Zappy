/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** pgt
*/

#include "graph.h"

void	pgt_recv_g_s(graph_t *graph, t_player *player, int type)
{
	switch (type) {
	case 6:
		player->stones->thystame += 1;
		fill_place(graph, graph->map->map[player->y][player->x]
			->stones->thystame, chained_list_len(graph->map
			->map[player->y][player->x]->stones->thystame) - 1);
		break;
	default:
		break;
	}
}

void	pgt_recv_g_ff(graph_t *graph, t_player *player, int type)
{
	switch (type) {
	case 4:
		player->stones->mendiane += 1;
		fill_place(graph, graph->map->map[player->y][player->x]
			->stones->mendiane, chained_list_len(graph->map
			->map[player->y][player->x]->stones->mendiane) - 1);
		break;
	case 5:
		player->stones->phiras += 1;
		fill_place(graph, graph->map->map[player->y][player->x]
			->stones->phiras, chained_list_len(graph->map
			->map[player->y][player->x]->stones->phiras) - 1);
		break;
	default:
		pgt_recv_g_s(graph, player, type);
		break;
	}
}

void	pgt_recv_g_tt(graph_t *graph, t_player *player, int type)
{
	switch (type) {
	case 2:
		player->stones->deraumere += 1;
		fill_place(graph, graph->map->map[player->y][player->x]
			->stones->deraumere, chained_list_len(graph->map
			->map[player->y][player->x]->stones->deraumere) - 1);
		break;
	case 3:
		player->stones->sibur += 1;
		fill_place(graph, graph->map->map[player->y][player->x]
			->stones->sibur, chained_list_len(graph->map
			->map[player->y][player->x]->stones->sibur) - 1);
		break;
	default:
		pgt_recv_g_ff(graph, player, type);
		break;
	}
}

void	pgt_recv_g(graph_t *graph, char **args)
{
	t_player *player = get_player_by_id(graph->players, atoi(args[1]));

	switch (atoi(args[2])) {
	case 0:
		player->food += 1;
		fill_place(graph, graph->map->map[player->y][player->x]->food,
			chained_list_len(graph->map->map[player->y][player->x]
			->food) - 1);
		break;
	case 1:
		player->stones->linemate += 1;
		fill_place(graph, graph->map->map[player->y][player->x]
			->stones->linemate, chained_list_len(graph->map
			->map[player->y][player->x]->stones->linemate) - 1);
		break;
	default:
		pgt_recv_g_tt(graph, player, atoi(args[2]));
		break;
	}
}